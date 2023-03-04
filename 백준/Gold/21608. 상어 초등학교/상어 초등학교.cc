#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 21
#define endl '\n'

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

struct STUDENT
{
	int num;
	int like[4];
};

struct POSITION
{
	int x, y, nearly_empty, nearly_friend;
};
STUDENT Student_Arr[MAX * MAX];
vector<STUDENT> Student;

int N;
int MAP[MAX][MAX];

bool cmp(POSITION a, POSITION b) {
	if (a.nearly_friend == b.nearly_friend) {
		if (a.nearly_empty == b.nearly_empty) {
			if (a.x == b.x) {
				return a.y < b.y;
			}
			return a.x < b.x;
		}
		return a.nearly_empty > b.nearly_empty;
	}
	return a.nearly_friend > b.nearly_friend;
}

void Set_position() {
	for (int i = 0;i < Student.size();i++) {
		vector<POSITION> pos;
		int student_num = Student[i].num;
		for (int x = 0;x < N;x++) {
			for (int y = 0;y < N;y++) {
				if (MAP[x][y] != 0)
					continue;
				int nearly_friend = 0;
				int nearly_empty = 0;
				for (int k = 0;k < 4;k++) {
					int nx = x + xd[k];
					int ny = y + yd[k];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N)
						continue;
					if (MAP[nx][ny] == 0)
						nearly_empty++;
					else {
						for (int j = 0;j < 4;j++) {
							int friend_num = Student[i].like[j];
							if (MAP[nx][ny] == friend_num) {
								nearly_friend++;
								break;
							}
						}
					}
				}
				pos.push_back({ x,y,nearly_empty,nearly_friend });
			}
		}
		sort(pos.begin(), pos.end(), cmp);
		MAP[pos[0].x][pos[0].y] = student_num;
	}
}

int Calculate(int F) {
	if (F == 0) return 0;
	if (F == 1) return 1;
	if (F == 2) return 10;
	if (F == 3) return 100;
	if (F == 4) return 1000;
}

int main(void) {
	cin >> N;
	int answer = 0;
	for (int i = 0;i < N * N;i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		Student.push_back({ a,{b,c,d,e} });
		Student_Arr[a].num = a;
		Student_Arr[a].like[0] = b;
		Student_Arr[a].like[1] = c;
		Student_Arr[a].like[2] = d;
		Student_Arr[a].like[3] = e;
	}
	Set_position();
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++)	{
			int student_num = MAP[i][j];
			int friend_cnt = 0;
			for (int k = 0; k < 4; k++)	{
				int nx = i + xd[k];
				int ny = j + yd[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;

				for (int l = 0; l < 4; l++)	{
					int friend_num = Student_Arr[student_num].like[l];
					if (MAP[nx][ny] == friend_num) {
						friend_cnt++;
						break;
					}
				}
			}
			answer += Calculate(friend_cnt);
		}
	}
	cout << answer;
}