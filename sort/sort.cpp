#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
using namespace std;
constexpr int VECTOR_MAX = 10000;

template<typename T> bool checkSorted(const vector<T>& v){
	bool is_sorted = true;
	int temp = 0;
	for(const auto& e : v){
		if(temp > e) is_sorted = false;
		temp = e;
	}
	return is_sorted;
}

template<typename T> void bubbleSort(vector<T>& v){
	bool sorting = true;
	size_t sortedIdx = 0;
	while(sorting){
		sorting = false;
		for(size_t i=0; i<v.size()-1-sortedIdx; ++i){
			if(v[i]>v[i+1]){
				swap(v[i],v[i+1]);
				if(!sorting)sorting = true;
			}
		}
		sortedIdx++;
	}
}

template<typename T> void selectionSort(vector<T>& v){
	for(size_t i=0; i<v.size()-1; ++i){
		int minTemp = v[i];
		size_t minIdx = i;
		for(size_t j=i+1; j<v.size(); ++j){
			if(minTemp > v[j]){
				minTemp = v[j];
				minIdx = j;
			}
		}
		swap(v[i],v[minIdx]);
	}
}

template<typename T> void shakerSort(vector<T>& v){
	bool sorting = true;
	size_t sortedIdx = 0;
	while(sorting){
		for(size_t i=sortedIdx; i<v.size()-1; ++i){
			if(v[i]>v[i+1]){
				swap(v[i],v[i+1]);
			}
		}
		sorting = false;
		for(size_t i=v.size()-2-sortedIdx; i<v.size(); --i){
			if(v[i]>v[i+1]){
				swap(v[i],v[i+1]);
				if(!sorting)sorting = true;
			}
		}
		sortedIdx++;
	}
}

template<typename T> void combSort(vector<T>& v){
	size_t h = (v.size()*10)/13;
	bool is_sorted = false;
	while(!is_sorted){
		if(h==1)is_sorted = true;
		for(size_t i=0; i<v.size()-h; ++i){
			if(v[i]>v[i+h]){
				swap(v[i],v[i+h]);
				if(is_sorted)is_sorted = false;
			}
		}
		if(h>1) h = (h*10)/13;
		if(h==0) h = 1;
	}
}

template<typename T> void normSort(vector<T>& v){
	for(size_t i=1; i<v.size(); ++i){
		for(size_t j=i; j<v.size(); --j){
			if(v[j-1]>v[j]){
				swap(v[j-1],v[j]);
			}
		}
	}
}

template<typename T> void shellSort(vector<T>& v){
	size_t h = 1;
	while(1){
		size_t nexth = 3*h + 1;
		if(nexth<v.size()) h = nexth;
		else break;
	}
	bool is_sorted = false;
	while(!is_sorted){
		if(h==1)is_sorted = true;
		for(size_t i=h; i<v.size(); ++i){
			for(size_t j=i; j>=h; j-=h){
				if(v[j-h]>v[j]){
					swap(v[j-h],v[j]);
					if(is_sorted)is_sorted = false;
				}
			}
		}
		h = (h-1)/3;
		if(h==0) h = 1;
	}
}

int main() {
	double sortTime;
	std::chrono::system_clock::time_point timeStt, timeEnd;
	size_t size = 10000;
	vector<int> v(size);
	generateVector(v);
	//bubble sort
	vector<int> v_bubble = v;
	timeStt = std::chrono::system_clock::now();
	bubbleSort(v_bubble);
	timeEnd = std::chrono::system_clock::now();
	sortTime = std::chrono::duration_cast<std::chrono::microseconds >(timeEnd - timeStt).count();
	cout << "bubble sort : " << (checkSorted(v_bubble)? "OK" : "NG") << endl;
	cout << "bubble time[s] : " << sortTime/1000000 << endl;

	//selection sort
	vector<int> v_selection = v;
	timeStt = std::chrono::system_clock::now();
	selectionSort(v_selection);
	timeEnd = std::chrono::system_clock::now();
	sortTime = std::chrono::duration_cast<std::chrono::microseconds >(timeEnd - timeStt).count();
	cout << "selection sort : "  << (checkSorted(v_selection)? "OK" : "NG") << endl;
	cout << "selection time[s] : " << sortTime/1000000 << endl;

	//shaker sort
	vector<int> v_shaker = v;
	timeStt = std::chrono::system_clock::now();
	shakerSort(v_shaker);
	timeEnd = std::chrono::system_clock::now();
	sortTime = std::chrono::duration_cast<std::chrono::microseconds >(timeEnd - timeStt).count();
	cout << "shaker sort : "  << (checkSorted(v_shaker)? "OK" : "NG") << endl;
	cout << "shaker time[s] : " << sortTime/1000000 << endl;

	//comb sort
	vector<int> v_comb = v;
	timeStt = std::chrono::system_clock::now();
	combSort(v_comb);
	timeEnd = std::chrono::system_clock::now();
	sortTime = std::chrono::duration_cast<std::chrono::microseconds >(timeEnd - timeStt).count();
	cout << "comb sort : "  << (checkSorted(v_comb)? "OK" : "NG") << endl;
	cout << "comb time[s] : " << sortTime/1000000 << endl;

	//norm sort
	vector<int> v_norm = v;
	timeStt = std::chrono::system_clock::now();
	normSort(v_norm);
	timeEnd = std::chrono::system_clock::now();
	sortTime = std::chrono::duration_cast<std::chrono::microseconds >(timeEnd - timeStt).count();
	cout << "norm sort : "  << (checkSorted(v_norm)? "OK" : "NG") << endl;
	cout << "norm time[s] : " << sortTime/1000000 << endl;

	//shell sort
	vector<int> v_shell = v;
	timeStt = std::chrono::system_clock::now();
	shellSort(v_shell);
	timeEnd = std::chrono::system_clock::now();
	sortTime = std::chrono::duration_cast<std::chrono::microseconds >(timeEnd - timeStt).count();
	cout << "shell sort : "  << (checkSorted(v_shell)? "OK" : "NG") << endl;
	cout << "shell time[s] : " << sortTime/1000000 << endl;

	return 0;
}
