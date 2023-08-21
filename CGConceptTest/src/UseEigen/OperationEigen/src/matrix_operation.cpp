#include "GLCore.h"
#include "Eigen/Dense"


int main()
{
	GLCore::Log::Init();

	CG_INFO("Matrix arithmatic operation:");
	Eigen::MatrixXd m1(3, 2);
	m1 << 4, 5, 8, 3, 5, 0;
	std::cout << m1 << std::endl;
	
	CG_WARN("Matrix sub operation:");
	Eigen::MatrixXd m2(m1.rows(), m1.cols());
	m2 = m1 - Eigen::MatrixXd::Constant(m1.rows(), m1.cols(), 1.2);
	std::cout << m2 << std::endl;

	CG_WARN("Matrix add operation:");
	std::cout << m1 + m1 << std::endl;


	CG_WARN("Matrix multi (valut) operation:");
	std::cout << m1 * 3 << std::endl;
	CG_WARN("Matrix multi (matrix) operation:");
	std::cout << m1 * m1.transpose() << std::endl;

	CG_WARN("Matrix div operation:");
	std::cout << m1 / 3 << std::endl;

	return 0;
}