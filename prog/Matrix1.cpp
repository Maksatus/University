#include "pch.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void OutputMatrix(int **a,int row,int colum) {
	cout << endl<<endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < colum; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
		
}

void clean(int **a,int row) {
	for (int i = 0; i < row; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}

void OutputMatrixSpiral(int **arr, int row, int colum) {
	
	
}

//Рекурсия,поиск чила
bool func(int** arr, int height, int length, int s, int elem)
{
	for (int i = 0; i < length; ++i) {
		if (elem < arr[s][i])
			return false; 
		else if (elem == arr[s][i]) { 
			if ((s + 1) == height) 
				return true;
			else 
				return func(arr, height, length, s + 1, elem); 
		}
	}
	return false; 
}

void findnumber(int **a, int row, int colum) {
	int i = 0;
	
	while ((i < colum) && (!func(a, row, colum, 1, a[0][i]))) ++i;
	if (i == colum) cout << "NO" << endl;
	else cout << a[0][i] << endl;
}
	//end


void Swith(int k,int **a,int row,int colum) {
	switch (k)
	{
	case 1:
		OutputMatrixSpiral(a,row,colum);
		break;
	case 2:
		findnumber(a,row,colum);
		break;
	case 3:
		OutputMatrix(a, row, colum);
		break;
	default:
		
		break;
	}
 }

int main()
{
	setlocale(LC_ALL, "Russian");
	int str, stb, i,j;
	cout << "Matrix size"<<endl;
	cin >> str >> stb;
	
	int **a = new int*[str];
	for (i = 0; i < str; i++) a[i] = new int[stb];
	cout << "Fill in the matrix" << endl;
	
	for (i = 0; i < str; i++)
		for (j = 0; j < stb; j++)
			cin >> a[i][j];
	
	
     int k;
	do
	{
		cout << "Выберите функцию: " << endl << "   1)Вывод матрицы по спирали" << endl << "   2)Числа матрицы,которые встречаются... " << endl << "   3)Вывод стандартной матрицы" << endl<< "   4)Exit"<<endl;
		cin >> k;
		Swith(k,a, str, stb);
	} while (k<4);
	clean(a, str);
}
