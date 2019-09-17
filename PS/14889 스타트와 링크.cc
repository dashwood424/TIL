#include <iostream>
#include <vector>
using namespace std;

int s[20][20]; //각 팀의 능력치
int n;
int go(int index, vector<int> first, vector<int> second) {
	if (index == n) { //n번째 사람까지 팀을 정했으면
		if (first.size() != n / 2) return -1;
		if (second.size() != n / 2) return -1;

		int one = 0; //first의 점수의 합
		for (int i = 0; i < first.size(); i++) {
			for (int j = 0; j < first.size(); j++) {
				if (i == j) continue;
				one += s[first[i]][first[j]];
			}
		}

		int two = 0;
		for (int i = 0; i < second.size(); i++) {
			for (int j = 0; j < second.size(); j++) {
				if (i == j) continue;
				two += s[second[i]][second[j]];
			}
		}

		int diff = one - two;
		if (diff < 0) {
			diff = -diff;
		}
		return diff;
	}
	
	int ans = -1;
	first.push_back(index); //index번째 사람이 first인 경우
	int temp = go(index + 1, first, second);
	if (ans == -1 || temp != -1 && ans > temp) {
		ans = temp;
	}
	first.pop_back();

	second.push_back(index); //index번째 사람이 second인 경우
	temp = go(index + 1, first, second);
	if (ans == -1 || temp != -1 && ans > temp) {
		ans = temp;
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

	vector<int> first, second;
	
	cout << go(0, first, second) << '\n';
	return 0;
}