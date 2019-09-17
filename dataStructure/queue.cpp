#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N,q;
	cin >> N;
	cin >> q;
	struct task{
		string name;
		int time;
	};
	queue<task> que;
	for (int i=0;i<N;i++) {
		task t;
		cin >> t.name;
		cin >> t.time;
		que.push(t);
	}
	int elapsedTime = 0;
	while (!que.empty()) {
		auto t = que.front();
		que.pop();
		if (t.time-q > 0) {
			elapsedTime += q;
			t.time -= q;
			que.push(t);
		} else {
			elapsedTime += t.time;
			cout << t.name << " " << elapsedTime << endl;
		}
	}
	return 0;
}
