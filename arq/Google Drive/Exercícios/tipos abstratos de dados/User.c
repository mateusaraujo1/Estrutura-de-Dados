#include <string.h>
#include <stdlib.h>
#include "User.h"

struct User {
	char login[LOGIN_MAX_LENGTH];
	char password[PASSWORD_MAX_LENGTH];
};

User *User_alloc(char *login, char *password) {
	User *u;
	u = malloc(sizeof(User));
	if (u && login && password) {
		strcpy(u->login, login);
		strcpy(u->password, password);
	}
	return u;
}

void User_free(User *user) {
	if (user) {
		free(user);
	}
}

int User_authenticate(User *user, char *login, char *password) {
	if (user && login && password) {
		return strcmp(user->login, login) == 0 
				&& strcmp(user->password, password) == 0;
	}
	return 0;
}
