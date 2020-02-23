#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore(); //입력 버퍼 비우기
	while(n--) {
		string a;
		getline(cin, a); //공백 문자를 포함하여 읽어 들임

		stack<char> s;
		for (int i = 0; a[i]!='\0'; i++) {
			if (a[i] != ' ') {
				s.push(a[i]);
			}
			else {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
		}

		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
		cout << '\n';
	}

	return 0;
}