#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<char> &a, vector<int> &num) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '<' && num[i] > num[i + 1]) {
			return false;
		}
		else if (a[i] == '>' && num[i] < num[i + 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	vector<char> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> small(n + 1);
	vector<int> big(n + 1);

	for (int i = 0; i < n + 1; i++) {
		small[i] = i;
		big[i] = 9 - i;
	}

	do {
		if (check(a, small)) { //부등호를 만족하면
			break;
		}
	} while (next_permutation(small.begin(), small.end()));

	do {
		if (check(a, big)) {
			break;
		}
	} while (prev_permutation(big.begin(), big.end()));

	for (int i = 0; i < n + 1; i++) {
		cout << big[i];
	}

	cout << '\n';

	for (int i = 0; i < n + 1; i++) {
		cout << small[i];
	}
	return 0;
}