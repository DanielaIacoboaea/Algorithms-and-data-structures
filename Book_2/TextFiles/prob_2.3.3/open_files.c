#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *demo;
    char buff[255];
    //FILE *fopen(const char *invatacel, const char a+);
    // CALE ABSOLUTA (absolute path)
    //demo = fopen("/root/sandbox/textFiles/files/demo_file.txt", "w+");
    // CALE RELATIVA (relative path) - RELATIVA LA LOCUL IN CARE ESTI CAND EXECUTI PROGRAMUL (in terminal)
    demo = fopen("files/demo_file.txt", "r");
    if(demo == NULL) {
        printf("EROARE!!\n");
        return 1;
    }

   // fprintf(demo,"This is testing for printf..\n");
    //fputs("This is testing for fputs...\n", demo);
    fscanf(demo, "%s", buff);
    printf("1: %s\n", buff);

    fgets(buff, 255, (FILE*)demo);
    printf("2: %s\n", buff);

    fgets(buff, 255, (FILE*)demo);
    printf("3: %s\n", buff);
    fclose(demo);
    return 0;
}
