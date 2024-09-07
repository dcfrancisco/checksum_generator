#include "checksum.h"

// Function to calculate the checksum of a string (line)
unsigned char calculate_checksum(const char *line)
{
    unsigned char checksum = 0;
    for (int i = 0; line[i] != '\0'; i++)
    {
        checksum = (checksum + line[i]) % 256;
    }
    return checksum;
}

// Function to convert the checksum to a two-character string
void checksum_to_string(unsigned char checksum, char *checksum_str)
{
    checksum_str[0] = (checksum / 16) + 'A';
    checksum_str[1] = (checksum % 16) + 'A';
    checksum_str[2] = '\0';
}
