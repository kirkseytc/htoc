#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_LINE 1024

int main(int argc, char* argv[]){

    if(argc == 1){
        printf("No Actions Performed.\n");
        return 0;
    }

    for(unsigned int i = 1; i < argc; i++){

        const int len = strlen(argv[i]) + 1;

        char tempArr[len];
        strcpy(tempArr, argv[i]);

        FILE* headerFile = fopen(argv[i], "r");

        if(!headerFile){
            printf("\"%s\" not found. Exiting program.\n", argv[i]);
            return 1;
        }

        char* index = strchr(tempArr, '.');
        index++;
        *index = 'c';

        FILE* newFile = fopen(tempArr, "w");
        if(!newFile){
            printf("\"%s\" couldn't be created. Exiting program\n", tempArr);
            return 2;
        }

        fprintf(newFile, "#include \"%s.h\"\n", strtok(tempArr, "."));

        char line[MAX_CHAR_LINE];

        while((fgets(line, MAX_CHAR_LINE, headerFile)) != NULL){

            if(line[0] == '#'){
                continue;
            }

            for(unsigned short s = 0; s < MAX_CHAR_LINE; s++){

                if(line[s] == '\0'){
                    break;
                }

                if(line[s] == ';'){
                    fputs(" {\n\n}\n", newFile);
                    continue;
                }

                fputc(line[s], newFile);
            }

        }

        fclose(newFile);
        fclose(headerFile);

    }

}