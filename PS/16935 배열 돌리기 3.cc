#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> go1(vector<vector<int>> &a) { //상하반전 연산
	int n = a.size();
	int m = a[0].size();
	vector<vector<int>> b(n, vector<int>(m));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = a[n - i - 1][j];
		}
	}

	return b;
}

vector<vector<int>> go2(vector<vector<int>> &a) { //좌우반전 연산
	int n = a.size();
	int m = a[0].size();
	vector<vector<int>> b(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = a[i][m - j - 1];
		}
	}

	return b;
}

vector<vector<int>> go3(vector<vector<int>> &a) { //오른쪽으로 90도 연산
	int n = a.size();
	int m = a[0].size();
	vector<vector<int>> b(m, vector<int>(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[n - j - 1][i];
		}
	}

	return b;
}

vector<vector<int>> go4(vector<vector<int>> &a) { //왼쪽으로 90도 연산
	int n = a.size();
	int m = a[0].size();
	vector<vector<int>> b(m, vector<int>(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[j][m - i - 1];
		}
	}

	return b;
}

vector<vector<int>> go5(vector<vector<int>> &a) { //1->2, 2->3, 3->4, 4->1
	int n = a.size();
	int m = a[0].size();
	vector<vector<int>> b(n, vector<int>(m));

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m / 2; j++) {
			b[i][j] = a[i + n / 2][j]; //4->1
			b[i][j + m / 2] = a[i][j]; //1->2
			b[i + n / 2][j + m / 2] = a[i][j + m / 2]; //2->3
			b[i + n / 2][j] = a[i + n / 2][j + m / 2]; //3->4
		}
	}

	return b;
}

vector<vector<int>> go6(vector<vector<int>> &a) { //1->4, 4->3, 3->2, 2->1
	int n = a.size();
	int m = a[0].size();
	vector<vector<int>> b(n, vector<int>(m));

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m / 2; j++) {
			b[i][j] = a[i][j + m / 2]; //2->1
			b[i][j + m / 2] = a[i + n / 2][j + m / 2]; //3->2
			b[i + n / 2][j + m / 2] = a[i + n / 2][j]; //4->3
			b[i + n / 2][j] = a[i][j];
		}
	}

	return b;
}

int main() {
	int n, m, r; //r개의 회전연산
	cin >> n >> m >> r;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	while (r--) {
		int k;
		cin >> k;

		if (k == 1) {
			a = go1(a);
		}
		else if (k == 2) {
			a = go2(a);
		}
		else if (k == 3) {
			a = go3(a);
		}
		else if (k == 4) {
			a = go4(a);
		}
		else if (k == 5) {
			a = go5(a);
		}
		else if (k == 6) {
			a = go6(a);
		}
	}

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}