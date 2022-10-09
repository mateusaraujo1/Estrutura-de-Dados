#include <stdio.h>

void print(int v[], int begin, int length) {
	if (begin < length) {
		printf("%d ", v[begin]);
		print(v, begin+1, length);
	}
}

int main() {
	int n[5] = {2,3,5,7,11};
	print(n, 0, 5);
	return 0;
}


