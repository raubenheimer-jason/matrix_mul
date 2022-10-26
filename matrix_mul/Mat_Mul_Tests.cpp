#include "Mat_Mul_Tests.hpp"

void mat_mul_01basic_Test(const std::vector<std::vector<int>> A, const std::vector<std::vector<int>> B)
{
	test_template("mat_mul_01basic_Test", mat_mul_01basic, A, B);
}

void mat_mul_02standard2x2_Test(const std::vector<std::vector<int>> A, const std::vector<std::vector<int>> B)
{
	test_template("mat_mul_02standard2x2_Test", mat_mul_02standard2x2, A, B);
}

void test_template(const std::string test_name, int(*test_func)(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C), const std::vector<std::vector<int>> A, const std::vector<std::vector<int>> B)
{
	std::cout << "Testing: " << test_name << std::endl;

	std::vector<std::vector<int>> C;
	auto start = std::chrono::high_resolution_clock::now();
	int result = test_func(A, B, C);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	if (result == -1)
		std::cout << "dim error\n" << std::endl;

	//std::cout << "C." << std::endl;
	std::cout << "C." << std::endl;
	mat_print(C);

	// To get the value of duration use the count()
	// member function on the duration object
	std::cout << "time: " << duration.count() << " us" << std::endl;
	std::cout << "------------------------------------\n" << std::endl;

}


//void Mat_Mul_01basic_Test(const std::vector<std::vector<int>> A, const std::vector<std::vector<int>> B)
//{
//	// Mat_Mul_01basic
//	std::vector<std::vector<int>> C;
//	auto start = std::chrono::high_resolution_clock::now();
//	int result = mat_mul_01basic(A, B, C);
//	auto stop = std::chrono::high_resolution_clock::now();
//	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//	if (result == -1)
//		std::cout << "dim error\n" << std::endl;
//
//	//std::cout << "C." << std::endl;
//	std::cout << "C." << std::endl;
//	mat_print(C);
//
//	// To get the value of duration use the count()
//	// member function on the duration object
//	std::cout << "time: " << duration.count() << " us" << std::endl;
//}