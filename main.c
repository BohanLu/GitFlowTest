#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define DIR_PATH    "/home/bohan/tmp/"

void list_folder(char *path){

    DIR *dir = NULL;
    struct dirent *dp;

    printf("List dir [%s]...\n", path);
    dir = opendir(path);
    while ((dp = readdir(dir))){
        printf("    [%s]\n", dp->d_name);
    }
    printf("List dir [%s] completed\n", path);

}

int main(int argc, char** argv) {

    list_folder(DIR_PATH);
    return EXIT_SUCCESS;
}
