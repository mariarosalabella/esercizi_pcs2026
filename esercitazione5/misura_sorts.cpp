#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "sorting_algorithms.hpp"
#include "merge_quick.hpp"

#include "randfiller.h"
#include "timecounter.h"

int main() {
	randfiller rf;
	timecounter tc;
	
	const int num_vettori = 100;
	
	std::ofstream file("Risultati_misura1.txt");
	file << "n\tbubble         selection        insertion        merge             quick\n";
	
	for (int n = 5; n <= 100; n += 5) {  //per ogni dimensione n
		std::vector<std::vector<int>> vec_test;  //inizializzo vettore di vettori
		vec_test.resize(num_vettori);   //creo 100 vettori vuoti
		
		for (int i = 0; i < num_vettori; i++) {  
		    vec_test[i].resize(n);  //li inizializzo con numeri casuali
		    rf.fill(vec_test[i], -200, 200);
		}
	
	    //creo le copie di vec_test per fare le misure
	    std::vector<std::vector<int>> vec_bubble = vec_test;
	    std::vector<std::vector<int>> vec_selection = vec_test;
	    std::vector<std::vector<int>> vec_insertion = vec_test;
	    std::vector<std::vector<int>> vec_merge = vec_test;
	    std::vector<std::vector<int>> vec_quick= vec_test;
	
	    tc.tic();
	    for (int i = 0; i < num_vettori; i++) {
		    bubble_sort(vec_bubble[i]);
	    }
	    double t_bubble = tc.toc()/num_vettori; 
	
	    tc.tic();
		for (int i = 0; i < num_vettori; i++) {
		    selection_sort(vec_selection[i]);
	    }
	    double t_selection = tc.toc()/num_vettori; 
	
	    tc.tic();
	    for (int i = 0; i < num_vettori; i++) {
		    insertion_sort(vec_insertion[i]);
	    }
	    double t_insertion = tc.toc()/num_vettori; 
	
	    tc.tic();
	    for (int i = 0; i < num_vettori; i++) {
		    mergesort(vec_merge[i], 0, vec_merge[i].size() - 1);
	    }
	    double t_merge = tc.toc()/num_vettori; 
	
	    tc.tic();
	    for (int i = 0; i < num_vettori; i++) {
		    quicksort(vec_quick[i], 0, vec_quick[i].size() - 1);
	    }
	    double t_quick = tc.toc()/num_vettori; 
	
	    file << n << "\t" 
	         << t_bubble << "\t" 
			 << t_selection << "\t" 
			 << t_insertion << "\t"
			 << t_merge << "\t"
			 << t_quick << "\n";
	}
	file.close();
	return 0;
}
	