#include <stdio.h>

void runLengthEncoding(char *str) {
    int i, count;

    for (i = 0; str[i] != '\0'; i++) {
        // Count occurrences of current character
        count = 1;
        while (str[i] == str[i + 1] && count < 9) {
            count++;
            i++;
        }

        // Print encoded character and count
        printf("%c%d", str[i], count);
    }
}

int main() {
    char input[] = "AABBBCCCCddd";
    printf("Input: %s\n", input);
    
    printf("Output: ");
    runLengthEncoding(input);

    return 0;
}
