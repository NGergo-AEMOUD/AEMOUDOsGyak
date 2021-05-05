#include <stdio.h>
#include <stdlib.h>

int main()
{
    
  FILE * fptr;
  int i,n;
  char str[100];
  char fname[20]="AEMOUD.txt";
  char str1;

	fptr = fopen (fname, "r");  
	printf("A fájl tartalma:\n");
	str1 = fgetc(fptr);
	while (str1 != EOF)
		{
			printf ("%c", str1);
			str1 = fgetc(fptr);
		}
    printf("\n\n");
    fclose (fptr);
    return 0;
}
