#include <iostream>
#include <cmath>
using namespace std;

int foo(int n, int r, int k)
{
	if (n > 0 && (r >= 0) && (r < (n * (k - 1) + 1)))
	{
		int res = 0;
		for (int i = 0; i <= k - 1; i++)
		{
			res += foo(n - 1, r - i, k);
		}
		return res;
	}
	else if (n == 0 && r == 0) { return 1; }
	else { return 0; }
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "������� k, n, t:" << endl;
	int k, n, t, x;
	cin >> k >> n >> t;

	if (k == 0 && n == 0 && t == 0) { return 0; }

	int s = 0;
	for (int i = 0; i <= n * (k - 1); i++)
	{
		s += foo(n, i, k);
	}

	int m = pow(10, t);
	x = s % m;

	cout << "case# : " << x << endl;
	
	return 0;
}