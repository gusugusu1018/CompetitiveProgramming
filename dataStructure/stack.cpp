#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int main() {
	stack<int> st;
	string line,s;
	getline(cin, line);
	istringstream iss(line);
	while (iss >> s) {
		try {
			const auto num = stoi(s);
			st.push(num);
			cout << "push : " << st.top() << endl;
		}
		catch (...) {
			if (s == "*") {
				const auto a = st.top();
				st.pop();
				const auto b = st.top();
				st.pop();
				st.push(b*a);
			} else if (s == "-") {
				const auto a = st.top();
				st.pop();
				const auto b = st.top();
				st.pop();
				st.push(b-a);
			} else if (s == "+") {
				const auto a = st.top();
				st.pop();
				const auto b = st.top();
				st.pop();
				st.push(b+a);
			}
		}
	}

	cout << st.top() << endl;
	return 0;
}
