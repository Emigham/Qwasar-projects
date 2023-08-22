#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Iterate through each file name passed as argument
  for (int i = 1; i < argc; i++) {
    // Open the file in read-only mode
    FILE *file = fopen(argv[i], "r");

    // Check if the file was opened successfully
    if (file == NULL) {
      printf("Error opening file: %s\n", argv[i]);
      continue;
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate a buffer to hold the contents of the file
    char *buffer = malloc(size + 1);
    if (buffer == NULL) {
      printf("Error allocating memory for file: %s\n", argv[i]);
      fclose(file);
      continue;
    }

    // Read the contents of the file into the buffer
    size_t bytes_read = fread(buffer, 1, size, file);
    if (bytes_read != size) {
      printf("Error reading file: %s\n", argv[i]);
      free(buffer);
      fclose(file);
      continue;
    }

    // Null-terminate the buffer
    buffer[size] = '\0';

    // Print the contents of the buffer to the console
    printf("%s", buffer);

    // Free the buffer and close the file
    free(buffer);
    fclose(file);
  }

  return 0;
}
