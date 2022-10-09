#include <stdio.h>

void find(int m[4][4], int i, int j) {
	if (m[i][j] == 8) {
		printf("i = %d j = %d\n", i , j);
	}
	else {
		if (m[i][j] == 1)
			find(m, i-1, j);
		if (m[i][j] == 2)
			find(m, i, j+1);
		if (m[i][j] == 3)
			find(m, i+1, j);
		if (m[i][j] == 4)
			find(m, i, j-1);
	}
}

int main() {
	int m[4][4] = {{2,2,2,3},
				   {3,4,4,3},
				   {3,8,1,3},
				   {2,1,1,4}};
	find(m, 0, 0);
	return 0;
}
