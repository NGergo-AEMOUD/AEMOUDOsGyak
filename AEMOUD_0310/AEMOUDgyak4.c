#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
  char *my_args[5];
  pid_t pid;

  my_args[0] = "child.exe";
  my_args[1] = "arg1";
  my_args[2] = "arg2";
  my_args[3] = NULL;


  switch ((pid = fork()))
  {
    case -1:
      perror ("fork");
      break;
    case 0:
      execv ("child.exe", my_args);
      puts("exec-hiba!");
      exit(EXIT_FAILURE);
      break;
    default:
      puts ("Szulo uzenet.\n");
      break;
  }

  puts ("Szulo program vege.\n");

  return 0;
}

/*
 *

 *
 */
