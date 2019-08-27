#include <iostream>
using namespace std;

bool d[360]; //각 i를 만들 수 있으면 true
int a[10]; //만들 수 있는 각

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	d[0] = true; //0도는 항상 가능
	
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 360; k++) { //모든 가능한 각을 만들 수 있음을 보장하기 위해
			for (int j = 0; j < 360; j++) {
				if (d[j] == false) continue; //만들 수 없는 각이면 건너뜀
				d[(j - a[i] + 360) % 360] = true;
				d[(j + a[i]) % 360] = true;
			}
		}
	}
	while (m--) {
		int x;
		cin >> x;
		cout << (d[x] ? "YES" : "NO") << '\n';
	}
	return 0;
}