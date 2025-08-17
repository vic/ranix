# ranix

A Nix language parser implemented in C. Uses Ragel (-G2 Really fast goto-driven FSM) for C. This project is being used as a library for an in-progress Nix compiler implemented in a secret higher-level language.

> [!NOTE]
> ragel machine.rl and bison nix.y code originally based on https://github.com/orivej/go-nix (2018) and updated with fixes for parsing most of nixpkgs as of 16-08-2025 only one file fails
