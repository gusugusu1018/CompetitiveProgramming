#include <iostream>
#include <vector>
#define rep(i,n) for(int i=0; i<n;i++)
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A;
	rep(i,N) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	int c=0;
	while (true) {
		rep(i,N) {
			if (A[i]%2==1) {
				cout << c << endl;
				return 0;
			}
		}
		c++;
		rep(i,N) A[i]/=2;
	}
}
