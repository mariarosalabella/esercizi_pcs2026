#pragma once
#include <vector>
#include <algorithm>  //per swap
#include <cstdlib>  //per rand

//funzione merge
template<typename T>
void merge(std::vector<T>& vec, int sinistra, int centro, int destra) {
	int n1 = centro - sinistra + 1;
	int n2 = destra - centro;
	
	std::vector<T> L(n1);
	std::vector<T> R(n2);
	
	for (int i = 0; i < n1; i++) {
		L[i] = vec[sinistra + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = vec[centro + j + 1];
	}
	
	//fusion
	int i = 0;
	int j = 0;
	for (int k = sinistra; k <= destra; k++) {
		if (i < n1 && (j >= n2 || L[i] <= R[j])) {  //per valori di i validi, se R è finito (j>=n2) o se L[i] <= R[j], prendi da L
			vec[k] = L[i];
			i++;
		}
		else {
			vec[k] = R[j];   //altrimenti prendi da R
			j++;
		}
	}
}
		
template<typename T>
void mergesort(std::vector<T>& vec, int sinistra, int destra) {
	if (sinistra < destra) {
		int centro = (sinistra + destra)/2;
		mergesort(vec, sinistra, centro);
		mergesort(vec, centro + 1, destra);  //continuo a spezzare finché ogni pezzo ha 1 elemento (sinistra==destra)
		merge(vec, sinistra, centro, destra);  //applico fusion
	}
}


template<typename T> 
int partition(std::vector<T>& vec, int sinistra, int p_index, int destra) {
	std::swap(vec[p_index], vec[destra]);  //metto il pivot in ultima posizione
    T p = vec[destra];  //prendo il valore del pivot
	
	int i = sinistra - 1; //indice degli elementi minori del pivot
	
	for (int j = sinistra; j < destra; j++) {
		if (vec[j] <= p) {
			i++;
			std::swap(vec[i], vec[j]);  //metto tutti i <= pivot a sinistra
		}
	}
    std::swap(vec[i+1], vec[destra]);  //metto il pivot in posizione corretta
	return i + 1;
}

template<typename T>
void quicksort(std::vector<T>& vec, int sinistra, int destra) {
	if (sinistra < destra) {
		int p_index = sinistra + std::rand() %(destra - sinistra + 1);  //scelgo un pivot random
		int r = partition(vec, sinistra, p_index, destra);
		quicksort(vec, sinistra, r - 1);
		quicksort(vec, r + 1, destra);
	}
}	

	