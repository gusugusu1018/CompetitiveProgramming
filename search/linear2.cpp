#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n,q;
	cin >> n;
	vector<int> S(n);
	for (auto& s:S) cin >> s;
	cin >> q;
	for (int i=0;i<q;i++) {
		cin >> t;
		for (const auto s:S)
	}
	for (auto& t:T) cin >> t;
	int counter=0;
	for (const auto t:T) {
		for (const auto s:S) {
			if (s==t) counter++;
		}
	}
	cout << counter << endl;
	return 0;
}
