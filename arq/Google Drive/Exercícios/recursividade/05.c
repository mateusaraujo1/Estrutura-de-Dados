#include <stdio.h>

void bin(int x) {
	if (x > 0) {
		bin(x/2);
		printf("%d", x%2);
	}
}

int main() {
	printf("255 = ");
	bin(255);
	printf("\n");
	return 0;
}
