#include <iostream>
using namespace std;

void fillarr(int& rows, int& cols, int** arr) // ������� ��� ��������� ���������� ������� � ����������
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int aa;
			cin >> aa;
			arr[i][j] = aa;
		}
	}
}

void showarr(int& rows, int& cols, int** arr) // ������� ��� ������ ���������� ������� �� �������
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	// �������� �������

	int rows = 1, cols = 1;
	cout << "������� ����� �����: ";
	cin >> rows;
	cout << "������� ����� ��������: ";
	cin >> cols;

	int** a = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		a[i] = new int[cols];
	}

	// ���������� � ���������� � ����� �� ������� �������

	cout << "������� �������� �������:" << endl;
	
	fillarr(rows, cols, a);

	cout << "������:" << endl;
	
	showarr(rows, cols, a);
	
	// �������� � ���������� ������ �������, ��� ������ ������ �������� �� ������� ��������� ���������

	int size = rows;
	if (rows < cols) { size = rows; }
	else { size = cols; }
	int* anew = new int[size];
	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j)
			{
				if (a[i][j] % 2 == 0)
				{
					anew[k] = a[i][j];
					k++;
				}
				else { size--; }
			}
		}
	}

	// ����� ������ �������

	cout << endl << "�������� ������:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << anew[i] << "\t";
	}
	cout << endl;

	// ������� ������

	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	delete[] anew;

	return 0;
}