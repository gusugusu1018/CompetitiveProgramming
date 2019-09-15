#include <iostream>
#include <vector>
using namespace std;

template<typename T> void insertSort(vector<T>& v) {
	for (int i=1;i<v.size();i++) {
		int j=i-1;
		const auto temp = v[i]
		while (j>=0 && v[j]>temp) {
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=temp;
		for (const auto& e:v) cout << e << ",";
		cout << endl;
	}
}

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (auto& e: v) cin >> e;
	insertSort(A);
	return 0;
}
