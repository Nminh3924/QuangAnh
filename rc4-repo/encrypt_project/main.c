#include <stdio.h>
#include <string.h>
#include "../lib/rc4.h"

int main() {
    const char *key = "RC4Key123";
    const char *plaintext = "Hanoi University of Science and Technology";

    rc4_state st;
    rc4_init((const uint8_t*)key, strlen(key), &st);

    unsigned char ciphertext[1024];
    rc4_crypt(&st, (const uint8_t*)plaintext, ciphertext, strlen(plaintext));

    printf("Kết quả: ");
    for (size_t i = 0; i < strlen(plaintext); i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    return 0;
}
