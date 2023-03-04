#include <iostream>
#include <algorithm>
using namespace std;
#include <cmath>
//int map[1001][1001];
int map2[10000001];
int main() {
	int n;
	//int Max = -1;
	int cnt = 0, num, idx = 0;
	long long total = 0, sum = 0;
	int x;
	cin >> n;
	num = (int)pow((double)n, 2);
	for (int i = 0; i < num; i++) {
		cin >> x;
		//x = 10000000;
		total += x;
		map2[x]++;
		//Max = max(Max, map[i][j]);
	}
	//printf("%d\n", num);
	//for (i = 0; i < num; i++)
		//printf("%d ", map2[i]);
	//cout << endl;
	//int num2 = num;
	if (map2[0] == num) {
		//cout << map2[0] << num << endl;
		cout << "0";
		return 0;
	}
	while (1) {

		if ((double)sum*100 / (double)total>=50) {
			//printf("%f %lld\n", (double)sum * 100 / (double)total,total);
			cout << cnt;
			break;
		}
		num -= map2[idx++];
		sum += num;
		//printf("%d %d\n",cnt, sum);
		cnt++;
	}
}