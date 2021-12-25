#include <iostream>
using namespace std;

void fillarr(int& sizearr, int** arr)			// ���������� ���������� ������� � ����������
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

void showarr(int& sizearr, int** arr)			// ����� ���������� ������� �� �������
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

double sum1(int& sizearr, int* arr)				// ����� �������� ��������������� � ���������� �������
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

	// �������� �������, ����������, �����

	int n = 4;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}

	cout << "������� ������ �������: " << endl;

	fillarr(n, a);

	cout << "������:" << endl;
	
	showarr(n, a);

	// �������� ������ ������� �� �������� ��������� ������ �����, �����

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

	cout << "����� ������:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << anew[i] << "\t";
	}

	// ����� �������� ��������������� 

	cout << endl << "������� �������������� ��������� �������: " << sum1(size, anew) << endl;

	// ������� ������

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	delete[] anew;

	return 0;
}