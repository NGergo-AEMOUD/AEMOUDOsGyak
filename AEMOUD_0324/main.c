#include <stdio.h>
#include <stdlib.h> // For exit() function
int main() {
    #define CHUNK 1024 /* read 1024 bytes at a time */
    char buf[CHUNK];
    FILE *file;
    size_t nread;
    int size;

    file = fopen("AEMOUD.txt", "r+");
    printf("A File tartalma:\n");
    if (file) {
        while ((nread = fread(buf, 1, sizeof buf, file)) > 0){
            fwrite(buf, 1, nread, stdout);
        }
    if (ferror(file)) {
        printf("HIBA!");
        exit(-1);
    }
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    printf("\nA Fileban levo byteok: %d\n", size);
    //fseek( file, 0, SEEK_SET );
    fwrite("\nRandom", 1, 7, file);
    fclose(file);
}
}
