#define LOGIN_MAX_LENGTH 20
#define PASSWORD_MAX_LENGTH 20

typedef struct User User;

User *User_alloc(char *login, char *password);
void  User_free(User *user);
int   User_authenticate(User *user, char *login, char *password);
