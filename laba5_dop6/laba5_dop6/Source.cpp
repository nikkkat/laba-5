#include <iostream>
using namespace std;

int foo(int i)
{
	if (i % 2 != 0) { return i; }
	else { foo(i / 2); }
}

int main()
{
	setlocale(LC_ALL, "ru");

	int n;
	cout << "������� ����������� ����� n: ";
	cin >> n;

	if (n <= 0) { return 0; }

	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		s += foo(i);
	}

	cout << endl << "���������: " << s << endl;

	return 0;
}