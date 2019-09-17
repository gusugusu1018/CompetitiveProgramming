#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	stack<int> st;
	string s;
	cin >> s;
	for (auto c:s) {
		if (c=='\\') {
			cout << "\\" << endl;
		}else if (c=='/') {
			cout << "/" << endl;
		}else if (c=='_') {
			cout << "_" << endl;
		}
	}
	return 0;
}
