// matrix_mul.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <chrono> // for timing

#include "Mat_Utils.hpp"
#include "Mat_Mul_Tests.hpp"

int main()
{
	//std::cout << "Hello World!\n";

	//std::vector<std::vector<int>> A{ {1,2},{3,4},{5,6} };
	//std::vector<std::vector<int>> A{ {1,2},{3,4} };
	//std::vector<std::vector<int>> A{ {1,2,9},{3,4,9},{1,2,9},{3,4,9},{1,2,9},{3,4,9},{1,2,9},{3,4,9},{1,2,9},{3,4,9} };
	//std::vector<std::vector<int>> B{ {5,6,9,9,9,9,9},{7,8,9,9,9,9,9},{7,8,9,9,9,9,9} };

	std::vector<std::vector<int>> A;
	std::vector<std::vector<int>> B;

	mat_rand(10, 3, A);
	mat_rand(3, 7, B);

	std::cout << "A." << std::endl;
	mat_print(A);
	std::cout << "B." << std::endl;
	mat_print(B);

	Mat_Mul_01basic_Test(A, B);
}
