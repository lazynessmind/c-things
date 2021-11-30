#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("You must be kidding! How do you want to convert an number to hex if you don't provide the number!\n");
        return 1;
    } else {
        char hexBase[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

        int remainder;

        char buffer[1024] = "";

        if (argv[1] > 0) {
            long decimal = strtol(argv[1], NULL, 10);

            printf("Result for %li => ", decimal);

            while (decimal > 0) {
                remainder = decimal % 16;

                size_t bufferLen = strlen(buffer);
                memmove(buffer + 1, buffer, ++bufferLen);
                *buffer = hexBase[remainder];

                decimal = decimal / 16;
            }

            printf("%s", buffer);
        }
    }
    return 0;
}
