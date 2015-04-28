#include <iostream>
using namespace std;
const int N = 100005;
int A[N];
bool R1[N];
bool R2[N];
int T[N];
int F[N];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		bool F1 = 1, F2 = 1;
		int TC = 0, FC = 0;
		cin >> n;
		n++;
		for (int i = 1; i < n; ++i) {
			cin >> A[i];
		}
		memset(R1, 0, sizeof(R1));
		memset(R2, 0, sizeof(R2));
		R1[1] = 0;
		for (int i = 1; i < n; ++i) {
			R1[i+1] = A[i] - R1[i-1] - R1[i];
			if (R1[i+1] > 1) {
				F1 = 0;
				 break;
			}
		}
		if (R2[n] == 1) F2 = 0;
		R2[1] = 1;
		for (int i = 1; i < n; ++i) {
			R2[i+1] = A[i] - R2[i-1] - R2[i];
			if (R2[i+1] > 1) {
				F2 = 0;
				break;
			}
		}
		if (R2[n] == 1) F2 = 0;
		if (F1 && F2) {
			cout << "R[1] = 0 or R[1] = 1" << endl;
			for (int i = 1; i < n; ++i) {
				if (R1[i] == R2[i] == 0) {
					F[FC++] = i;
				} else if (R1[i] == R2[i] == 1) {
					T[TC++] = i;
				}
			}
		} else if (F1) {
			cout << "R[1] = 0" << endl;
			for (int i = 1; i < n; ++i) {
				if (R1[i] == 0) {
					F[FC++] = i;
				} else {
					T[TC++] = i;
				}
			}
		} else if (F2) {
			cout << "R[1] = 1" << endl;
			for (int i = 1; i < n; ++i) {
				if (R2[i] == 0) {
					F[FC++] = i;
				} else {
					T[TC++] = i;
				}
			}
		}
		cout << TC << ' ';
		for (int i = 0; i < TC; ++i) {
			cout << T[i] << ' ';
		}
		cout << endl;
		cout << FC << ' ';
		for (int i = 0; i < FC; ++i) {
			cout << F[i] << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
			
		
