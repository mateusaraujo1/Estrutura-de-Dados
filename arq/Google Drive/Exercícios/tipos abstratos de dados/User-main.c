#include <stdio.h>
#include "User.h"

int main() {
	int sa = 0;
	
	char lg[LOGIN_MAX_LENGTH], pw[PASSWORD_MAX_LENGTH];
	User *u = User_alloc("admin", "1234");
	do {
		scanf("%s%s", lg, pw);
		sa = User_authenticate(u, lg, pw);
		if (sa)
			printf("Sucesso\n");
		else
			printf("Falha\n");		
	}
	while (!sa);
	
	User_free(u);
	return 0;
}
