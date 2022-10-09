#include <stdio.h>

int soma(int, int);

int main() {
	int n1, n2;
	printf("n1 = ");
	scanf("%d", &n1);
	printf("n2 = ");
	scanf("%d", &n2);
	printf("soma = %d\n", soma(n1, n2));
	
	return 0;
}

int soma(int a, int b) {
	int s = 0, i = 0;
	
	for (i = a; i <= b; i++) {
		s = s + i;
	}
	
	return s;
}
