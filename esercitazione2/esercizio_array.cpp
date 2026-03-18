#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
  static const int N = 7;
  double arr[N] = {1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8};
  
  double minimo = arr[0];
  for (int i=0; i<N; i++) {
    minimo = std::min(minimo, arr[i]);
	}
  std::cout << "Il minimo è" << " " << minimo << "\n";
  
  double massimo = arr[0];
  for (int i=0; i<N; i++) {
    massimo = std::max(massimo, arr[i]);
	}
  std::cout << "Il massimo è" << " " << massimo << "\n";
  
  double somma = 0;
  for (int i=0; i<N; i++) {
    somma += arr[i];
	}
  double media = somma/N;
  std::cout << "La media è" << " " << media << "\n";
  
  double somma_scarti = 0;
  for (int i=0; i<N; i++) {
    somma_scarti += (arr[i]-media)*(arr[i]-media);
	}
  double stdev = std::sqrt(somma_scarti/N);
  std::cout << "La deviazione standard è" << " " << stdev << "\n";
    
}