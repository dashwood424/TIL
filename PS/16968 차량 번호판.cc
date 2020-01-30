#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int ans = 1;
	for (int i = 0; i < s.length(); i++) {
		int cnt = (s[i] == 'c') ? 26 : 10;
		if (i > 0 && s[i] == s[i - 1]) {
			cnt -= 1;
		}
		ans *= cnt;
	}
	cout << ans << '\n';

	return 0;
}