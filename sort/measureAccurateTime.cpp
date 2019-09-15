#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
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

//constexpr int VECTOR_MAX = 2147483647;
constexpr int VECTOR_MAX = 247;

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
	ofstream outputfile("bubbleSort.csv");
	outputfile << "size,time" << endl;
	std::chrono::system_clock::time_point timeStt, timeEnd;
	fot (size_t size=10;size<5000;size+=10) {
		vector<int> v(size);
		double aveTime = 0.0;
		for (int i=0;i<100;i++) {
			generateVector(v);
			timeStt = std::chrono::system_clock::now();
			bubbleSort(v);
			timeEnd = std::chrono::system_clock::now();
			aveTime += std::chrono::duration_cast<std::chrono::microseconds >(timeEnd - timeStt).count();
		}
		outputfile << size << "," << aveTime << endl;
	}
	outputfile.close();
	cout << "check sort      : " << (checkSorted(v)? "OK" : "NG") << endl;
	cout << "average time[ms]: " << aveTime/100000.0 << endl;
	return 0;
}
