#include <iostream>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
int main() {
	int A,B,C,X;
	cin >> A >> B >> C >> X;
	int counter = 0;
	rep(a,A+1) {
		rep(b,B+1) {
			rep(c,C+1) {
				if (X == 500*a+100*b+50*c) counter++;
			}
		}
	}
	cout << counter << endl;
	return 0;
}
