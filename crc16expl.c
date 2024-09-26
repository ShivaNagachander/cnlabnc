#include <stdio.h>
#include <string.h>

void main() {
    int i, j, keylen, msglen;
    char input[100], key[30], temp[100], quot[100], rem[30], key1[30];

    // Prompt user for the 16-bit binary data
    printf("Enter 16-bit Data (binary format): ");
    gets(input); // Unsafe function but used here for simplicity

    // Prompt user for the key (divisor) in binary format
    printf("Enter Key (binary format): ");
    gets(key);

    // Calculate the length of the key and input
    keylen = strlen(key);
    msglen = strlen(input);

    // Validate that the input is exactly 16 bits long
    if (msglen != 16) {
        printf("Error: Input data must be exactly 16 bits.\n");
        return; // Exit if input is not 16 bits
    }

    // Copy the original key to key1, as key will be modified later in the process
    strcpy(key1, key);

    // Copy the input message to a temporary string
    strcpy(temp, input);

    // Append (keylen - 1) zeros to the end of the temp message to prepare for division
    for (i = 0; i < keylen - 1; i++) {
        strcat(temp, "0"); // Adds zeros to the end of the message
    }

    // Perform the division (message XOR key) to get quotient and remainder
    for (i = 0; i < msglen; i++) {
        // Store the first bit of temp into quotient
        quot[i] = temp[0]; 

        // If quotient bit is '0', XOR with all zeros (do nothing)
        if (quot[i] == '0') {
            for (j = 0; j < keylen; j++) {
                key[j] = '0'; // Key becomes a string of zeros
            }
        } 
        // If quotient bit is '1', XOR with the original key
        else {
            for (j = 0; j < keylen; j++) {
                key[j] = key1[j]; // Key remains the original key for XOR
            }
        }

        // Perform XOR on temp and key, store the result in remainder (rem)
        for (j = keylen - 1; j > 0; j--) {
            // If temp[j] == key[j], result is 0; otherwise, result is 1 (XOR operation)
            if (temp[j] == key[j]) {
                rem[j - 1] = '0'; // XOR result is 0
            } else {
                rem[j - 1] = '1'; // XOR result is 1
            }
        }

        // Bring down the next bit for the next step of the division
        rem[keylen - 1] = temp[keylen + i]; 

        // Copy the remainder (rem) back into temp for the next iteration
        strcpy(temp, rem); 
    }

    // Output the quotient from the division
    printf("\nQuotient is ");
    for (i = 0; i < msglen; i++) {
        printf("%c", quot[i]);
    }

    // Output the remainder, which is the CRC value
    printf("\nRemainder is ");
    for (i = 0; i < keylen - 1; i++) {
        printf("%c", rem[i]);
    }

    // Output the final data (original message + remainder/CRC)
    printf("\nFinal data is: ");
    for (i = 0; i < msglen; i++) {
        printf("%c", input[i]); // Output original 16-bit input
    }
    for (i = 0; i < keylen - 1; i++) {
        printf("%c", rem[i]); // Append remainder to original message
    }
    
    printf("\n");
}
