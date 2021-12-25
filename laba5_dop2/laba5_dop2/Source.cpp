#include <iostream>
using namespace std;

void fillarr(int& size, double** arr)		// ���������� ���������� ������� ������������� ����������
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = (double)(rand() % 100) / 10;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void backarr(int& size, double** arr)		// ����� ���������� ������� � �������� �������
{
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = size - 1; j >= 0; j--)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int n = 5;
	
	// �������� �������

	double** a = new double* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}

	// ���������� � �����

	cout << "������:" << endl;
	
	fillarr(n, a);

	// ����� ������� ��������� � �� ����������
	
	cout << endl << "������� ��������:" << endl;
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
			{
				cout << "�������: " << i << "\t" << j << endl;
				z++;
			}
		}
	}
	cout << "����������: " << z << endl;

	// �������� ������� � �������� �������

	cout << endl << "�������� ������� � �������� �������:" << endl;
	
	backarr(n, a);

	// ������� ������

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}