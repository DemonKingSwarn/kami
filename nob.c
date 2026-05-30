#define NOB_IMPLEMENTATION
#include "nob.h"

const char *cflags[] = {"-I./include", "./lib/libraylib.a", "-lGL", "-lm", "-lpthread", "-ldl", "-lrt", "-lubsan", "-pedantic"};

const char *exe = "main";

int main(int argc, char **argv) {
  NOB_GO_REBUILD_URSELF(argc, argv);
  Nob_Cmd cmd = {0};

  nob_cmd_append(&cmd, "mkdir", "-p", "build");

  if (!nob_cmd_run(&cmd)) return 1;
  cmd.count = 0;

  nob_cmd_append(&cmd, "clang", "main.c");
  for (size_t i = 0; i < NOB_ARRAY_LEN(cflags); i++) {
    nob_cmd_append(&cmd, cflags[i]);
  }

  char buf[256];
  snprintf(buf, sizeof(buf), "build/%s", exe);

  nob_cmd_append(&cmd, "-o", buf);

  if (!nob_cmd_run(&cmd)) return 1;
  cmd.count = 0;

  nob_cmd_append(&cmd, "upx", "--best", "--lzma", buf);

  if (!nob_cmd_run(&cmd)) return 1;
  return 0;
}
