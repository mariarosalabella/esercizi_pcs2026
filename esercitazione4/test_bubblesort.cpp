#include <iostream>
#include <vector>
#include <string>

#include <cstdlib> //contiene rand()

#include "sorting_algorithms.hpp"
#include "is_sorted.hpp"
#include "randfiller.h"

int main() {
	randfiller rf;
	std::vector<std::vector<int>> vettori;//inizializza un vettore di vettori
	//definisco i 100 vettori casuali da mettere in vettori
	for (int i = 0; i < 100; i++) {
		int size = rand() %21; //genera numeri casuali da 0 a 20
		std::vector<int> v; //inizializzo un vettore vuoto di interi
		
		v.resize(size); 
		rf.fill(v, -50, 50);
      
		vettori.push_back(v); //aggiunge v alla fine di vettori
	}
	
	//test sui vettori
	std::cout << "Test algoritmo bubblesort:" << "\n";
	std::cout << "Test su 100 vettori"<< "\n";
	for (int i = 0; i < vettori.size(); i++) {
		bubble_sort(vettori[i]);
		
		if (is_sorted(vettori[i]) == false) {
			std::cout << "Errore: il vettore" << i << "non è ordinato"<< "\n";
			return 1;
		}
	}
	std::cout << "Tutti i vettori sono stati ordinati correttamente." << "\n";
	
	//stringhe
	std::vector<std::string> words; //inizializza un vettore di stringhe
	words.push_back("case");
	words.push_back("viaggi");
	words.push_back("auto");
	words.push_back("libri");
	words.push_back("fogli");
	words.push_back("giornale");
	words.push_back("biblioteca");
	words.push_back("aula");
	words.push_back("politecnico");
	words.push_back("luce");
	words.push_back("dizionario");
	
	bubble_sort(words);
	//test sulle stringhe
	std::cout << "Test su stringhe:"<< "\n";
	if (is_sorted(words) == false) {
		std::cout << "Errore: le parole non sono state ordinate correttamente." << "\n";
		return 1;
	}
	else {
		std::cout << "Anche le parole sono state ordinate correttamente." << "\n";
	}
	return 0;
}
	
		
	
	
		
	






