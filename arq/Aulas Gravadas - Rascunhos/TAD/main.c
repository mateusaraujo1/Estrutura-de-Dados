#include <stdio.h>
#include <stdlib.h>
#include "User.h"

int main() {
    User *u = User_create();
    User_setLogin(u, "gandalf");
    printf("login = %s\n", u->login);
    return 0;
}