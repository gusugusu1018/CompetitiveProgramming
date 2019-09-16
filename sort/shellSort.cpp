#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

template<typename T> void insertSort(vector<T>& v) {
	for (size_t i=1;i<v.size();i++) {
		int j=i-1;
		const auto temp = v[i];
		while (j>=0 && v[j]>temp) { //Ascending
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=temp;
	}
}

template<typename T> void shellSort(vector<T>& v) {
	for (size_t i=1;i<v.size();i++) {
		int j=i-1;
		const auto temp = v[i];
		while (j>=0 && v[j]>temp) { //Ascending
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=temp;
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
	vector<float> v(size);
	generateVector(v);
	const auto timeStt = chrono::system_clock::now();
	shellSort(v);
	const auto timeEnd = chrono::system_clock::now();
	const double sortTime = chrono::duration_cast<chrono::microseconds >(timeEnd - timeStt).count();
	cout << "check sort : " << (checkSorted(v)? "OK" : "NG") << endl;
	cout << "time[ms]    : " << sortTime/1000.0 << endl;
	return 0;
}
