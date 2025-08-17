#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ftw.h>
#include <errno.h>
#include <sys/stat.h>

#include "lexer_adapter.h"
#include "node.h"
#include "parser.h"

static size_t total_files = 0;
static size_t ok_count = 0;
static size_t fail_count = 0;

/* dynamic array of failed paths */
static char **failed_paths = NULL;
static size_t failed_capacity = 0;
static size_t failed_len = 0;

static void add_failed(const char *path) {
    if (failed_len + 1 > failed_capacity) {
        size_t nc = failed_capacity ? failed_capacity * 2 : 64;
        char **n = realloc(failed_paths, nc * sizeof(char*));
        if (!n) return;
        failed_paths = n;
        failed_capacity = nc;
    }
    /* use manual strdup to avoid relying on POSIX strdup */
    size_t l = strlen(path) + 1;
    char *s = malloc(l);
    if (s) memcpy(s, path, l);
    failed_paths[failed_len++] = s;
}

static int has_nix_ext(const char *path) {
    size_t n = strlen(path);
    if (n < 4) return 0;
    return strcmp(path + n - 4, ".nix") == 0;
}

static int process_file(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) return -1;
    if (fseek(f, 0, SEEK_END) != 0) { fclose(f); return -1; }
    long sz = ftell(f);
    if (sz < 0) { fclose(f); return -1; }
    if (fseek(f, 0, SEEK_SET) != 0) { fclose(f); return -1; }
    char *buf = malloc((size_t)sz);
    if (!buf) { fclose(f); return -1; }
    if (fread(buf, 1, (size_t)sz, f) != (size_t)sz) { fclose(f); free(buf); return -1; }
    fclose(f);

    void *scanner = create_scanner(buf, (int)sz, path);
    if (!scanner) { free(buf); return -1; }

    void *ast = NULL;
    int perr = yyparse(&ast, scanner);
    if (perr == 0 && ast != NULL) {
        ok_count++;
    } else {
        fail_count++;
        add_failed(path);
    }

    free_scanner(scanner);
    free(buf);
    total_files++;
    return 0;
}

static int walk_cb(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf) {
    (void)sb; (void)ftwbuf;
    if (typeflag == FTW_F && has_nix_ext(fpath)) {
        process_file(fpath);
    }
    return 0; /* continue */
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <directory>\n", argv[0]);
        return 2;
    }
    const char *dir = argv[1];

    /* nftw with reasonable limits */
    if (nftw(dir, walk_cb, 20, FTW_PHYS) != 0) {
        fprintf(stderr, "nftw failed: %s\n", strerror(errno));
        return 1;
    }

    printf("total .nix files: %zu\n", total_files);
    printf("parsed ok: %zu\n", ok_count);
    printf("parsed failed: %zu\n", fail_count);
    if (fail_count > 0) {
        printf("failed paths:\n");
        for (size_t i = 0; i < failed_len; ++i) {
            printf("%s\n", failed_paths[i]);
            free(failed_paths[i]);
        }
    }
    free(failed_paths);
    return 0;
}
