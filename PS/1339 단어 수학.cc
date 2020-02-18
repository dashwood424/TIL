#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int alpha[26]; //각 알파벳에 대응하는 숫자

int go(vector<string> &a, vector<char> &letters, vector<int> &d) {
	//letters에 d에 저장된 순서대로 숫자 대입하기
	int m = letters.size();
	
	for (int i = 0; i < m; i++) {
		alpha[letters[i] - 'A'] = d[i];
	}

	int ans = 0;

	//입력받은 문자열 a에 적용
	for (string s : a) { 
		int temp = 0;
		for (char c : s) { //s번째 문자열에 있는 문자 c와 대입된 숫자로 숫자 만들기
			temp = temp * 10 + alpha[c - 'A'];
		}
		ans += temp;
	}

	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	vector<char> letters;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (char s : a[i]) { //i번째 문자열에 있는 알파벳 
			letters.push_back(s);
		}
	}
	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());

	int m = letters.size();
	vector<int> d;
	
	for (int i = 0; i < m; i++) { //알파벳의 개수만큼 큰 수부터
		d.push_back(9 - i);
	}
	sort(d.begin(), d.end());

	int ans = 0;

	do {
		int temp = go(a, letters, d);
		if (ans < temp) {
			ans = temp;
		}
	} while (next_permutation(d.begin(), d.end())); //letters에 대입할 숫자들을 결정

	cout << ans << '\n';

	return 0;
}