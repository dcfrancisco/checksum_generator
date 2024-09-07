#ifndef CHECKSUM_H
#define CHECKSUM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE_WIDTH 3

// Function to calculate the checksum of a string (line)
unsigned char calculate_checksum(const char *line);

#endif // CHECKSUM_H
