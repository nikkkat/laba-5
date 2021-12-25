#include <iostream>
#include "..\staticlib\Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	
	// ���� �������� ��������, �������� ��������

	cout << "������� ���������� ����� � �������� �������:" << endl << "n: ";
	int n, m;
	cin >> n;
	cout << "m: ";
	cin >> m;

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}

	int* s = new int[m];

	// ���� ��������� ���������� �������, ����� �������

	cout << endl << "������� ������� �������:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int aa;
			cin >> aa;
			a[i][j] = aa;
		}
	}

	cout << endl << "������� �:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	// ���������� ������� S ������� ��������� ������� �, ����� ������� S

	fillarr(a, s, n, m);

	cout << endl << "���������� ������ S:" << endl;
	for (int j = 0; j < m; j++)
	{
		cout << s[j] << "\t";
	}

	// ����� � ����� ����������� �������� ����� ������� S

	cout << endl << endl << "���������� ������� ������� S: " << minimal(s, m) << endl;

	// ������� ������

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	delete[] s;

	return 0;
}