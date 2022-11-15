#include <stdio.h>
#include "User.h"

int main() {
    char *login = "gandalf";
    char *pass = "tolkien";
    User *usr = User_create();

    User_setLogin(usr, login);
    User_setPassword(usr, pass);

    if (User_authenticate(usr, "mago"))
        printf("Usuario autenticado com sucesso.\n");
    else
        printf("Login ou senha invalidos.\n");
        
    if (User_authenticate(usr, "tolkien"))
        printf("Usuario autenticado com sucesso.\n");
    else
        printf("Login ou senha invalidos.\n");

    return 0;
}