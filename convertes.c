#include <stdio.h>
#include <mem.h>

void expandAndTerminate(char *buffer, int position, int bitCounter, char symbol, char separator) {
    int remainder = bitCounter & 3;
    if (remainder != 0 || position == 1) {
        for (int i = remainder; i < 4; i++) {
            buffer[position] = symbol;
            position++;
        }
        buffer[position] = separator;
        position++;
    }
    buffer[position] = '\0';
    buffer = strrev(buffer);
}

void transformToBinary(long long number, char *buffer) {
    const char char0 = '0', char1 = '1', separator = '|';
    int position = 1, bitCounter = 0;
    buffer[0] = separator;
    while (number > 0) {
        int bit = number & 1;
        if (bit == 1)
            buffer[position] = char1;
        else
            buffer[position] = char0;
        number >>= 1;
        position++;
        bitCounter++;
        if ((bitCounter & 3) == 0) {
            buffer[position] = separator;
            position++;
        }
    }
    expandAndTerminate(buffer, position, bitCounter, char0, separator);
}

int main() {
    long long number;
    scanf("%lli", &number);
    char buffer[200];
    transformToBinary(number, buffer);
    printf(buffer);
    return 0;
}