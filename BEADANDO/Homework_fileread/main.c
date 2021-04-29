#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char buff[255];

    fp = fopen("C:\\Users\\nagyg\\Desktop\\Progi\\Homework_7\\AEMOUD.txt", "r");
    fscanf(fp, "%s", buff);
    printf("\nA file tartalma : %s\n", buff );

    fclose(fp);
}
