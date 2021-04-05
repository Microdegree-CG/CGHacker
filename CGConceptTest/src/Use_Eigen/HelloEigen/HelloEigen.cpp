#include <iostream>

#include "Eigen/Dense"


int main()
{
	Eigen::MatrixXd mat(3, 3);
	mat(0, 0) = 1.3;

	std::cout << mat << std::endl;
	return 0;
}