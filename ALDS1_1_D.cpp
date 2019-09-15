#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> R(N);
	for (auto& r: R) cin >> r;
	int maxv = -2000000000;
	int minv = R[0];
	for (int i=1; i<N;i++) {
		maxv = max(maxv, R[i]-minv);
		minv = min(minv, R[i]);
		//cout << "minv : " << minv << ", maxv : " << maxv << endl;
	}
	cout << maxv << endl;
	return 0;
}
