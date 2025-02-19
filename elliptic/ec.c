#include <openssl/ec.h>
#include <openssl/bn.h>
#include <stdio.h>

int main() {
    EC_GROUP *curve = EC_GROUP_new_by_curve_name(NID_secp256k1);
    EC_KEY *key = EC_KEY_new();
    EC_KEY_set_group(key, curve);

    EC_KEY_generate_key(key);

    printf("Private Key: ");
    BN_print_fp(stdout, EC_KEY_get0_private_key(key));
    printf("\n");

    printf("Public Key: ");
    EC_POINT_print_fp(stdout, EC_KEY_get0_public_key(key), curve);
    printf("\n");

    EC_KEY_free(key);
    EC_GROUP_free(curve);
    return 0;
}