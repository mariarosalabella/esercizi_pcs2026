#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char*argv[])
{
  if (argc != 2) {
  std::cerr << "Errore: specificare il nome del file\n";
  }
  
  std::string filename = argv[1];
  std::ifstream ifs(filename);
  if (!ifs.is_open()){
      std::cerr << "Errore: non è stato possibile aprire il file" << filename << "\n";
  }
  else {
	  while ( !ifs.eof() ) {
		  std::string città;
	      double temp[4];
		  double somma = 0;
		  ifs >> città >> temp[0] >> temp[1] >> temp[2] >> temp[3];
		  for (int i=0; i<4; i++) {
		    somma += temp[i];
	      }
	  double media = somma/4.0;
	  std::cout << città << " " << media << "\n";
      }
  return 0;
  }
}
	  

