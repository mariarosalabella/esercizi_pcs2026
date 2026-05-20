#pragma once
#include <Eigen/Dense>

int gradiente_coniugato(const Eigen::MatrixXd& A, 
                        const Eigen::VectorXd& b, 
						Eigen::VectorXd& x, 
						const int iter_max, 
						const double res_tol) {
	
	Eigen::VectorXd res = b - A * x;
	double res_norm_0 = res.norm();
	
	Eigen::VectorXd p = res; //direzione di discesa
	
	int iter = 0;
	
	while (iter < iter_max && res.norm() > res_tol * res_norm_0) {
		Eigen::VectorXd Ap = A * p;
		
		const double alpha_k = (p.dot(res))/(p.dot(Ap));
		x = x + alpha_k * p;
		Eigen::VectorXd new_res = b - A * x;
		
		const double beta_k = (p.dot(A * new_res))/(p.dot(Ap));
		p = new_res - beta_k * p;
		res = new_res;
		iter++;
	}
	return iter;	
}	
