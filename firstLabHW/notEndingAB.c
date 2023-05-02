#include <stdio.h>
#include <string.h>
#define MAX 10

void checkDFA(char s[]);
void checkString(char s);

int main(void) 
{
    char str[MAX];
    printf("Enter the string to check(of length 10): ");
    scanf("%s", str);
    checkDFA(str);
    return 0;
}

void checkDFA(char s[])
{
    char state = 'a';

    for (int i = 0; i < strlen(s); i++)
    {
        switch(state) 
        {
            case 'a': 
                if (s[i] == 'a') state = 'b';
                else if (s[i] == 'b') state = 'a';

            break;
            case 'b':
                if (s[i] == 'a') state = 'b';
                else if (s[i] == 'b') state = 'c';
            break;
            case 'c':
                if (s[i] == 'a') state = 'b';
                else if (s[i] == 'b') state = 'a';
            break;
        }
    }
    checkString(state);
}

void checkString(char s)
{
    if (s == 'c')
    {
        printf("String not accepted.\n");
    }
    else
    {
        printf("String is accepted.\n");
    }
}


