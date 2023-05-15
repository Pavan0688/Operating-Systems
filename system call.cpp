#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100], data[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating the file.\n");
        exit(1);
    }

    printf("Enter data to write in the file (max 100 characters):\n");
    scanf(" %[^\n]", data);

   
    fprintf(file, "%s", data);

    fclose(file);

    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    printf("\nData read from the file:\n");
    
   
    while (fgets(data, sizeof(data), file) != NULL) {
        printf("%s", data);
    }

    fclose(file);

    return 0;
}
