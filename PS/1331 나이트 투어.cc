#include <iostream>
#include <vector>
#include <string>
using namespace std;

int a[6][6];
int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[] = { -2, -1, 1, 2, 2, 1, -1,-2 };


int main() {
	string str;
	cin >> str;

	int x = str[0] - 'A';
	int y = str[1] - '1';
	
	int sx = x;
	int sy = y; //경로 시작점

	a[sx][sy] = 1;
	bool ok = false;

	for (int i = 0; i < 35; i++) {
		cin >> str;
		int nx = str[0] - 'A';
		int ny = str[1] - '1';

		ok = false;
		
		for (int k = 0; k < 8; k++) {
			if (x + dx[k] == nx && y + dy[k] == ny && a[nx][ny] == 0) { //경로 중간에 시작점을 방문하지 않음
				ok = true;
				a[nx][ny] = 1;
			}
		}
		x = nx;
		y = ny;

		if (ok == false) {
			cout << "Invalid" << '\n';
			return 0;
		}
	}

	bool back = false;

	if (ok) {
		for (int k = 0; k < 8; k++) {
			if (x + dx[k] == sx && y + dy[k] == sy) {
				back = true;
			}
		}
	}

	if (ok == true && back == true) {
		cout << "Valid" << '\n';
	}
	else {
		cout << "Invalid" << '\n';
	}

	return 0;
}