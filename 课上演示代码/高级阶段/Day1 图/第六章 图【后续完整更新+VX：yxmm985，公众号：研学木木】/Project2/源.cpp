#define MaxKey 1000
#include<stdio.h>
int hash(const char* key) {
	int h = 0, g;
	while (*key) {
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g) {
			h ^= g >> 24;
		}
		h &= ~g;
	}
	return h % MaxKey;
}
int main() {
	const char* pStr[5] = { "xiongda","lele","hanmeimei","wangdao","fenggu" };
	int i;
	const char* pHash_table[MaxKey] = { NULL };
	for (i = 0; i < 5; i++) {
		printf("%s is key =%d\n", pStr[i], hash(pStr[i]));
		pHash_table[hash(pStr[i])] = pStr[i];
	}
	return 0;
}
