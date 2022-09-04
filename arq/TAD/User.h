typedef struct User User; //os membros da estrutura vão ser definidos em outro arquivo... então o main não vai ter acesso aos membros dessa struct, mas vai ter acesso às funções abaixo que podem acessar esses membros

User *User_create();
void User_delete();
int User_authenticate(User *u, char *password);
char *User_getLogin(User *u);
//funções q começam com get são apenas de leitura
void *User_setLogin(User *u, char *login);
//set recebe o login e altera o login da estrutura
