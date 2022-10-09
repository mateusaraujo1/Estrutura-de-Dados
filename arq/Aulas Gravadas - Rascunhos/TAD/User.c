#include <stdlib.h>
#include <string.h>
#include "User.h"

User *User_create(){
    User *u = malloc(sizeof(User));
    return u;
}
void  User_delete(){

}
int   User_authenticate(User *u, char *password){

}
char *User_getLogin(User *u){
    return u->login;
}
void  User_setLogin(User *u, char *login){
    strcpy(u->login, login); 
    //passa o valor de login para u->login
}