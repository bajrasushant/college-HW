#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100 

int
main()
{
	printf("Enter a string: ");
	char str[MAX] = { 0 };
	scanf("%s", str);
	int str_len = strlen(str);

	char first_char = str[0];
	if (!isalpha(first_char) && first_char != '_') {
		printf("Invalid identifier\n");
		return 0;
	}

	char *keywords[] = { "auto",     "break",    "case",     "char",
			     "const",    "continue", "default",  "do",
			     "double",   "else",     "enum",     "extern",
			     "float",    "for",      "goto",     "if",
			     "int",      "long",     "register", "return",
			     "short",    "signed",   "sizeof",   "static",
			     "struct",   "switch",   "typedef",  "union",
			     "unsigned", "void",     "volatile", "while",
			     NULL };

	int i = 0;
	for (char *keyword = keywords[0]; keyword != NULL;
	     keyword       = keywords[++i]) {
		if (strncmp(str, keyword, str_len) == 0) {
			printf("Keyword\n");
			return 0;
		}
	}

	// Check if there is any special character in the string.
	for (char *current = str; *current != '\0'; current++) {
		if (!isalnum(*current) && *current != '_') {
			printf("Invalid identifier\n");
			return 0;
		}
	}

	printf("Valid identifier\n");
}
