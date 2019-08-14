//비트마스크로 풀기

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count(int mask, vector<int> &words) { //배운 글자로 읽을 수 있는 단어의 수
	int cnt = 0;
	for (int word : words) {
		//mask: 배운 알파벳이 들어있음
		//word에 배우지 않은 알파벳이 없어야 함
		//~mask
		if ((word & ((1 << 26) - 1 - mask)) == 0) {
			//word가 1 -> 단어에 포함된 알파벳임
			//(1<<26)-1-mask가 1 -> 배우지 않은 알파벳임
			//0 -> word에 배우지 않은 글자가 없음
			cnt += 1;
		}
	}
	return cnt;
}


int go(int index, int k, int mask, vector<int> &words) { //index: 알파벳의 번호, k: 배울수 있는 알파벳의 개수
	if (k < 0) return 0; //배울수 있는 글자를 모두 배웠다면
	
	if (index == 26) {
		return count(mask, words);
	}

	int ans = 0;
	int t1 = go(index + 1, k - 1, mask | (1 << index), words);
	if (ans < t1) ans = t1;

	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') {
		//'a','n','t','i','c' 가 아닌 경우 알파벳을 배우지 않는 경우 추가
		t1 = go(index + 1, k, mask, words);
		if (ans < t1) ans = t1;
	}
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> words(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (char x : s) {
			//word[i]: i번째 단어에 포함되어있는 알파벳의 비트마스크
			words[i] |= (1 << (x - 'a'));
		}
	}
	cout << go(0, k, 0, words) << '\n';
	return 0;
}