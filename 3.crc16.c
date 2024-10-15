#include <stdio.h>
#include <string.h>
void main() {
    int i, j, keylen, msglen;
    char input[100], key[30], temp[100], quot[100], rem[30], key1[30];
    printf("Enter 16-bit Data (binary format): ");
    gets(input);
    printf("Enter Key (binary format): ");
    gets(key);
    keylen = strlen(key);
    msglen = strlen(input);
    if (msglen != 16) {
        printf("Error: Input data must be exactly 16 bits.\n");
        return;
    }
    strcpy(key1, key);
    strcpy(temp, input);
    for (i = 0; i < keylen - 1; i++) {
        strcat(temp, "0");
    }
    for (i = 0; i < msglen; i++) {
        quot[i] = temp[0]; 
        if (quot[i] == '0') {
            for (j = 0; j < keylen; j++) {
                key[j] = '0';
            }
        } else {
            for (j = 0; j < keylen; j++) {
                key[j] = key1[j];
            }
        }
        for (j = keylen - 1; j > 0; j--) {
            if (temp[j] == key[j]) {
                rem[j - 1] = '0';
            } else {
                rem[j - 1] = '1';
            }
        }
        rem[keylen - 1] = temp[keylen + i];
        strcpy(temp, rem); 
    }
    printf("\nQuotient is ");
    for (i = 0; i < msglen; i++) {
        printf("%c", quot[i]);
    }
    printf("\nRemainder is ");
    for (i = 0; i < keylen - 1; i++) {
        printf("%c", rem[i]);
    }
    printf("\nFinal data is: ");
    for (i = 0; i < msglen; i++) {
        printf("%c", input[i]);
    }
    for (i = 0; i < keylen - 1; i++) {
        printf("%c", rem[i]);
    }
    printf("\n");
}
OUTPUT:
Enter 16-bit Data (binary format): 1001011010010110
Enter Key (binary format): 1001

Quotient is 1000011001011101
Remainder is 101
Final data is: 1001011010010110101
