#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen ("Nagy.txt", "w+");
    fputs("Nagy Gergo; ", fp);
    fputs("Programtervező Informatikus; ", fp);
    fputs("AEMOUD; ", fp);
    fclose(fp);
}
