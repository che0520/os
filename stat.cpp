#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <string.h>


void handle_mdtm(const char* filepath) {
    struct stat file_stat;
    stat(filepath, &file_stat);
    struct tm *gmt = gmtime(&file_stat.st_mtime);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y%m%d%H%M%S", gmt);
    printf("%s\n", time_str);
}


int main() {
    handle_mdtm("README.md");
    return 0;
}
