# kami

Just me getting to use C after a really long time.

## Building

This project uses [Tsoding's nob](https://github.com/tsoding/nob.h) for it's build system.

The reason I am using `nob` for the build system for this project is that, I have been programming a lot in Jai and Odin lately, and I really started to like the idea that the language / simple shell script itself is the build program rather than relying on something like `cmake` or `build.zig`.


```sh
clang nob.c -o nob
./nob
```
