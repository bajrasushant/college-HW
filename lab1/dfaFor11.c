#include <stdio.h>
#include <string.h>
#define MAX 10


void checkString(char s);
void checkDFA(char s[]);


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
                if (s[i] == '1') state = 'b';
                else if (s[i] == '0') state = 'a';

            break;
            case 'b':
                if (s[i] == '0') state = 'a';
                else if (s[i] == '1') state = 'c';
            break;
            case 'c':
                if (s[i] == '1') state = 'c';
                else if (s[i] == '0') state = 'a';
            break;
        }
    }
    checkString(state);
}

void checkString(char s)
{
    if (s == 'c')
    {
        printf("String is accepted.\n");
    }
    else{
        printf("String not accepted.\n");
    }
}
