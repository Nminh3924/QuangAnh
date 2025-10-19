#include <stdio.h>
#include <string.h>
#include "../lib/rc4.h"

void hex_to_bytes(const char *hex, unsigned char *bytes) {
    for (int i = 0; i < strlen(hex) / 2; i++) {
        sscanf(hex + 2*i, "%2hhx", &bytes[i]);
    }
}

int main() {
    const char *key = "RC4Key123";
    const char *ciphertext_hex = "14a44411bd2276d0e160a73c138e38943a712c4364dcce966179e5380b4df2f18f10939ad4d30298b229";
    unsigned char ciphertext[1024];
    unsigned char decrypted[1024];

    int cipher_len = strlen(ciphertext_hex) / 2;
    hex_to_bytes(ciphertext_hex, ciphertext);

    rc4_state st;
    rc4_init((const uint8_t*)key, strlen(key), &st);
    rc4_crypt(&st, ciphertext, decrypted, cipher_len);

    decrypted[cipher_len] = '\0';
    printf("Kết quả: %s\n", decrypted);
    return 0;
}
