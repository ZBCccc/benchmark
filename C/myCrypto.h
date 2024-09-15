#include <stdlib.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include <openssl/sha.h>
#include <openssl/bn.h>

void prf_fp(const unsigned char *key, int key_len, const unsigned char *message, int message_len, const BIGNUM *p, const BIGNUM *g, BIGNUM *result){
    unsigned char mac[EVP_MAX_MD_SIZE]; // 声明 mac 变量
    unsigned int mac_len;     
    HMAC(EVP_sha256(), key, key_len, message, message_len, mac, &mac_len);

    BIGNUM *res = BN_bin2bn(mac, mac_len, NULL);

    // 初始化上下文
    BN_CTX* ctx = BN_CTX_new();

    BIGNUM *p_minus_1 = BN_new();
    BN_sub(p_minus_1, p, BN_value_one());

    BIGNUM* res_mod_p = BN_new();
    BN_mod(res_mod_p, res, p, ctx);

    if (BN_is_zero(res_mod_p)) {
        BN_add(res, res, BN_value_one());
    }

    BIGNUM *ex = BN_new();
    BN_mod(ex, res, p, ctx);

    BN_mod_exp(result, g, ex, p_minus_1, ctx);

    BN_free(res);
    BN_free(p_minus_1);
    BN_free(ex);

}