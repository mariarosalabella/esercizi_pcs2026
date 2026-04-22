#pragma once
#include <vector>
#include <algorithm> 
#include <cstdlib> 

#include "merge_quick.hpp"  //per prendere la funzione partition

template<typename T>
void better_quicksort(std::vector<T>& vec, int sinistra, int destra) {
	const int soglia = 30;   //soglia individuata dalle misurazioni
	
	if (destra - sinistra + 1 <= soglia) {  
		//se la dimensione del vettore con cui sto lavorando è minore della soglia trovata, uso insertion sort
	    for (int j = sinistra + 1; j <= destra; j++) {
		    T value = vec[j];
		    int i = j-1;
		    while (i >= sinistra && vec[i] > value) {
			    vec[i+1] = vec[i];
			    i = i-1;
		    }
		    vec[i+1] = value;
	    }
	}
	else {
		int p_index = sinistra + std::rand() %(destra - sinistra + 1);  
		int r = partition(vec, sinistra, p_index, destra);
		better_quicksort(vec, sinistra, r - 1);
		better_quicksort(vec, r + 1, destra);
	}
}
		
		
	