#include <stdio.h>

int pot(int x, int n) {
	if (n == 0)
		return 1;
	else
		return x * pot(x, n-1);
}

int main() {
	printf("2**3 = %d\n", pot(2,3));
	return 0;
}
