#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> R(N);
	for (auto& r: R) cin >> r;
	int max = 0;
	for (int i=0; i<N-1;i++) {
		int diff = R[i+1] - R[i];
		if (diff < 0) { //down
			//initialize
			max = 0;
		} else { //up
			max += diff;
		}
		cout << R[i] << " " << max << endl;
	}
}
