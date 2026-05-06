The stat function is a system call in C used to retrieve information about a file from the inode. Instead of opening the file and reading its contents, stat looks at the metadata (size, permissions, timestamps, etc.).1. The Header and SyntaxTo use it, you need <sys/stat.h> and <sys/types.h>.C#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int stat(const char *pathname, struct stat *statbuf);
pathname: The path to the file.statbuf: A pointer to a struct stat where the function will write the file information.Returns: 0 on success, -1 on failure (and sets errno).2. The struct stat LayoutWhen stat succeeds, the structure is filled with details. Here are the most important fields:FieldDescriptionst_sizeFile size in bytes.st_modeFile type and permissions (e.g., is it a directory?).st_mtimeTime of last data modification.st_uid / st_gidUser ID and Group ID of the owner.st_nlinkNumber of hard links.3. Practical Example: Getting File SizeThis is a common way to check how large a file is before allocating a buffer to read it.C#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat sb;

    if (stat("config.json", &sb) == 0) {
        printf("File size: %lld bytes\n", (long long)sb.st_size);
        
        // Check if it's a directory or a regular file
        if (S_ISDIR(sb.st_mode)) {
            printf("This is a directory.\n");
        } else if (S_ISREG(sb.st_mode)) {
            printf("This is a regular file.\n");
        }
    } else {
        perror("stat failed");
    }

    return 0;
}
