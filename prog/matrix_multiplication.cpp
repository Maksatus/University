#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int **fill(int row, int column)
{
	int i, j;
	int **a = (int**)malloc(sizeof(int*)*row);
	for (i = 0; i < row; i++)
		a[i] = (int*)malloc(sizeof(int)*column);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
	return a;
}
void clear(int **a, int row)
{
	int i;
	for (i = 0; i < row; i++)
		free(a[i]);
	free(a);
}
void output(int **a, int row, int column)
{
	int j, i;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void output2(int **a, int row, int column)
{
	int j, i;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void multiplied(int **arr1, int **arr2, int row,int colum2)
{
	int i, j, k;
	int **mul = (int**)malloc(row * sizeof(int*));
	for (i = 0; i < row; i++)
		mul[i] = (int*)malloc(colum2 * sizeof(int));
	for (i = 0; i < row; i++)
		for (j = 0; j < row; j++)
		{
			mul[i][j] = 0;
			for (k = 0; k < row; k++)
				mul[i][j] += arr1[i][k] * arr2[k][j];
		}
	output2(mul,row,colum2);
}

int main()
{
	int lines, stolb, lines1, stolb1, i;
	int **arr2; int **arr1;
	printf("enter the size of the matrix №1: ");
	scanf("%d%d", &lines, &stolb);
	printf("enter the size of the matrix №2: ");
	scanf("%d%d", &lines1, &stolb1);
	arr1 = fill(lines, stolb);
	arr2 = fill(lines1, stolb1);
	output(arr1, lines, stolb);
	output(arr2, lines1, stolb1);
	if (stolb == lines1)
	{
		printf("Сonclusion:\n");
		multiplied(arr1, arr2, lines, stolb1);
	}
	else
		for (i = 0;;i++)
		printf("ERROR");
	clear(arr1, lines);
	clear(arr2, lines1);
	return 0;
}

