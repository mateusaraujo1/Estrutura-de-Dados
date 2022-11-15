#include <stdlib.h>
#include <string.h>
#include "User.h"

struct User {
    char login[120];
    char password[30];
};

User *User_create() {
    User *u = (User *) malloc(sizeof (User));
    return u;
}

int User_delete(User *usr) {
    free(usr);
    usr = NULL;
    return 0;
}

int User_authenticate(User *usr, char *pass) {
    return strcmp(usr->password, pass) == 0;
}

char *User_getLogin(User *usr) {
    return usr->login;
}
char *User_getPassword(User *usr) {
    return usr->password;
}
int User_setLogin(User *usr, char *login) {
    strcpy(usr->login, login);
    return 0;
}
int User_setPassword(User *usr, char *pass) {
    strcpy(usr->password, pass);
    return 0;
}
