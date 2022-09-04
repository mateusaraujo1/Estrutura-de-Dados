#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char login[20];
    char login2[20];
    printf("Escreva: ");
    scanf("%[^\n]", login);
    printf("%s\n", login);

    scanf("%*c");

    scanf("%[^\n]", login2);
    printf("%s\n", login2);

    if (strcmp(login, login2) == 0)
    {
        printf("são iguais");
    }
    
    return 0;
}
