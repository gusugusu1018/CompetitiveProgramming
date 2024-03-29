#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int L, N;
	vector<int> X;
	cin >> L >> N;
	for (int n = 0; n < N; n++) {
		int x;
		cin >> x;
		X.push_back(x);
	}
	int ans_min = 0;
	int ans_max = 0;
	for (auto x:X) {
		ans_min = max(ans_min,min(L-x,x));
		ans_max = max(ans_max,max(L-x,x));
	}
	cout << ans_min << endl;
	cout << ans_max << endl;
	return 0;
}
