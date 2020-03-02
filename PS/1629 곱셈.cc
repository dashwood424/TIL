#include <iostream>
using namespace std;

long long go(long long a, long long b, long long c) {
	if (b == 0) {
		return 1;
	}
	else if (b == 1) {
		return a%c;
	}
	else if (b % 2 == 0) {
		long long temp = go(a, b / 2, c);
		return (temp*temp) % c;
	}
	else if (b % 2 == 1) {
		return (a*go(a, b - 1, c)) % c;
	}
}

int main() {
	long long a, b, c;
	cin >> a >> b >> c;

	cout << go(a, b, c) << '\n';

	return 0;
}