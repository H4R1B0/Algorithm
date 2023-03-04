#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 10
#define endl '\n'

int xd[] = { 0,1,0,-1 };
int yd[] = { -1,0,1,0 };

int N;
int MAP[MAX][MAX];
int kx, ky, sx, sy;

bool move(string s) {
	int nkx=kx, nky=ky, nsx=sx, nsy=sy;
	if (s == "R") {
		nkx = kx + xd[2];
		nky = ky + yd[2];
		if (nkx < 0 || nkx >= 8 || nky < 0 || nky >= 8)
			return false;
		if (nkx == sx && nky == sy) {
			nsx = sx + xd[2];
			nsy = sy + yd[2];
			if (nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8)
				return false;
		}		
	}
	else if (s == "L") {
		nkx = kx + xd[0];
		nky = ky + yd[0];
		if (nkx < 0 || nkx >= 8 || nky < 0 || nky >= 8)
			return false;
		if (nkx == sx && nky == sy) {
			nsx = sx + xd[0];
			nsy = sy + yd[0];
			if (nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8)
				return false;
		}
	}
	else if (s == "B") {
		nkx = kx + xd[1];
		nky = ky + yd[1];
		if (nkx < 0 || nkx >= 8 || nky < 0 || nky >= 8)
			return false;
		if (nkx == sx && nky == sy) {
			nsx = sx + xd[1];
			nsy = sy + yd[1];
			if (nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8)
				return false;
		}
	}
	else if (s == "T") {
		nkx = kx + xd[3];
		nky = ky + yd[3];
		if (nkx < 0 || nkx >= 8 || nky < 0 || nky >= 8)
			return false;
		if (nkx == sx && nky == sy) {
			nsx = sx + xd[3];
			nsy = sy + yd[3];
			if (nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8)
				return false;
		}
	}
	else if (s == "RT") {
		nkx = kx + xd[2] + xd[3];
		nky = ky + yd[2] + yd[3];
		if (nkx < 0 || nkx >= 8 || nky < 0 || nky >= 8)
			return false;
		if (nkx == sx && nky == sy) {
			nsx = sx + xd[2] + xd[3];
			nsy = sy + yd[2] + yd[3];
			if (nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8)
				return false;
		}
	}
	else if (s == "LT") {
		nkx = kx + xd[0] + xd[3];
		nky = ky + yd[0] + yd[3];
		if (nkx < 0 || nkx >= 8 || nky < 0 || nky >= 8)
			return false;
		if (nkx == sx && nky == sy) {
			nsx = sx + xd[0] + xd[3];
			nsy = sy + yd[0] + yd[3];
			if (nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8)
				return false;
		}
	}
	else if (s == "RB") {
		nkx = kx + xd[2] + xd[1];
		nky = ky + yd[2] + yd[1];
		if (nkx < 0 || nkx >= 8 || nky < 0 || nky >= 8)
			return false;
		if (nkx == sx && nky == sy) {
			nsx = sx + xd[2] + xd[1];
			nsy = sy + yd[2] + yd[1];
			if (nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8)
				return false;
		}
	}
	else if (s == "LB") {
		nkx = kx + xd[0] + xd[1];
		nky = ky + yd[0] + yd[1];
		if (nkx < 0 || nkx >= 8 || nky < 0 || nky >= 8)
			return false;
		if (nkx == sx && nky == sy) {
			nsx = sx + xd[0] + xd[1];
			nsy = sy + yd[0] + yd[1];
			if (nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8)
				return false;
		}
	}
	kx = nkx, ky = nky, sx = nsx, sy = nsy;
	return true;
}

int main(void) {
	string king, stone;
	cin >> king >> stone >> N;
	ky = king[0] - 'A';
	kx = 8 - (king[1] - '0');
	sy = stone[0] - 'A';
	sx = 8 - (stone[1] - '0');
	while (N--) {
		string s;
		cin >> s;
		move(s);
	}
	cout << (char)('A' + ky) << (8 - kx) << endl;
	cout << (char)('A' + sy) << (8 - sx) << endl;
}