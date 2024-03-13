#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_LINE 512

int main(int argc, char* argv[]){

    if(argc == 1){
        printf("H -> C : Version 1.0\n");
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
        char userDataTypeFlag = 0;

        while((fgets(line, MAX_CHAR_LINE, headerFile)) != NULL){

            if(line[0] == '#'){
                continue;
            }

            if(userDataTypeFlag){

                if(strchr(line, '}') != NULL){ // ending the declaration
                    userDataTypeFlag = 0;
                }

                continue;

            }

            if(strstr(line, "struct") != NULL || strstr(line, "union") != NULL || strstr(line, "enum") != NULL){

                fpos_t currLinePos;
                fgetpos(headerFile, &currLinePos);

                char tempLine[MAX_CHAR_LINE];
                fgets(tempLine, MAX_CHAR_LINE, headerFile);

                if(strchr(tempLine, '{') != NULL){ // next line has "{"

                    userDataTypeFlag = 1;
                    continue;

                } else {

                    fsetpos(headerFile, &currLinePos);

                }



            }

            if(strchr(line, '{') != NULL){ // defining a user data type

                if(strrchr(line, '}') != NULL){ // one line declarations
                    continue;
                }

                userDataTypeFlag = 1;
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