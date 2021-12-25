#include <iostream>
using namespace std;

void fillarr(int& sizearr, int** arr)			// заполнение двумерного массива с клавиатуры
{
	for (int i = 0; i < sizearr; i++)
	{
		for (int j = 0; j < sizearr; j++)
		{
			int aa;
			cin >> aa;
			arr[i][j] = aa;
		}
	}
}

void showarr(int& sizearr, int** arr)			// вывод двумерного массива на консоль
{
	for (int i = 0; i < sizearr; i++)
	{
		for (int j = 0; j < sizearr; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

double sum1(int& sizearr, int* arr)				// поиск среднего арифметического в одномерном массиве
{
	int sum = 0;
	for (int i = 0; i < sizearr; i++)
	{
		sum += arr[i];
	}

	return (double)sum / sizearr;
}

int main()
{
	setlocale(LC_ALL, "ru");

	// создание массива, заполнение, вывод

	int n = 4;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}

	cout << "введите данные массива: " << endl;

	fillarr(n, a);

	cout << "массив:" << endl;
	
	showarr(n, a);

	// создание нового массива из нечетных элементов четных строк, вывод

	int size = 0, k = 0;
	if (n % 2 == 0) { size = n * n / 2; }
	else { size = n*n / 2 + n; } 
	int* anew = new int[size];
	for (int j = 0; j < n; j++)
	{
		if (j % 2 != 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (a[i][j] % 2 != 0)
				{
					anew[k] = a[i][j];
					k++;
				}
				else { size--; }
			}
		}
	}

	cout << "новый массив:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << anew[i] << "\t";
	}

	// поиск среднего арифметического 

	cout << endl << "среднее арифметическое итогового массива: " << sum1(size, anew) << endl;

	// очистка памяти

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	delete[] anew;

	return 0;
}