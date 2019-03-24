#include "pch.h"
#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL,"Russian");
	int a[32] = { 0 };
	int i, e = 0, sum = 0;
	string line, l = " ";
	char k = ' ';
	
	ifstream in("read.txt");
	
	if (in.is_open())
		while (getline(in,line))
		{
			l += line;
		}

	in.close();
	
	cout << l << endl;
	for (i = 0; l[i] != '\0'; i++)
	{
		k = tolower(l[i]);
		if (k >= 'а' && k <= 'я')
		{
			a[(int)k + 32] += 1;
			sum++;
		}
		if (k == (char)-72)
		{
			e++;
		  }
	}

	for (i = 0; i < 32; i++) {
		cout << (char)(i - 32) << " " << a[i] << endl;
	}
	cout << "ё "<< e<<endl;
	cout << "Сумма: " << sum;
	return 0;
}
