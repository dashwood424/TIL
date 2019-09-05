#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calc(vector<int> &a, vector<int> &b) {
	int n = a.size();
	int ans = a[0];
	for (int i = 0; i < n - 1; i++) {
		if (b[i] == 0) {
			ans += a[i + 1];
		}
		else if (b[i] == 1) {
			ans -= a[i + 1];
		}
		else if (b[i] == 2) {
			ans *= a[i + 1];
		}
		else if (b[i] == 3) {
			ans /= a[i + 1];
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n); //피연산자
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> b; //연산자가 무엇인지 0:+, 1:-, 2:*, 3:/
	for (int i = 0; i < 4; i++) {
		int cnt;
		cin >> cnt; //각 연산자의 개수
		for (int j = 0; j < cnt; j++) {
			b.push_back(i);
		}
	}

	sort(b.begin(), b.end());
	vector<int> result; //모든 가능한 연산결과 저장
	
	do {
		int temp = calc(a, b);
		result.push_back(temp);
	} while (next_permutation(b.begin(), b.end()));

	auto ans = minmax_element(result.begin(), result.end());

	cout << *ans.second << '\n';
	cout << *ans.first << '\n';
	return 0;
}