/*Игра про камни,есть два вида хода, убрать один камень или два рядом стоящие*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int N = 25;
int arr[25];
int massiv(int a[]);
int bot();
int massiv2();
int homo();
int proverka(int *prov);
int main()
{
	int i;
	for (i = 0; i < N; i++)
		arr[i] = 1;

	do
	{
			massiv2();
			printf("\n");
			massiv(arr);
			printf("\n");
			homo();
			if (proverka(arr) == 0)
			{
				printf("win player");
				break;
			}

			bot();
			if (proverka(arr) == 0)
			{
				printf("win bot");
				break;
			}

	} while (true);

	return 0;
}
int massiv(int a[])
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%3d", a[i]);
	}
	return 0;
}
int homo()
{
	int k, k1, k2;
	printf("how many stones will you clean up?\n");
	scanf("%d", &k);
	switch (k)
	{
	case 1:
		scanf("%d", &k1);
		arr[k1] = 0;
		break;
	case 2:
		scanf("%d%d", &k1, &k2);
		arr[k1] = 0;
		arr[k2] = 0;
		break;
	}
	return 0;
}
int massiv2()
{
	int i;
	int a[25];
	for (i = 0; i < N; i++)
	a[i] = i;
	for (i = 0; i < N; i++)
		printf("%3d", a[i]);
	return 0;
}
int bot()
{
	int i,n,k,k1,k2;
	int counter = 0;
	n = rand() % 2 + 1;
	for (i = 0; i < N-1; i++)
	{
		if (arr[i] + arr[i + 1] > 1)
			counter++;
	}

	if (counter == 0)
		n = 1;
	if (n == 1)
	{
		do
		{
			k = rand() % 26;
		} while (arr[k] == 0);
		arr[k] = 0;
	}
	else
	{
		do
		{
			k1 = rand() % 25;
			k2 = k1 + 1;
		} while (arr[k1] == 0 ||arr[k2]==0);
		arr[k1] = 0;
		arr[k2] = 0;
	}

	return 0;
}
int proverka(int *prov)
{
	bool k;
	int i;
	for (i = 0; i < N; i++)
	{
		if (prov[i] == 0)
		{
			k = true;
		}
		else
		{
			k = false;
			break;
		}
	}
	if (k == false)
		return 1;
	else
		return 0;
}
