#include <iostream>
#include <vector>
using namespace std;

template<typename T> void insertSort(vector<T>& v) {
	for (int i=1;i<v.size();i++) {
		int j=i-1;
		while (j>=0 && v[j]>v[i]) {
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=v[i];
		for (const auto& e:v) cout << e << " ";
		cout << endl;
	}
}


int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (auto& a: A) cin >> a;
	insertSort(A);
	for (const auto a:A) cout << a << " ";
	cout << endl;
	return 0;
}
