/*
주어진 메모리 제한이 작음 -> 32MB
배열로 퍼즐의 모든 상태를 저장하기에는 부족
퍼즐을 배열이 아닌 정수형태로 만들어서 map으로 퍼즐의 최소 이동횟수 세기
-> 퍼즐의 상태를 정점으로 하는 bfs

퍼즐을
1 2 3
4 5 6
7 8
상태로 만드는 최소 이동횟수
*/

#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	int temp = 0; //퍼즐을 정수형태로 만들기
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int x;
			cin >> x;
			if (x == 0) {
				temp = temp * 10 + 9;
			}
			else {
				temp = temp * 10 + x;
			}
		}
	}

	map<int, int> d;
	queue<int> q;
	d[temp] = 0;
	q.push(temp);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		//빈 칸을 인접한 칸과 바꿔봄
		string nowStr = to_string(now);
		int index = nowStr.find('9'); //빈 칸의 위치 찾고
		int x = index / 3;
		int y = index % 3; //퍼즐에서의 위치 복원

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) { //인접한 칸이 퍼즐의 범위안에 있는지
				//일단 next를 만들어보고 만들어본 상태가 아니면 큐에 넣고 이동횟수 증가
				string nextStr = nowStr;
				swap(nextStr[x * 3 + y], nextStr[nx * 3 + ny]); //빈칸과 교환
				
				int next = stoi(nextStr);
				if (d.count(next) == 0) {
					d[next] = d[now] + 1;
					q.push(next);
				}
			}
		}
	}

	if (d.count(123456789) == 0) { //퍼즐을 맞출수 없는 경우
		cout << -1 << '\n';
	}
	else {
		cout << d[123456789] << '\n';
	}

	return 0;
}