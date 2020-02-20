#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string a;
	cin >> a;
	char op;
	cin >> op;
	string b;
	cin >> b;

	int a_0 = 0; //a에서 0의 개수
	int b_0 = 0; //b에서 0의 개수

	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] == '0') {
			a_0 += 1;
		}
	}
	for (int i = 0; b[i] != '\0'; i++) {
		if (b[i] == '0') {
			b_0 += 1;
		}
	}

	vector<char> ans;

	if (op == '+') {
		if (a_0 < b_0) {
			ans.push_back('1');
			for (int i = 0; i < b_0 - a_0 - 1; i++) {
				ans.push_back('0');
			}
			ans.push_back('1');
			for (int i = 0; i < a_0; i++) {
				ans.push_back('0');
			}
		}
		else if (a_0 == b_0) {
			ans.push_back('2');
			for (int i = 0; i < a_0; i++) {
				ans.push_back('0');
			}
		}
		else if (a_0 > b_0) {
			ans.push_back('1');
			for (int i = 0; i < a_0 - b_0 - 1; i++) {
				ans.push_back('0');
			}
			ans.push_back('1');
			for (int i = 0; i < b_0; i++) {
				ans.push_back('0');
			}
		}
	}
	else if (op == '*') {
		ans.push_back('1');
		for (int i = 0; i < a_0 + b_0; i++) {
			ans.push_back('0');
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}

	return 0;
}