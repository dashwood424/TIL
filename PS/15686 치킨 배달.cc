#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[50][50];

int main() {
	int n, m; //m: 폐업시키지 않을 치킨집의 개수
	cin >> n >> m;
	vector<pair<int, int>> house; //집
	vector<pair<int, int>> chicken; //치킨집
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (a[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	vector<int> d(chicken.size(), 0);
	for (int i = 0; i < m; i++) {
		d[i] = 1; //폐업시키지 않을 치킨 집의 수 만큼 1
	}
	sort(d.begin(), d.end());

	int ans = -1;

	do {
		vector<int> res;
		for (auto x : house) { //각 집마다
			vector<int> dists; //x번째 집에서 폐업시키지 않을 치킨집 까지의 거리
			for (int i = 0; i < chicken.size(); i++) {
				if (d[i] == 1) { //폐업시키지 않을 치킨집이라면
					int r = x.first - chicken[i].first;
					int c = x.second - chicken[i].second;
					if (r < 0) r = -r;
					if (c < 0) c = -c;
					int dist = r + c; 
					dists.push_back(dist);
				}
			}
			res.push_back(*min_element(dists.begin(), dists.end())); //각 집에서 폐업시키지 않을 치킨집까지 거리 중 가장 짧은 거리
		}

		int temp = 0;

		for (int i = 0; i < res.size(); i++) { //도시의 치킨거리 구하기
			temp += res[i];
		}
		if (ans == -1 || ans > temp) {
			ans = temp;
		}
	} while (next_permutation(d.begin(), d.end()));

	cout << ans << '\n';

	return 0;
}