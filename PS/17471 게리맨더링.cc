#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int people[11]; //각 도시의 인구수
bool check[11][11]; //인접 행렬
bool c[11]; //dfs 방문 체크
int a[11]; //선택한 도시
int n;

bool bfs(vector<int> v) { //정점 번호를 받고 정점들을 모두 방문할 수 있으면 true
	memset(c, false, sizeof(c));
	
	c[v[0]] = true;
	queue<int> q;
	q.push(v[0]);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v.size(); i++) {
			if (check[x][v[i]] == true && c[v[i]] == false) {
				c[v[i]] = true;
				q.push(v[i]);
			}
		}
	}

	bool ok = true;

	for (int i = 0; i < v.size(); i++) {
		if (c[v[i]] == false) {
			ok = false;
		}
	}
	return ok;
}

int go(int index, vector<int> first, vector<int> second) { //도시를 선택하는 경우
	if (index == n + 1) {
		if (first.size() == 0) return -1;
		if (second.size() == 0) return -1;

		int one = 0; //1번 선거구의 인구 수
		int two = 0; //2번 선거구의 인구 수

		if (bfs(first) && bfs(second)) {
			for (int i = 0; i < first.size(); i++) {
				one += people[first[i]];
			}

			for (int i = 0; i < second.size(); i++) {
				two += people[second[i]];
			}
		}

		if (one != 0 && two != 0) {
			int diff = one - two;
			if (diff < 0) diff = -diff;
			return diff;
		}
		else {
			return -1;
		}
	}

	int ans = -1; //인구 차이의 최솟값
	
	first.push_back(index);
	int temp = go(index + 1, first, second);
	if (temp != -1 && (ans == -1 || ans > temp)) {
		ans = temp;
	}
	first.pop_back();

	second.push_back(index);
	temp = go(index + 1, first, second);
	if (temp != -1 && (ans == -1 || ans > temp)) {
		ans = temp;
	}
	second.pop_back();

	return ans;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
	}

	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			check[i][x] = true;
		}
	}

	vector<int> first, second;
	cout << go(1, first, second) << '\n';	
	
	return 0;
}