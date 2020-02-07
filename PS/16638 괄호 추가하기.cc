/*
연산자 우선순위를 고려하여 괄호치기
괄호안에 연산자는 하나만, 괄호는 중첩될 수 없음
-> 연산자가 연속해서 먼저 계산될 수 없음
가능한 답의 범위가 -2^31~2^31
1. 괄호를 먼저 계산
2. * 계산 -> 괄호를 계산한 결과에서 0과 곱하지 않도록 이전의 계산 결과에 곱하기
3. +, - 계산
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Expr {
	int num; //숫자, 연산자면 0
	int op; //0: 숫자, 1: +, 2: -, 3: *
};

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	vector<Expr> a(n);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			a[i] = { s[i]-'0', 0 }; //->s[i]번째에 있는 숫자는 아스키값 자체임 '0' 빼주기
		}
		else {
			if (s[i] == '+') {
				a[i] = { 0, 1 };
			}
			else if (s[i] == '-') {
				a[i] = { 0, 2 };
			}
			else if (s[i] == '*') {
				a[i] = { 0, 3 };
			}
		}
	}

	int ans = -2147482648; //int 최솟값
	
	int m = (n - 1) / 2; //연산자의 개수

	for (int i = 0; i < (1 << m); i++) { //m번째 연산자를 먼저 계산하거나 안하거나
		bool ok = true; //불가능한 괄호인 경우 false
		for (int j = 0; j < m - 1; j++) {
			if ((i&(1 << j)) > 0 && (i&(1 << (j + 1))) > 0) { //괄호안에 연산자가 두개 들어있는 경우
				ok = false;
			}
		}

		if (!ok) continue;
		
		vector<Expr> b(a);
		
		for (int j = 0; j < m; j++) {
			if ((i&(1 << j)) > 0) {
				int k = 2 * j + 1;
				if (b[k].op == 1) {
					b[k - 1].num += b[k + 1].num;
					b[k].op = -1; // b[k].op b[k+1].num 부분을 건너 뛰기 위함
					b[k + 1].num = 0;
				}
				else if (b[k].op == 2) {
					b[k - 1].num -= b[k + 1].num;
					b[k].op = -1;
					b[k + 1].num = 0;
				}
				else if (b[k].op == 3) {
					b[k - 1].num *= b[k + 1].num;
					b[k].op = -1;
					b[k + 1].num = 0;
				}
			}
		}

		vector<Expr> c;
		for (int j = 0; j < n; j++) {
			if (j % 2 == 0) {
				c.push_back(b[j]);
			}
			else {
				if (b[j].op == -1) {
					j += 1;
				}
				else {
					if (b[j].op == 3) {
						int temp = c.back().num*b[j + 1].num;
						c.pop_back();
						c.push_back({ temp, 0 });
						j += 1;
					}
					else {
						c.push_back(b[j]);
					}
				}
			}
		}

		int l = ((int)c.size() - 1) / 2;
		int cur = c[0].num;

		for (int j = 0; j < l; j++) {
			int k = 2 * j + 1;
			if (c[k].op == 1) {
				cur += c[k + 1].num;
			}
			else if (c[k].op == 2) {
				cur -= c[k + 1].num;
			}
		}

		if (ans < cur) {
			ans = cur;
		}
	}

	cout << ans << '\n';

	return 0;
}