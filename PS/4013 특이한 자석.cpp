#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int n = 4;
		int k;
		cin >> k; //�ڼ��� ȸ����Ű�� Ƚ��
		vector<vector<int>> a(n, vector<int>(8));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> a[i][j];
			}
		}

		while (k--) { //ȸ�� Ƚ�� ��ŭ �ݺ�
			int no, dir; //ȸ����ų �ڼ�, ����(1: �ð�, -1:�ݽð�)
			cin >> no >> dir;
			no -= 1; 
			vector<int> d(8, 0); //�ڼ����� ȸ�� ����
			d[no] = dir; //no��° �ڼ��� ����
			
			for (int i = no - 1; i >= 0; i--) { //no��° �ڼ��� �����ڼ��� ȸ�� ���� ����
				if (a[i][2] != a[i + 1][6]) { //���� �ٸ���
					d[i] = -d[i + 1]; //�ݴ� ��������
				}
				else { //���� ������ ȸ������ ���� -> 0
					break;
				}
			}

			for (int i = no + 1; i < n; i++) { //no��° �ڼ��� ������ �ڼ��� ȸ������
				if (a[i - 1][2] != a[i][6]) { //���� �ٸ���
					d[i] = -d[i - 1];
				}
				else {
					break;
				}
			}

			for (int i = 0; i < n; i++) {
				if (d[i] == 0) continue; //i��° �ڼ��� ȸ������ �ʴ� ���

				else if (d[i] == 1) { //i��° �ڼ��� �ð�������� ȸ���ϴ� ���
					int temp = a[i][7];
					for (int j = 7; j > 0; j--) {
						a[i][j] = a[i][j - 1];
					}
					a[i][0] = temp;
				}
				else if (d[i] == -1) {
					int temp = a[i][0];
					for (int j = 0; j < 7; j++) {
						a[i][j] = a[i][j + 1];
					}
					a[i][7] = temp;
				}
			}
		}
		int ans = 0;

		for (int i = 0; i < n; i++) {
			if (a[i][0] == 1) {
				ans |= (1 << i);
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}