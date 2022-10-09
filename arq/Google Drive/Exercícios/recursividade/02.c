#include <stdio.h>

float soma(float v[], int begin, int length) {
	if (begin == length)
		return 0;
	else
		return v[begin] + soma(v, begin+1, length);
}

int main() {
	float n[5] = {2.5, 3.5, 5.5, 7.5, 11.5};
	printf("soma = %f\n", soma(n, 0, 5));
	return 0;
}
