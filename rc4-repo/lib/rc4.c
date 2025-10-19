#include "rc4.h"

void rc4_init(const uint8_t *key, size_t key_len, rc4_state *state) {
    for (int i = 0; i < 256; i++) {
        state->S[i] = i;
    }
    state->i = 0;
    state->j = 0;

    uint8_t j = 0;
    for (int i = 0; i < 256; i++) {
        j = j + state->S[i] + key[i % key_len];
        uint8_t temp = state->S[i];
        state->S[i] = state->S[j];
        state->S[j] = temp;
    }
}

uint8_t rc4_getbyte(rc4_state *state) {
    state->i = (state->i + 1) & 0xFF;
    state->j = (state->j + state->S[state->i]) & 0xFF;

    uint8_t temp = state->S[state->i];
    state->S[state->i] = state->S[state->j];
    state->S[state->j] = temp;

    return state->S[(state->S[state->i] + state->S[state->j]) & 0xFF];
}

void rc4_crypt(rc4_state *state, const uint8_t *in, uint8_t *out, size_t len) {
    for (size_t n = 0; n < len; n++) {
        out[n] = in[n] ^ rc4_getbyte(state);
    }
}
