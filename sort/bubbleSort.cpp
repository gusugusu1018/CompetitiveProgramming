#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

template<typename T> void bubbleSort(vector<T>& v) {
	bool sorting = true;
	for (size_t i=0;sorting;i++) {
		sorting = false;
		for(size_t j=v.size()-1;j>=i+1;j--){
			if(v[j]<v[j-1]){ //Ascending
				swap(v[j],v[j-1]);
				sorting = true;
			}
		}
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
	bubbleSort(v);
	const auto timeEnd = chrono::system_clock::now();
	const double sortTime = chrono::duration_cast<chrono::microseconds >(timeEnd - timeStt).count();
	cout << "check sort    : " << (checkSorted(v)? "OK" : "NG") << endl;
	cout << "sort time[ms] : " << sortTime/1000.0 << endl;
	return 0;
}
