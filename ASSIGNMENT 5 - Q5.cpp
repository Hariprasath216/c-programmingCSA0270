#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM_LETTERS 26

int main() 
{
	char strcspn;
    FILE *input_file;
    FILE *output_file;
    char filename[256];
    char line[1024];
    int letter_counts[NUM_LETTERS] = {0};
    int i, c;
    printf("Enter the name of the input file: ");
    fgets(filename, 256, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    input_file = fopen(filename, "r");
    if (input_file == NULL) 
	{
        printf("Error opening input file\n");
        return 1;
    }
    while (fgets(line, 1024, input_file) != NULL) {
        for (i = 0; line[i] != '\0'; i++) {
            c = tolower(line[i]);
            if (isalpha(c)) {
                letter_counts[c - 'a']++;
            }
        }
    }

    
    output_file = fopen("statistics.txt", "w");
    if (output_file == NULL)
	 {
        printf("Error opening output file\n");
        return 1;
    }

    for (i = 0; i < NUM_LETTERS; i++) 
	{
        fprintf(output_file, "%c: %d\n", 'a' + i, letter_counts[i]);
    }
    fclose(input_file);
    fclose(output_file);

    return 0;
}
