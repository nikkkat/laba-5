#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

int main()
{
	// ����������� ������������ ����������

	HINSTANCE load;
	load = LoadLibrary(L"dynamic.dll");
	typedef bool (*foo) (double);
	foo Func;
	Func = (foo)GetProcAddress(load, "Func");

	setlocale(LC_ALL, "ru");

	// ���������� �������

	int n;
	cout << "������� ���������� ��������� � �������: ";
	cin >> n;

	int* arr = new int[n];
	cout << endl << "������� ������� �������:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// �������� �������, ��� ������ ������� ����� �������� �������� �������� � ����� �� ������� � ����������� �������

	double* acos = new double[n];
	cout << endl << "������ ���������:" << endl;
	for (int i = 0; i < n; i++)
	{
		acos[i] = cos(arr[i]);
		cout << acos[i] << "\t";
	}

	// �������� � ������� ������� �������� ���������

	for (int i = 0; i < n; i++)
	{
		arr[i] = Func(acos[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0) { cout << endl << endl << "������� ����������� �� ��� ���� ���������" << endl; 
		delete[] acos;
		delete[] arr;
		FreeLibrary(load);
		return 0; }
	}

	cout << endl << endl << "������� ����������� ��� ���� ���������" << endl;

	delete[] acos;
	delete[] arr;
	FreeLibrary(load);

	return 0;
}