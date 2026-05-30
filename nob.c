#define NOB_IMPLEMENTATION
#include "nob.h"

int main(int argc, char **argv) {
  NOB_GO_REBUILD_URSELF(argc, argv);
  Nob_Cmd cmd = {0};
  nob_cmd_append(&cmd, "mkdir", "-p", "build");
  if (!nob_cmd_run(&cmd)) return 1;
  cmd.count = 0;
  nob_cmd_append(&cmd, "clang", "main.c", "-I./include", "./lib/libraylib.a", "-lGL", "-lm", "-lpthread", "-ldl", "-lrt", "-lubsan", "-o", "build/main", "-pedantic");
  if (!nob_cmd_run(&cmd)) return 1;
  return 0;
}
