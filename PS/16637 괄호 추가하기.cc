/*

괄호안에는 연산자가 하나만 있고 연산자 우선 순위는 같다
괄호를 친다 -> 연산자를 먼저 계산한다 -> 연산자를 먼저 계산하거나 안하거나 문제
괄호안에는 연산자가 하나만 있어야 함 -> 연산자를 연속해서 먼저 계산하려함
괄호가 중첩되는 경우 안됨
괄호는 추가하지 않아도 됨 -> 먼저 계산하는 연산자가 없는 경우도 가능
수식의 길이가 n일 때 연산자의 개수 m은 m=(n-1)/2 개
괄호를 적절히 추가하여 계산하는 방법의 수를 러프하게 생각해보면 2^m 가지 -> (1<<m) 가지
0<=j<m 일 때, j번째 연산자를 먼저 계산하고 j+1번째 연산자를 먼저 계산하는 경우 제외하기

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Expr {
	int num; //수
	int op; //연산자, 0: 수, 1: +, 2: -, 3: *
};

int main() {
	int n;
	cin >> n; //수식의 길이
	string s;
	cin >> s;

	vector<Expr> a(n);

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) { //수 이면
			a[i] = { s[i] - '0', 0 };
		}
		else { //연산자
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

	int ans = -2147483647; // -2^31 <= 정답 <= 2^31
	int m = (n - 1) / 2;

	for (int i = 0; i < (1 << m); i++) { //연산자의 개수가 m일 때 모든 가능한 경우의 수 고려하기 
		//모든 경우의 수 고려하면서 최대값 찾기
		bool ok = true; //불가능한 경우 false
		for (int j = 0; j < m - 1; j++) {
			if ((i&(1 << j)) > 0 && (i&(1 << (j + 1))) > 0) { //j번째 연산자와 j+1번째 연산자가 괄호안에 연속하는 경우
				ok = false;
			}
		}

		if (!ok) continue; //불가능한 경우이면 다음 경우 탐색

		vector<Expr> b(a);

		for (int j = 0; j < m; j++) { //괄호 안의 연산자 계산
			if ((i&(1 << j)) > 0) { //m번째 연산자를 먼저 계산하는 경우
				int k = 2 * j + 1; //수식에서 연산자의 위치 복원

				if (b[k].op == 1) { //k번째 연산자 연산하고 +0 처리 
					b[k - 1].num += b[k + 1].num;
					b[k + 1].num = 0;
				}
				else if (b[k].op == 2) {
					b[k - 1].num -= b[k + 1].num;
					b[k].op = 1;
					b[k + 1].num = 0;
				}
				else if (b[k].op == 3) {
					b[k - 1].num *= b[k + 1].num;
					b[k].op = 1;
					b[k + 1].num = 0;
				}
			}
		}

		//순차적으로 수식결과 계산
		int temp = b[0].num;

		for (int j = 0; j < m; j++) {
			int k = 2 * j + 1; //연산자의 위치

			if (b[k].op == 1) {
				temp += b[k + 1].num;
			}
			else if (b[k].op == 2) {
				temp -= b[k + 1].num;
			}
			else if (b[k].op == 3) {
				temp *= b[k + 1].num;
			}
		}

		if (ans < temp) {
			ans = temp;
		}
	}

	cout << ans << '\n';

	return 0;
}