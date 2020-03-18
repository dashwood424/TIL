#include <iostream>
using namespace std;


int go(int sum, int goal) {
	if (sum == goal) {
		return 1;
	} 
	if (sum > goal) {
		return 0;
	}
	int ans = 0;

	for (int i = 1; i <= 3; i++) {
		ans += go(sum + i, goal);
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << go(0, n) << '\n';
	}

	return 0;
}