#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <openssl/md5.h>

const char sum[] = {
	0x3a, 0x87, 0x03, 0xf5,
	0x60, 0xb3, 0x76, 0x8e,
	0x02, 0x77, 0x09, 0x4c,
	0x58, 0xc6, 0x86, 0xe1
};

#define MAXLEN 20
char passwd[MAXLEN+1] = {0};

void test_password() {
	uint8_t out[16];
	MD5((unsigned char *)passwd, strlen(passwd), out);
	if(!memcmp(out, sum, 16)) {
		printf("Correct password: %s\n", passwd);
		exit(0);
	}
}

void recursive_generate(char *p, int l) {
	// if length is 0, zero terminate here and test the password
	if(l <= 0) {
		*p = 0;
		test_password();
		return;
	}

	int i;
	for(i='a';i<='z';i++) {
		// try every possibility and then recurse
		*p = i;
		recursive_generate(p+1, l-1);
	}
}

int main() {
	int i = 1;
	// from length 1 - MAXLEN, generate passwords
	for(; i <= MAXLEN; i++) {
		printf("Testing length %i\n", i);
		recursive_generate(passwd, i);
	}

	return 1;
}
