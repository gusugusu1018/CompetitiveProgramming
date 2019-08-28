#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int N, A, B;
	cin >> N >> A >> B;
	int res = 0;
	for (int n = 1; n <= N; n++) {
		int sum = 0;
		int temp = n;
		int i = 0;
		while(true) {
			sum += temp % (int)pow(10,i);
			temp/=pow(10,i);
			i++;
			if (temp < 1) break;
		}
		if ((sum >= A) && (sum <= B)) {
			res+=n;
		}
		//cout << n << " sum " << sum << " res " << res << endl;
	}
	cout << res << endl;
	return 0;
}
