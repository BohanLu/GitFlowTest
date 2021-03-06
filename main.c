#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define DIR_PATH    "/home/bohan/tmp/"

int create_folder(const char *path, mode_t mode){
    return mkdir(path, mode);
}

int remove_folder(const char *path){
    return rmdir(path);
}

void list_number_of_elements(const char *path){

    if (!path){
        printf("Invalid path !!!\n");
        return;
    }

    int counts = folder_operation(path, false);
    printf("Number of elements in dir [%s] = %d\n", path, counts);
    return;
}

void list_folder(const char *path){

    if (!path){
        printf("Invalid path !!!\n");
        return;
    }

    folder_operation(path, true);
    return;
}

int folder_operation(const char *path, bool is_print){

    DIR *dir = NULL;
    struct dirent *dp;
    int counts = 0;

    if (!path){
        printf("Invalid path !!!\n");
        return -1;
    }

    if (is_print)
        printf("List dir [%s]...\n", path);

    dir = opendir(path);
    while ((dp = readdir(dir))){

        if (is_print)
            printf("    [%s]\n", dp->d_name);
        counts++;
    }

    if (is_print)
        printf("List dir [%s] completed\n", path);

    return counts;
}

int main(int argc, char** argv) {

    list_folder(DIR_PATH);
    return EXIT_SUCCESS;
}
