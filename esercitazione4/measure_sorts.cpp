#include <iostream>
#include <vector>
#include <algorithm>

#include "sorting_algorithms.hpp"
#include "is_sorted.hpp"
#include "randfiller.h"
#include "timecounter.h"

int main() {
	randfiller rf;
	timecounter tc;
	
	
	for (int n = 4; n <= 8192; n *= 2) {
		int size = n;
		std::vector<int> vec_test;
		vec_test.resize(size);
		rf.fill(vec_test, -1000, 1000);
		
		//creo una copia di vec_test per ciascun test in modo da avere test equi
		std::vector<int> v1 = vec_test;
		std::vector<int> v2 = vec_test;
		std::vector<int> v3 = vec_test;
		std::vector<int> v4 = vec_test;
		
		//misura bubble sort
		tc.tic();
		bubble_sort(v1);
		double t_bubble = tc.toc();
		
		//misura insertion sort
		tc.tic();
		insertion_sort(v2);
		double t_insertion = tc.toc();
		
		//misura selection sort
		tc.tic();
		selection_sort(v3);
		double t_selection = tc.toc();
		
		//misura std::sort()
		tc.tic();
		std::sort( v4.begin(), v4.end() );
		double t_sort = tc.toc();	
		
		std::cout << "Dimensione del vettore: " << n << "\n";
		std::cout << "Tempo bubble sort: " << t_bubble << "\n";
		std::cout << "Tempo insertion sort: " << t_insertion << "\n";
		std::cout << "Tempo selection sort: " << t_selection << "\n";
		std::cout << "Tempo std::sort(): " << t_sort << "\n";
	}
	return 0;
}
		
		

