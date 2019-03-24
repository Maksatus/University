/*Нахождение суммы,минимального элемента в каждой строке и  меняем первую строку с последней */


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

int sum(int **a, int row, int colum)
{
	int i, j, s = 0;
	for (i = 0; i < row; i++)
	{
		for (j=0;j<colum;j++)
		{
			s += a[i][j];
		}
	}
	return printf("sum-%d\n",s);
}
void min(int **a, int row, int colum)
{
	int i, j, min;
	for (i = 0; i < row; i++)
	{
		min =100;
		for (j = 0; j < colum; j++)
		{
			if (a[i][j]<min)
				min = a[i][j];
		}
		printf("min %d)%3d\n",i,min);
	}
}
void swap(int **a, int row, int colum)
{
	int j,tmp;
		for (j = 0; j < colum; j++)
		{
			tmp = a[0][j];
			a[0][j] = a[row-1][j];
			a[row-1][j] = tmp;
		}
	  output(a,row,colum);
}
void swit(int n, int **arr,int row,int colum)
{
     switch (n)
	 {
		case 1:
			sum(arr,row,colum);
			break;
		case 2:
			min(arr, row, colum);
			break;
		case 3:
			swap(arr, row, colum);
			break;

	 }

}
int main()
{
	int lines, stolb; int **arr;
	int n;
	printf("enter the size of the matrix: ");
	scanf("%d%d", &lines, &stolb);
	arr = fill(lines, stolb);
	output(arr, lines, stolb);
	printf("Enter transaction number:\n 1)sum\n 2)minimal elements in the rows\n 3)swap first and last line\n 4)exit\n");
	do
	{
		scanf("%d", &n);
		swit(n, arr,lines,stolb);
	} while (n<=3);
	clear(arr,lines);
	return 0;
}
