#ifndef RC4_H
#define RC4_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint8_t S[256];
    uint8_t i, j;
} rc4_state;

void rc4_init(const uint8_t *key, size_t key_len, rc4_state *state);
uint8_t rc4_getbyte(rc4_state *state);
void rc4_crypt(rc4_state *state, const uint8_t *in, uint8_t *out, size_t len);

#endif
