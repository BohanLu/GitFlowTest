#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define DIR_PATH    "/home/bohan/tmp/"

int main(int argc, char** argv) {

    DIR *dir = NULL;
    struct dirent *dp;

    printf("List dir [%s]...\n", DIR_PATH);
    dir = opendir(DIR_PATH);
    while ((dp = readdir(dir))){
        printf("    [%s]\n", dp->d_name);
    }
    printf("List dir [%s] completed\n", DIR_PATH);

    return EXIT_SUCCESS;
}
