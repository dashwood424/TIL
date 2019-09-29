#include <iostream>
#include <vector>
using namespace std;

vector<int> lotto;

void go(vector<int> &a, int index, int cnt) {
	//a: 주어진 숫자
	//index: index번째 숫자를 포함할지 말지
	//cnt: 6개를 뽑았는지
	
	int n = a.size();

	//1. 정답을 찾은 경우(6개 숫자를 뽑음)
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << ' ';
		}
		cout << '\n';
		return;
	}

	//2. 불가능한 경우
	if (index == n) return;
	
	//3. 다음 가능한 경우
	lotto.push_back(a[index]);
	go(a, index + 1, cnt + 1); //index번째 수를 포함하는 경우
	lotto.pop_back();
	go(a, index + 1, cnt); //index번째 수를 포함하지 않는 경우

}

int main() {
	while (true) {
		int n;
		cin >> n;
		
		if (n == 0) {
			break;
		}
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		go(a, 0, 0);
		cout << '\n';
	}
	return 0;
}