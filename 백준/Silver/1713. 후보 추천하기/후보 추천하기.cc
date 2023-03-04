#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 2000
#define endl '\n'

int xd[] = { -1,-1,-1,0 };
int yd[] = { -1,0,1,1 };

int N, M;

struct STUDENT
{
	int num, cnt, order;
};
vector<STUDENT> Students;

bool cmp(STUDENT a, STUDENT b) {
	if (a.cnt == b.cnt)
		return a.order < b.order;
	return a.cnt < b.cnt;
}
bool cmp_ans(STUDENT a, STUDENT b) {
	return a.num < b.num;
}

int check(int num) {
	for (int i = 0;i < Students.size();i++) {
		if (Students[i].num == num) {
			return i;
		}
	}
	return -1;
}

int main(void) {
	cin >> N;
	cin >> M;
	for(int i=0;i<M;i++){
		int a;
		cin >> a;
		if (Students.size() < N) {
			int tmp = check(a);
			if (tmp != -1) {
				Students[tmp].cnt++;
			}
			else {
				Students.push_back({ a,1,i });
			}			
		}
		else {			
			int tmp = check(a);
			if (tmp != -1) {
				Students[tmp].cnt++;
			}
			else {
				sort(Students.begin(), Students.end(), cmp);
				Students[0] = { a,1,i };
			}
		}
	}
	sort(Students.begin(), Students.end(), cmp_ans);
	for (int i = 0;i < Students.size();i++) {
		cout << Students[i].num << " ";
	}
}