#include <iostream>
#include <vector>
#include <string>
#include <valarray>
#include <algorithm>
#include <cmath>
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
	vector<int> mi;
	vector<int> ma;
	for (auto x:X) {
		mi.push_back(min(L-x,x));
		ma.push_back(max(L-x,x));
	}
	int ans_min = *max_element(mi.begin(), mi.end());
	int ans_max = *max_element(ma.begin(), ma.end());
	cout << ans_min << endl;
	cout << ans_max << endl;
	return 0;
}
