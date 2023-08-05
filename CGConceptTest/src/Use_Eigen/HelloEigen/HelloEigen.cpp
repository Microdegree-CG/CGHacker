#include <iostream>

#include "cg.h"
#include "Eigen/Dense"


// A rule for thumb is to use fixed-size matrices for size 4-by-4 and smaller.


int main()
{
	CG::Log::Init();
	CG_INFO("Hello Eigen");
	Eigen::MatrixXd m(2, 2);

	m(0, 0) = 3;
	m(1, 0) = 2.5;
	m(0, 1) = -1;
	m(1, 1) = m(1, 0) + m(0, 1);
	std::cout << m << std::endl;

	return 0;
}
