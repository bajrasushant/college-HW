#include <stdio.h>
#include <string.h>
#define MAX 100

void
prefixes(char *str, int str_len)
{
	printf("prefixes:\n");

	char prefix_str[str_len + 1];
	for (int i = 0; i < str_len; i++) {
		prefix_str[i]     = str[i];
		prefix_str[i + 1] = '\0';
		printf("%s\n", prefix_str);
	}
}

void
suffixes(char *str, int str_len)
{
	printf("suffixes:\n");

	char suffix_str[str_len + 1];
	suffix_str[str_len + 1] = '\0';
	for (int i = str_len - 1; i >= 0; i--) {
		suffix_str[i] = str[i];
		printf("%s\n", suffix_str + i);
	}
}

void
substrings(char *str, int str_len)
{
	printf("substrings:\n");

	char sub_str[str_len + 1];

	for (int i = 0; i < str_len; i++) {
		for (int j = i; j < str_len; j++) {
			strncpy(sub_str, str + i, (j - i) + 1);
			sub_str[(j - i) + 1] = '\0';
			printf("%s\n", sub_str);
		}
	}
}

int
main(void)
{
	printf("Enter a string: ");
	char str[MAX];
	scanf("%s", str);
	int str_len = strlen(str);

	prefixes(str, str_len);
	printf("\n");
	suffixes(str, str_len);
	printf("\n");
	substrings(str, str_len);
}
