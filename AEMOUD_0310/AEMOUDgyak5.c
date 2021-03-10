#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>

main(int argc, char *argv[])

{
  FILE *fp;
  int pid, status, died, i;
  time_t now;

  fp = fopen("C:\\Users\\nagyg\\Desktop\\Progi\\AEMOUDgyak5","a+");
  time(&now);
  fprintf(fp,"Started %s%s", ctime(&now), argv[0]);
  for(i=1;i<argc;i++)
    fprintf(fp," %s", argv[i]);
  fprintf(fp,"\n");
  fclose(fp);

  argv[0] = "C:\\Users\\nagyg\\Desktop\\Progi\\child\\main.exe";
  status = spawnv(P_WAIT, "C:\\Users\\nagyg\\Desktop\\Progi\\child\\main.exe", argv);

  fp = fopen("C:\\Users\\nagyg\\Desktop\\Progi\\AEMOUDgyak5","a+");
  time(&now);
  fprintf(fp, "Completed %s\n", ctime(&now));
  fclose(fp);

  return status;
}
