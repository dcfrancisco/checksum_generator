#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE_WIDTH 3

// Function to calculate checksum of a string (line)
unsigned char calculate_checksum(const char *line)
{
    unsigned char checksum = 0;
    for (int i = 0; line[i] != '\0'; i++)
    {
        checksum = (checksum + line[i]) % 256;
    }
    return checksum;
}

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
    strncpy(output_filename, argv[1], sizeof(output_filename));
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

        // Print the checksum followed by the original line in the output file

        fprintf(output_file, "%02X%*s%s\n", checksum, SPACE_WIDTH, "", line);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Output written to: %s\n", output_filename);
    return 0;
}
