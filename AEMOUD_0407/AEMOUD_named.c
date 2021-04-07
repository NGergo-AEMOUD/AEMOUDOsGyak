#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int child;
    mkfifo("AEMOUD", S_IRUSR | S_IWUSR);
    child = fork();
    if(child>0){
        char s[1024];
        int fd;
        fd = open("AEMOUD", O_RDONLY);
        read(fd,s,sizeof(s));
        printf("%s", s);

        close(fd);
        unlink("AEMOUD");
    }else if(child == 0){
        int fd;
        fd = open("AEMOUD", O_WRONLY);
        write(fd, "NG_AEMOUD\n",12);
        printf("File létrehozva\n");
        close(fd);
    }
    return 0;




}


}

