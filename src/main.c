#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[]){

    if(argc == 1){
        printf("No Actions Performed.\n");
        return 0;
    }

    bool cpp_mode = false;

    for(unsigned int i = 0; i < argc; i++){

        if(strstr(argv[i], "-cpp") != NULL){ // cpp mode activation
            cpp_mode = true;
            continue;
        }
        
        if(strstr(argv[i], "-c") != NULL){ // c mode activation
            cpp_mode = false;
            continue;
        }

        FILE* headerFile = fopen(argv[i], "r");

        if(!headerFile){
            printf("\"%s\" not found. Exiting program.\n", argv[i]);
            return 1;
        }

        char* newFileName = malloc(sizeof(char) * (strlen(argv[i]) + 2));
        if(!newFileName){
            printf("\"malloc()\" error. Exiting program.");
            return 2;
        }
        newFileName = strtok(argv[i], ".");

        if(cpp_mode){
            newFileName = strcat(newFileName, ".cpp");
        } else {
            newFileName = strcat(newFileName, ".c");
        }

        FILE* newFile = fopen(newFileName, "w");
        if(!newFile){
            printf("\"%s\" couldn't be created. Exiting program", newFileName);
            return 3;
        }
        free(newFileName);

        while(!feof(headerFile)){

            // TODO write file

        }

        fclose(newFile);
        fclose(headerFile);

    }

}