#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

const char sum[] = {
	0x3a, 0x87, 0x03, 0xf5,
	0x60, 0xb3, 0x76, 0x8e,
	0x02, 0x77, 0x09, 0x4c,
	0x58, 0xc6, 0x86, 0xe1
};

#define MAXLEN 20

char passwd[MAXLEN+1] = {0};

/*
void test_password() {
	char cmdline[512] = {0};
	snprintf(cmdline, sizeof(cmdline), "mkpasswd --method=sha-512 -S %s %s", salt, passwd);
	FILE *proc = popen(cmdline, "r");
	fgets(cmdline, sizeof(cmdline), proc);
	pclose(proc);
	printf("Tested: %s\n", passwd);
	if(!strcmp(sum, cmdline+12)) {
		printf("Correct result: %s\n", passwd);
		exit(0);
	}
}
*/
// md5 stuff goes here
const uint8_t s[64] = {
	7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
	5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
	4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
	6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
};
const uint32_t K[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};
const uint32_t iv[4]= {
	0x67452301,
	0xefcdab89,
	0x98badcfe,
	0x10325476
};

#define lrot(x, y)	(((x) << (y)) | ((x) >> (32-(y))))
void md5(const char *input, uint8_t output[16]) {
	uint8_t msg[64] = {0};
	int len = strlen(input);
	memcpy(msg, input, len);
	msg[len++] = 0x80; // 1000 0000
	while(len < 56) {
		msg[len++] = 0x0;
	}
	if(len != 56) {
		printf("md5: padding failure, input probably too long\n");
		return;
	}
	uint64_t bitlen = strlen(input)*8;
	memcpy(msg+len, &bitlen, sizeof(bitlen));
	len += sizeof(bitlen);

	// time to do something with msg
	uint32_t *M = (uint32_t*)msg;
	uint32_t v[4];
	v[0] = iv[0];
	v[1] = iv[1];
	v[2] = iv[2];
	v[3] = iv[3];
	int i = 0;
	for(i = 0; i < 64; i++) {
		uint32_t F;
		uint32_t g;
		if(i < 16) {
			F = (v[1] & v[2]) | ((~v[1]) & v[3]);
			g = i;
		} else if(i < 32) {
			F = (v[3] & v[1]) | ((~v[3]) & v[2]);
			g = ((5*i) + 1) % 16;
		} else if(i < 48) {
			F = v[1] ^ v[2] ^ v[3];
			g = ((3*i)+5) % 16;
		} else {
			F = v[2] ^ (v[1] | (~v[3]));
			g = (7*i) % 16;
		}
		uint32_t tmp = v[3];
		v[3] = v[2];
		v[2] = v[1];
		v[1] = v[1] + lrot((v[0] + F + K[i] + M[g]), s[i]);
		v[0] = tmp;
	}
	v[0] += iv[0];
	v[1] += iv[1];
	v[2] += iv[2];
	v[3] += iv[3];
	memcpy(output, v, sizeof(v));
}

inline void test_password() {
	uint8_t out[16];
	md5(passwd, out);
	if(!memcmp(out, sum, 16)) {
		printf("Correct password: %s\n", passwd);
		exit(0);
	}
}

inline void recursive_generate(char *p, int l) {
	if(l <= 0) {
		*p = 0;
		test_password();
		return;
	}
	int i;
	for(i='a';i<='z';i++) {
		*p = i;
		recursive_generate(p+1, l-1);
	}
}

int main() {
	int i = 1;
	for(; i < MAXLEN; i++) {
		printf("Testing length %i\n", i);
		recursive_generate(passwd, i);
	}

	return 1;
}
