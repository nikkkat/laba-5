#include <iostream>
using namespace std;

int foo(int i)										// ����������� �������
{
	if (i % 10 > 0) { return i % 10; }
	else if (i == 0) { return 0; }
	else { foo(i / 10); }
}

int main()
{
	setlocale(LC_ALL, "ru");

	// ����, �������� �� ����������������� ������

	cout << "������� p � q:" << endl;
	int p, q, f, s = 0;
	cin >> p >> q;

	if (p < 0 || q < 0) { return 0; }

	// ���� ����� �������, ����� ����������

	for (int i = p; i < q + 1; i++)
	{
		s += foo(i);
	}

	cout << endl << "���������: " << s << endl;

	return 0;
}