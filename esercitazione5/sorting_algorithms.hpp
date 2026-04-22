#pragma once

#include <vector>
#include <algorithm>

//bubble sort
template<typename T>
void bubble_sort(std::vector<T>& vec) {
	int n = vec.size();
    for (int i = 0; i < n - 1 ; i++) {
	    for (int j = n - 1; j > i; j--) {
			if (vec[j] < vec [j-1]) {
			    std::swap(vec[j], vec [j-1]);
			}
		}
	}
}

//insertion sort
template<typename T>
void insertion_sort(std::vector<T>& vec) {
	int n = vec.size();
	for (int j = 1; j < n; j++) {
		T value = vec[j];
		int i = j-1;
		while (i >= 0 && vec[i] > value) {
			vec[i+1] = vec[i];
			i = i-1;
		}
		vec[i+1] = value;
	}
}

//selection sort
template<typename T>
void selection_sort(std::vector<T>& vec) {
	int n = vec.size();
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (vec[j] < vec[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i) {
			std::swap(vec[i], vec[min_index]);
		}
	}
}


			

					