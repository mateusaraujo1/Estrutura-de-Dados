typedef struct User User;

User *User_alloc();
void User_free(User *u);
void User_insert(User *l, char login[], int password);
//LISTAR
//REMOVER