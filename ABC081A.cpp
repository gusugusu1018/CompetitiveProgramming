#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int c = 0;
	if (s[0] == '1') c++;
	if (s[1] == '1') c++;
	if (s[2] == '1') c++;
	cout << c << endl;
	return 0;
}
