typedef struct User User;

User *User_create();
int   User_delete(User *);
int   User_authenticate(User *, char *);
char *User_getLogin(User *);
char *User_getPassword(User *);
int   User_setLogin(User *, char *);
int   User_setPassword(User *, char *);