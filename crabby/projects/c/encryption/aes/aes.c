/*
*
*/

#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 128 // define fixed key length

unsigned char key[AES_KEY_LENGTH / 8] = "contortedwaterme"; // 32 bytes for 256-bit key
unsigned char iv[AES_BLOCK_SIZE]; // Initialization Vector



/*         ENCRYPTION       */
void aes_encrypt(unsigned char *plaintext, unsigned char *ciphertext) {
    AES_KEY encryptKey;
    AES_set_encrypt_key(key, AES_KEY_LENGTH, &encryptKey);
    AES_cbc_encrypt(plaintext, ciphertext, AES_BLOCK_SIZE, &encryptKey, iv, AES_ENCRYPT);
}

void aes_decrypt(unsigned char *ciphertext, unsigned char *plaintext) {
    AES_KEY decryptKey;
    AES_set_decrypt_key(key, AES_KEY_LENGTH, &decryptKey);
    AES_cbc_encrypt(ciphertext, plaintext, AES_BLOCK_SIZE, &decryptKey, iv, AES_DECRYPT);
}

int main() {
    unsigned char plaintext[AES_BLOCK_SIZE] = "Hello, World!123"; // 16 bytes
    unsigned char ciphertext[AES_BLOCK_SIZE];
    unsigned char decryptedtext[AES_BLOCK_SIZE];

    // Generate a random IV
    if (!RAND_bytes(iv, sizeof(iv))) {
        fprintf(stderr, "Error generating random bytes.\n");
        return 1;
    }

    // Encrypt the plaintext
    aes_encrypt(plaintext, ciphertext);
    printf("Ciphertext: ");
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    aes_decrypt(ciphertext, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}







