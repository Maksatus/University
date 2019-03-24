#include <stdio.h>

void stringa()
{
	int str, ns = 0;
	int flag = 1;
	printf("Enter string:\n");

	while (flag == 1)
	{
		str = getchar();
		(str != ' ') ? ns = 0 : ++ns;
		if (ns <= 1)
			printf("%c", str);
		if (str == '\n')
			flag = 0;

	}
	printf("\n");
}

void count() {
	char str[255];
	int count = 0; int i;
	gets(str);

	for (i = 1; i < 255; i++)
	{
		if ((str[i] == ' ') && (str[i - 1] != ' '))
			count++;
	}
	printf("%d\n",count);

}
void swit(int n)
{
	switch (n)
	{
	case 1:
		stringa();
		break;
	case 2:
		count();
		break;
	}
}


int main()
{
	int n;
	printf("Enter function: \n1)Delition space\n2)Count word\n3)Exit\n");
	do
	{
		scanf("%d", &n);
		swit(n);
	} while (n<=2);

return 0;
}

