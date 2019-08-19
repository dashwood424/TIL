#include <iostream>
#include <vector>
using namespace std;

int s[20][20];
int n;
int go(int index, vector<int> &first, vector<int> &second) {
	if (index == n) {
		if (first.size() == 0) return -1; //팀에 사람이 한명도 없으면, 인원수가 같지 않아도 됨
		if (second.size() == 0) return -1;

		int t1 = 0, t2 = 0;
		for (int i = 0; i < first.size(); i++) {
			for (int j = 0; j < first.size(); j++) {
				if (i == j) continue;
				t1 += s[first[i]][first[j]];
			}
		}

		for (int i = 0; i < second.size(); i++) {
			for (int j = 0; j < second.size(); j++) {
				if (i == j) continue;
				t2 += s[second[i]][second[j]];
			}
		}

		int diff = t1 - t2;
		if (diff < 0)  diff = -diff;
		return diff;
	}

	int ans = -1; //두 팀의 능력치 차이의 최소값
	
	first.push_back(index); //index번째 사람을 first에 넣어봄
	int t1 = go(index + 1, first, second);
	if (ans == -1 || t1 != -1 && (t1 < ans)) {
		ans = t1;
	}
	first.pop_back();

	second.push_back(index);
	int t2 = go(index + 1, first, second);
	if (ans == -1 || t2 != -1 && (t2 < ans)) {
		ans = t2;
	}
	second.pop_back();

	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	vector<int> first, second; //first or second에 들어가는 index번째 사람 
	
	cout << go(0, first, second) << '\n';
	return 0;
}