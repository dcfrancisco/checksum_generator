#include "checksum.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments are provided
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the input file for reading
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        perror("Error opening input file");
        return 1;
    }

    // Prepare the output file name by changing the extension
    char output_filename[256];
    snprintf(output_filename, sizeof(output_filename), "%s", argv[1]);
    char *dot = strrchr(output_filename, '.');
    if (dot != NULL)
    {
        strcpy(dot, ".out"); // Change the extension to ".out"
    }
    else
    {
        strcat(output_filename, ".out"); // Add ".out" if no extension is found
    }

    // Open the output file for writing
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL)
    {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    // Buffer to store each line
    char line[1024];

    // Process each line of the input file
    while (fgets(line, sizeof(line), input_file))
    {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Calculate the checksum for the line
        unsigned char checksum = calculate_checksum(line);

        // Convert the checksum to a two-character string
        char checksum_str[3];
        checksum_to_string(checksum, checksum_str);

        // Print the checksum followed by the original line in the output file
        fprintf(output_file, "%s   %s\n", checksum_str, line); // 3 spaces between checksum and line
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Output written to: %s\n", output_filename);
    return 0;
}
