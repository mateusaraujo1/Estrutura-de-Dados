typedef struct User User;

User *User_alloc();
void User_free(User *u);
void User_insert(User *u, char login[], int password);
void User_print(User *u);
int User_remove(User* u, char login[]);
int User_menu(User *u);