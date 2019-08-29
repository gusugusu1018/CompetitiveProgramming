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
	sort(A.rbegin(),A.rend());
	for (auto a:A) cout << a << endl;
	for (int i=0;i+2<N;i++) {
		if (A[i]<A[i+1]+A[i+2]) {
			cout << A[i] + A[i+1] + A[i+2] << endl;
			return 0;
		}
	}
	cout << "0" << endl;
	return 0;
}
