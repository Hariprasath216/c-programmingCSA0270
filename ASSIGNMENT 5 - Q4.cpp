#include <stdio.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024
int main()
 {
    FILE *file;
    char filename[256];
    char search_string[256];
    char line[MAX_LINE_LENGTH];
   printf("Enter the name of the file to search: ");
    fgets(filename, 256, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    printf("Enter the search string: ");
    fgets(search_string, 256, stdin);
    search_string[strcspn(search_string, "\n")] = '\0';
    file = fopen(filename, "r");
    if (file == NULL)
	 {
        printf("Error opening file\n");
        return 1;
    }
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strstr(line, search_string) != NULL) {
            printf("%s", line);
        }
    }
    fclose(file);

    return 0;
}
