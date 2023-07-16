#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main() {
    FILE *file1, *file2;
    uint32_t num1, num2, sum;

    file1 = fopen("thousand.bin", "rb");
    if (file1 == NULL) {
        printf("Error opening file1\n");
        return 1;
    }

    file2 = fopen("five-hundred.bin", "rb");
    if (file2 == NULL) {
        printf("Error opening file2\n");
        fclose(file1);
        return 1;
    }

    if (fread(&num1, sizeof(uint32_t), 1, file1) != 1) {
        printf("Error reading from file1\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    if (fread(&num2, sizeof(uint32_t), 1, file2) != 1) {
        printf("Error reading from file2\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    num1 = ntohl(num1);
    num2 = ntohl(num2);
    sum = num1 + num2;
    printf("num1: %u\n", num1);
    printf("num2: %u\n", num2);

    printf("Sum: %u\n", sum);

    fclose(file1);
    fclose(file2);

    return 0;
}

