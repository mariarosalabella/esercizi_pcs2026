#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "sorting_algorithms.hpp"
#include "merge_quick.hpp"
#include "better_quicksort.hpp"

#include "randfiller.h"
#include "timecounter.h"

int main() {
	randfiller rf;
	timecounter tc;
	
	const int num_vettori = 100;
	
	std::ofstream file("Risultati_misura_definitiva.txt");
	file << "n\tbubble         selection        insertion        merge             quick         better_quick     std::sort\n";
	
	for (int n = 4; n <= 8192; n *= 2) {  //per ogni dimensione n
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
		std::vector<std::vector<int>> vec_better_quick= vec_test;
		std::vector<std::vector<int>> vec_stdsort= vec_test;
	
	
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
		
		tc.tic();
		for (int i = 0; i < num_vettori; i++) {
			better_quicksort(vec_better_quick[i], 0, vec_better_quick[i].size() - 1);
		}
		double t_better_quick = tc.toc()/num_vettori;
		
		tc.tic();
		for (int i = 0; i < num_vettori; i++) {
			std::sort(vec_stdsort[i].begin(), vec_stdsort[i].end());
		}
		double t_stdsort = tc.toc()/num_vettori;
	
	    file << n << "\t" 
	         << t_bubble << "\t" 
			 << t_selection << "\t" 
			 << t_insertion << "\t"
			 << t_merge << "\t"
			 << t_quick << "\t"
			 << t_better_quick << "\t"
			 << t_stdsort << "\n";
	}
	file.close();
	return 0;
}