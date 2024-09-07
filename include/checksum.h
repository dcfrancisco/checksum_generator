#ifndef CHECKSUM_H
#define CHECKSUM_H

// Function to calculate the checksum of a string (line)
unsigned char calculate_checksum(const char *line);

// Function to convert the checksum to a two-character string
void checksum_to_string(unsigned char checksum, char *checksum_str);

#endif // CHECKSUM_H
