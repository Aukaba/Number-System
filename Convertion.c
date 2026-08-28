#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert an unsigned long long integer to binary string
void to_binary_string(unsigned long long n, char *out_str) {
    if (n == 0) {
        strcpy(out_str, "0");
        return;
    }
    
    char temp[65];
    int index = 0;
    
    while (n > 0) {
        temp[index++] = (n % 2) + '0';
        n /= 2;
    }
    
    // Reverse the string
    for (int i = 0; i < index; i++) {
        out_str[i] = temp[index - 1 - i];
    }
    out_str[index] = '\0';
}

// Function to display number in all 4 systems
void display_all_bases(unsigned long long val) {
    char bin_str[65];
    to_binary_string(val, bin_str);

    printf("Binary      : %s\n", bin_str);
    printf("Octal       : %llo\n", val);
    printf("Decimal     : %llu\n", val);
    printf("Hexadecimal : %llX\n", val);
}

// Function to validate string against the specified base
int is_valid_for_base(const char *str, int base) {
    if (str == NULL || *str == '\0') return 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        switch (base) {
            case 2:
                if (c != '0' && c != '1') return 0;
                break;
            case 8:
                if (c < '0' || c > '7') return 0;
                break;
            case 10:
                if (!isdigit((unsigned char)c)) return 0;
                break;
            case 16:
                if (!isxdigit((unsigned char)c)) return 0;
                break;
            default:
                return 0;
        }
    }
    return 1;
}

// Function to safely clear input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int num_inputs = 0;
    unsigned long long total_decimal = 0;

    printf("=============================================\n");
    printf("    WELCOME TO THE NUMBER SYSTEM CONVERTER   \n");
    printf("=============================================\n");

    // 1. Get number of inputs (minimum 3)
    while (1) {
        printf("How many numbers do you want to convert? (Minimum 3): ");
        if (scanf("%d", &num_inputs) == 1) {
            if (num_inputs >= 3) {
                break;
            }
            printf("Error: You must enter at least 3 inputs.\n");
        } else {
            printf("Error: Invalid integer. Try again.\n");
            clear_input_buffer();
        }
    }

    // 2. Loop through each input
    for (int i = 1; i <= num_inputs; i++) {
        int base = 0;
        char num_str[100];
        unsigned long long decimal_val = 0;

        printf("\n--- INPUT %d ---\n", i);

        // Get valid base
        while (1) {
            printf("Select base (2 for Binary, 8 for Octal, 10 for Decimal, 16 for Hexadecimal): ");
            if (scanf("%d", &base) == 1) {
                if (base == 2 || base == 8 || base == 10 || base == 16) {
                    break;
                }
                printf("Error: Invalid base. Please enter 2, 8, 10, or 16.\n");
            } else {
                printf("Error: Please enter a valid number.\n");
                clear_input_buffer();
            }
        }

        clear_input_buffer(); // Clear newline before reading string

        // Get and validate input string for chosen base
        while (1) {
            printf("Enter the number (Base %d): ", base);
            if (fgets(num_str, sizeof(num_str), stdin) != NULL) {
                // Strip trailing newline
                num_str[strcspn(num_str, "\r\n")] = 0;

                if (strlen(num_str) > 0 && is_valid_for_base(num_str, base)) {
                    // Convert string to unsigned long long in the specified base
                    char *endptr;
                    decimal_val = strtoull(num_str, &endptr, base);
                    break;
                }
                printf("Error: '%s' is not a valid Base %d number. Try again.\n", num_str, base);
            }
        }

        // Accumulate total sum
        total_decimal += decimal_val;

        // Display individual results
        printf("\n--- INDIVIDUAL RESULT ---\n");
        display_all_bases(decimal_val);
        printf("-------------------------\n");
    }

    return 0;
}