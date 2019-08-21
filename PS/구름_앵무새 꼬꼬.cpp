#include <iostream>
#include <string>
using namespace std;

string a[101];
string temp[101];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		getline(cin, a[i]);
	}


	for (int i = 1; i <= n; i++) {
		int mo = 0;
		for (int j = 0; j < a[i].length(); j++) {
			if (a[i][j] == 'a' || a[i][j] == 'e' || a[i][j] == 'i' || a[i][j] == 'o' || a[i][j] == 'u'
				|| a[i][j] == 'A' || a[i][j] == 'E' || a[i][j] == 'I' || a[i][j] == 'O' || a[i][j] == 'U') {
				mo += 1;
				temp[i] += a[i][j];
			}
		}
		if (mo == 0) {
			temp[i] = "???";
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << temp[i] << '\n';
	}
	return 0;
}