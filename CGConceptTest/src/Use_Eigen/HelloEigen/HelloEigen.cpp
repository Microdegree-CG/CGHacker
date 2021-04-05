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

void InitMatrix()
{
	Eigen::Matrix3d m;
	m << 1, 2, 3,
		4, 5, 6,
		7, 8, 9;

	std::cout << m << std::endl;
}

void GetMatrixInfo()
{
	Eigen::Matrix3d m;
	m << 1, 2, 3,
		4, 5, 6,
		7, 8, 9;

	std::cout << "rows: " << m.rows() << "\ncols: " <<  m.cols() << "\nsize: " << m.size() << std::endl;
}

void CreateMatrixUseDefaultMethod()
{
	auto m1 = Eigen::MatrixXd::Random(4, 4);
	auto m2 = Eigen::MatrixXd::Constant(4, 4, 10);
	auto m3 = Eigen::MatrixXd::Zero(4, 4);
	auto m4 = Eigen::MatrixXd::Ones(4, 4);
	auto m5 = Eigen::MatrixXd::Identity(4, 4);
	auto m6 = Eigen::MatrixXd::LinSpaced(100, 1, 50);
}

int main()
{
	CG::Log::Init();
	CG_INFO("Hello Eigen");

	CG_WARN("Create Fix size matrix by Eigen::Matrix<double, 5, 3> ");
	CreateMatrix();
	CG_WARN("Create Fix size col/row vector by Eigen::Vector<double, 5> ");
	CreateVector();
	CG_WARN("Init Matrix by \"<<\" operator ");
	InitMatrix();

	CG_WARN("Get Matrix Info ");
	GetMatrixInfo();

	CG_WARN("Create Matrix Use default method");
	CreateMatrixUseDefaultMethod();

	return 0;
}