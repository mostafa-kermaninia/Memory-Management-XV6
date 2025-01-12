#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  // int i;

  // for(i = 1; i < argc; i++)
  //   printf(1, "%s%s", argv[i], i+1 < argc ? " " : "\n");

  if (fork() == 0){
    printf(1, "pid: %d\n", getpid());
    char *addr = open_sharedmem(1);
    printf(1, "addr: %p\n", (void*)addr);
    addr[0] = 10;
    printf(1, "befarma: %d\n", addr[0]);
    // addr = "hello\0";
    exit();
  }
  wait();
  if (fork() == 0){
    printf(1, "pid: %d\n", getpid());
    char *addr = open_sharedmem(1);
    printf(1, "addr: %p\n", (void*)addr);
    printf(1, "befarma: %d\n", addr[0]);
    if (addr[0] == 10)
      printf(1, "ok\n");
    else
      printf(1, "not ok\n");
      
    exit();
  }
  wait();

  exit();
}
