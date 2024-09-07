# Checksum Generator for Source Files

This program reads a source file where each line contains code, calculates a checksum for each line, and outputs a new file. The checksum is placed at the beginning of each line, followed by a specific number of spaces, and then the original line is printed, including any line numbers.

## Features
- **Checksum Calculation**: The program calculates the checksum for each line, including the line numbers if present.
- **Customizable Spacing**: The number of spaces between the checksum and the original line can be adjusted via the `SPACE_WIDTH` constant.
- **Output**: The output is saved to a new file with the same name as the input but with the `.out` extension.

## Background: Inspired by **COMPUTE!** Magazine

This program is inspired by the checksum method used in **COMPUTE!** and **COMPUTE!'s Gazette** magazines during the 1980s. These magazines published type-in programs for popular home computers like the Commodore 64, Atari, and Apple II. Readers could manually type in machine code or BASIC programs from the magazine into their computers.

To help reduce errors when manually entering long strings of code, the magazines often used a checksum system. Each line of code or data was accompanied by a checksum value that helped users detect any typing mistakes. This program implements a similar system to calculate checksums for each line of a source file.

## Algorithm Overview

### Checksum Calculation
The checksum algorithm used in this program is simple but effective for basic error detection. The algorithm works as follows:
1. **Input Line**: The entire line (including line numbers and code) is used to calculate the checksum.
2. **ASCII Sum**: The checksum is calculated by summing the ASCII values of all characters in the line.
3. **Modulo 256**: The sum is then taken modulo 256 to ensure the checksum fits in a single byte (0-255).
4. **Hexadecimal Representation**: The final checksum is printed as a two-character hexadecimal value.

This method ensures that any changes to the characters or line structure will alter the checksum, making it useful for detecting errors in data entry, similar to the approach used in **COMPUTE!** magazine’s type-in programs.

### Example
For the line:
```
540 PUT(NX,I+16),FALL
```

The checksum is calculated as the sum of the ASCII values of each character in `540 PUT(NX,I+16),FALL`, which results in a checksum of `D0` (in hexadecimal). The output format will be:
```
D0     540 PUT(NX,I+16),FALL
```

## How to Use

### Requirements
- A C compiler (e.g., `gcc`).

### Compilation

1. Clone or download this repository.
2. Compile the program using a C compiler:
   ```bash
   gcc -o checksum_generator checksum_generator.c
   ```

### Running the Program

Run the program with an input file as a parameter:
```bash
./checksum_generator inputfile.txt
```

This will generate a new file with the `.out` extension that contains the checksum for each line.

### Example
For an input file `example.txt` containing:
```
540 PUT(NX,I+16),FALL
550 DATA &H2C,&H17,&H0,&H5,&H0,&H0,&H4015,&H0
```

The output will be saved in `example.out`:
```
D0     540 PUT(NX,I+16),FALL
AF     550 DATA &H2C,&H17,&H0,&H5,&H0,&H0,&H4015,&H0
```

### Customization
- **Adjusting Spaces**: You can adjust the number of spaces between the checksum and the line of code by modifying the `SPACE_WIDTH` constant in the code:
  ```c
  #define SPACE_WIDTH 5  // Adjust the number of spaces here
  ```

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
