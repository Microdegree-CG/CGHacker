#include <iostream>

#include "Eigen/Dense"
#include "cg.h"


// A rule for thumb is to use fixed-size matrices for size 4-by-4 and smaller.

void CreateVector()
{
	Eigen::Vector<double, 5> colV;
	Eigen::RowVector<double, 5> rowV;

	std::cout << colV;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << rowV;
	std::cout << std::endl;
}

void  CreateMatrix()
{
	Eigen::Matrix<double, 5, 3> m1;
	std::cout << m1 << std::endl;
}

int main()
{
	CG::Log::Init();
	CG_INFO("Hello Eigen");

	CG_WARN("Create Fix size matrix by Eigen::Matrix<double, 5, 3> ");
	CreateMatrix();
	CG_WARN("Create Fix size col/row vector by Eigen::Vector<double, 5> ");
	CreateVector();

	return 0;
}