#include <stdio.h>
#include <string.h>
#include <openssl/hmac.h>
#include <time.h>

#define KEY "secret_key"
#define MESSAGE "Hello, World!"
#define ITERATIONS 1000

int main() {
    unsigned char hmac[EVP_MAX_MD_SIZE];
    unsigned int hmac_len;
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for (int i = 0; i < ITERATIONS; i++) {
        HMAC(EVP_sha256(), KEY, strlen(KEY), (unsigned char*)MESSAGE, strlen(MESSAGE), hmac, &hmac_len);
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("C: HMAC operation executed %d times in %f seconds\n", ITERATIONS, cpu_time_used);

    return 0;
}