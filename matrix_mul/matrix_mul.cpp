// matrix_mul.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int mat_mul(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C);
bool mat_mul_check_dims(const std::vector<std::vector<int>>& A, const  std::vector<std::vector<int>>& B);
void mat_print(const std::vector<std::vector<int>>& A);

int main()
{
	//std::cout << "Hello World!\n";

	std::vector<std::vector<int>> A{ {1,2},{3,4},{5,6} };
	std::vector<std::vector<int>> B{ {5,6},{7,8} };

	std::cout << "A" << std::endl;
	mat_print(A);
	std::cout << "B" << std::endl;
	mat_print(B);


	std::vector<std::vector<int>> C{ {} };

	int result = mat_mul(A, B, C);

	if (result == -1)
		std::cout << "error" << std::endl;

	mat_print(C);



}

void mat_print(const std::vector<std::vector<int>>& A)
{
	//std::cout << "printing..." << std::endl;

	for (auto& r : A)
	{
		for (auto& e : r)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
}


bool mat_mul_check_dims(const std::vector<std::vector<int>>& A, const  std::vector<std::vector<int>>& B)
{
	// num columns of A must equal num rows of B

	if (A.at(0).size() == B.size())
		return true;

	return false;
}

// Function multiplies two matrixes
int mat_mul(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C)
{
	// first check that matrix dimensions are correct
	if (!mat_mul_check_dims(A, B))
		return -1; // error

	// C holds the result, make sure it is empty
	C = { {} };

	// for the first element of result, loop over each column in the first row of A, loop over each row in the first column of B

	size_t C_cols{ B.at(0).size() }; // Num of cols in B
	size_t C_rows{ A.size() }; // Num of rows in A

	std::cout << "C_cols: " << C_cols << std::endl;
	std::cout << "C_rows: " << C_rows << std::endl;


	size_t num_elements{};
	for (size_t i{}; i < (C_cols + C_rows); ++i)
	{
		num_elements++;
	}

	std::cout << "num_elements: " << num_elements << std::endl;

	return 0;
}