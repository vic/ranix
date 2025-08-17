nothing:

ragel:
	ragel -C -G2 -o parser/machine.c parser/machine.rl

bison:
	bison -d -o parser/parser.c parser/parser.y

build: ragel bison
	gcc -std=c11 -O2 -I parser -o bin/lexdemo \
		parser/main.c parser/machine.c parser/parser.c parser/nodetype.c parser/lexer_helper.c parser/lexer_adapter.c
	gcc -std=c11 -O2 -I parser -o bin/walk \
		parser/walk.c parser/machine.c parser/parser.c parser/nodetype.c parser/lexer_helper.c parser/lexer_adapter.c

run: build
	./bin/lexdemo nixpkgs/pkgs/development/haskell-modules/hackage-packages.nix

run-walk: build
	./bin/walk ./nixpkgs/lib

test: build gen-c-ast
	@echo "Done"

test_nix := "nixpkgs/pkgs/development/haskell-modules/hackage-packages.nix"
# test_nix := "nixpkgs/pkgs/top-level/all-packages.nix"
# test_nix := "test.nix"

gen-c-ast: build
	./bin/lexdemo {{test_nix}} > tmp/c.ast
