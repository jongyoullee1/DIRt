#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main() {
    long int dirt_size = 0;
    DIR* stream = opendir(".");
    struct dirent* file = readdir(stream);
    printf("Stuff in directory:\n");
    while (file) {
        printf("- %s", (*file).d_name);
        if (file->d_type == DT_DIR) {
            printf(" (direct)");
        }
        else {
            struct stat buf;
            stat((*file).d_name, &buf);
            printf(" (%li bytes)", buf.st_size);
            dirt_size += buf.st_size;
        }
        printf("\n");
        file = readdir(stream);
    }
    printf("Directory size: %li bytes\n", dirt_size);
    closedir(stream);
    return 0;
}
