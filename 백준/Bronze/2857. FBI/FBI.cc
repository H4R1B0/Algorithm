#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };




int main(void)
{
	string str;
	vector<int> result;
	for (int i = 0;i < 5;i++) {
		cin >> str;
		for (int j = 0;j < str.size();j++) {
			if (str[j] == 'F' && str[j + 1] == 'B' && str[j + 2] == 'I') {
				result.push_back(i + 1);
				break;
			}
		}
	}
	if(result.size() == 0)
		cout << "HE GOT AWAY!" << endl;
	else {
		for (int i = 0;i < result.size();i++) {
			cout << result[i] << ' ';
		}
	}
}