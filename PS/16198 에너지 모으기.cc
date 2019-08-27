#include <iostream>
#include <vector>
using namespace std;

int go(vector<int> &a) {
	int n = a.size(); //구슬을 1번부터 n번까지 다시 번호를 매김
	if (n == 2) return 0; //첫 번째와 마지막 구슬만 있는 경우

	int ans = 0; //모을 수 있는 에너지 양의 최대값
	 
	for (int i = 1; i < n - 1; i++) {
		int energy = a[i - 1] * a[i + 1]; 
		vector<int> b(a);
		b.erase(b.begin() + i); //i번째 에너지 구슬 제거
		energy += go(b);
		if (ans < energy) {
			ans = energy;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << go(a) << '\n';
	return 0;
}
