#include "stdio.h"

typedef struct data {
	float value1;
	float value2;
} stuff;

#define alpha 1.2345
#define beta 9485.23
#define init(x) stuff x = {.value1 = alpha, .value2 = beta}

void print_bin(unsigned int n) {
	while(n) {
		if(n & 1) printf("1");
		else printf("0");
		n >>= 1;
	}
	printf("\n");
}
	
int main() {
	init(a);
	printf("%f %f\n", a.value1, a.value2);
	unsigned int z = 12;
	print_bin(z);
	return 0;
}
