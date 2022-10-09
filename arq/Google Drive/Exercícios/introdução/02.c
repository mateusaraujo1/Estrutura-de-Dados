#include <stdio.h>

int pot(int, int);

int main() {
	int x, z;
	printf("x = ");
	scanf("%d", &x);
	printf("z = ");
	scanf("%d", &z);
	printf("pot = %d\n", pot(x, z));
	
	return 0;
}

int pot(int a, int b) {
	int p = 1, i = 0;
	
	for (i = 0; i < b; i++) {
		p = p * a;
	}
	
	return p;
}
