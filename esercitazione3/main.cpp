#include <iostream>
#include "rational.hpp"

int main() {
	rational<int> r1(1,2);
	rational<int> r2(1,4);
	
    //Test semplificazione
    rational<int> r3(3, 6); 
    std::cout << r3 << "\n"; 

    //Test Inf e NaN
    rational<int> inf(1, 0);
    rational<int> nan(0, 0);
    rational<int> zero(0, 5);

    std::cout << inf << "\n";
    std::cout << nan << "\n";

    //Test operazioni con casi speciali
    std::cout << (r1 + inf) << "\n"; 
    std::cout << (inf * zero) << "\n"; 
    
	//Test somma e sottrazione
	std::cout << (r1+r2) << "\n";
	std::cout << (r1-r2) << "\n";
    //Test moltiplicazione e divisione
    std::cout << (r1*r2) << "\n";
    std::cout << (r1 / r2) << "\n";

    return 0;
}