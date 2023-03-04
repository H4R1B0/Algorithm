#include <iostream>
#include <cmath>
using namespace std;
int p(int n)
{
	if (n < 0)
		return n*(-1);
	return n;
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		double  x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double d = sqrt(pow((x2 - x1),2.0) + pow((y2 - y1),2.0));

		if (d == 0)
		{
			if (r1 == r2)
				cout << -1 << endl;
			else
				cout << 0 << endl;
		}
		else
		{
			if (p(r1 - r2) < d&&d < (r1 + r2))
				cout << 2 << endl;
			else if (d == p(r1 - r2) || d == (r1 + r2))
				cout << 1 << endl;
			else if (d>(r1 + r2) || d < p(r1 - r2))
				cout << 0 << endl;
		}
	}
}