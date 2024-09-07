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
