#pragma once 

#include <vector>

template<typename T>
//verifica se un vettore è ordinato, è un bool
bool is_sorted(const std::vector<T>& vec) {
    if (vec.size() == 0) {
	    return true;
	}
	
	for (int i = 1; i < vec.size(); i++) {
	    if (vec[i] < vec[i-1]) {
		    return false;
		}
	}
	
	return true;
}
	
	

