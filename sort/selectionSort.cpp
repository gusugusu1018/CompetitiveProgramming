#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

template<typename T> void selectionSort(vector<T>& v) {
	for (size_t i=0;i<v.size()-1;i++) {
		size_t minj = i;
		for (size_t j=i+1;j<v.size();j++) {
			if (v[j] < v[minj]) minj = j;
		}
		swap(v[i],v[minj]);
	}
}

constexpr int VECTOR_MAX = 2000000000;

template<typename T> void generateVector(vector<T>& v){
	for (auto& e : v) e = rand()%VECTOR_MAX;
}

template<typename T> bool checkSorted(const vector<T>& v){
	bool is_sorted = true;
	int temp = 0;
	for (const auto& e : v){
		if(temp > e) is_sorted = false;
		temp = e;
	}
	return is_sorted;
}

int main() {
	const size_t size = 1000;
	vector<int> v(size);
	generateVector(v);
	const auto timeStt = chrono::system_clock::now();
	selectionSort(v);
	const auto timeEnd = chrono::system_clock::now();
	const double sortTime = chrono::duration_cast<chrono::microseconds >(timeEnd - timeStt).count();
	cout << "check sort    : " << (checkSorted(v)? "OK" : "NG") << endl;
	cout << "sort time[ms] : " << sortTime/1000.0 << endl;
	return 0;
}
