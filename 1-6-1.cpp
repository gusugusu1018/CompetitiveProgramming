#include <iostream>
#include <vector>
#include <string>
#include <valarray>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int N;
	vector<int> A;
	cin >> N;
	for (int n = 0; n < N; n++) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j+1; k < N; k++) {
				int len = A[i] + A[j] + A[k];
				int ma = max(A[i],max(A[j],A[k]));
				int res = len - ma;
				if (res > ma) {
					ans = max(ans,len);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
