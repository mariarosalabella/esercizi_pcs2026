#include <iostream>
#include <Eigen/Dense>
#include "gradiente_coniugato.hpp"

int main() {
	
	unsigned int n = 7;
	//costruisco la matrice simmetrica, def positiva
	Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
	Eigen::MatrixXd A = B.transpose() * B;
	
	Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n); //soluzione esatta
	
	Eigen::VectorXd b = A * x_ex;
	
	Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
	const int iter_max = 10000;
	const double res_tol = 1e-12;
	int iter = gradiente_coniugato(A, b, x, iter_max, res_tol);
	
	const auto err_rel =
        (x_ex.norm() == 0.0) //se la soluzione esatta è il vettore nullo
            ? (x - x_ex).norm() //fai errore assoluto
            : (x - x_ex).norm() / x_ex.norm(); //altrimenti relativo

	std::cout.precision(4);
	std::cout << std::scientific<< "soluzione: " << x << std::endl;
	std::cout << std::scientific<< "errore relativo " << err_rel << std::endl;
	std::cout << std::scientific<< "numero di iterazioni: " << iter << std::endl;
	
	return 0;
}