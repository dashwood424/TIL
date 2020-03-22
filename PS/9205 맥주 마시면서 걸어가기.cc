#include <iostream>
#include <vector>
using namespace std;

bool check[102]; //정점의 개수
vector<int> v[102]; //정점 i에서 갈 수 있는 정점

void dfs(int node) {
	check[node] = true;

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

bool can(int x1, int y1, int x2, int y2) {
	int x = x1 - x2;
	int y = y1 - y2;
	if (x < 0) x = -x;
	if (y < 0) y = -y;
	int dist = x + y;

	return dist <= 1000 ? true : false;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		for (int i = 0; i < 102; i++) { //초기화
			check[i] = false;
			v[i].clear();
		}

		vector<pair<int, int>> node; //정점의 위치
		for (int i = 0; i < n + 2; i++) {
			int x, y;
			cin >> x >> y;
			node.push_back(make_pair(x, y));
		}

		for (int i = 0; i < n + 2; i++) {
			for (int j = i + 1; j < n + 2; j++) {
				if (can(node[i].first, node[i].second, node[j].first, node[j].second)) { //정점 i에서 j로 갈 수 있는지
					//정점의 좌표 거리가 1000미터 이하이면 갈 수 있음
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}

		dfs(0);

		if (check[n + 1]) {
			cout << "happy" << '\n';
		}
		else {
			cout << "sad" << '\n';
		}
	}

	return 0;
}