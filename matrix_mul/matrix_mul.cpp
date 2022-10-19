// matrix_mul.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <chrono> // for timing

int mat_mul(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C);
bool mat_mul_check_dims(const std::vector<std::vector<int>>& A, const  std::vector<std::vector<int>>& B);
void mat_print(const std::vector<std::vector<int>>& A);

int main()
{
	//std::cout << "Hello World!\n";

	//std::vector<std::vector<int>> A{ {1,2},{3,4},{5,6} };
	std::vector<std::vector<int>> A{ {1,2},{3,4} };
	std::vector<std::vector<int>> B{ {5,6},{7,8} };

	std::cout << "A." << std::endl;
	mat_print(A);
	std::cout << "B." << std::endl;
	mat_print(B);


	std::vector<std::vector<int>> C{ {} };

	auto start = std::chrono::high_resolution_clock::now();
	int result = mat_mul(A, B, C);
	auto stop = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	//if (result == -1)
		//std::cout << "error" << std::endl;

	//std::cout << "C." << std::endl;
	std::cout << "C.";
	mat_print(C);

	// To get the value of duration use the count()
	// member function on the duration object
	std::cout << "time: " << duration.count() << " us" << std::endl;
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
	std::cout << std::endl;
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

	size_t B_rows{ B.size() }; // Num of rows in B
	size_t A_cols{ A.at(0).size() }; // Num of cols in A

	//std::cout << "C_cols: " << C_cols << std::endl;
	//std::cout << "C_rows: " << C_rows << std::endl;


	// iterate over each row
	for (size_t r{}; r < C_rows; ++r)
	{
		std::vector<int> row;
		// iterate over each column
		for (size_t c{}; c < C_cols; ++c)
		{
			int element_result{};

			// then iterate over each column in A for the current row of C
			// and each row in B for the current column of C
			for (size_t cA{}, rB{}; cA < A_cols; ++cA, ++rB) // can also work for rB < B_rows
			{
				//std::cout << "ar: " << r << ", ac: " << cA << "  br: " << rB << " bc, " << c << "  --> ";
				//std::cout << A.at(r).at(cA) << "  " << B.at(rB).at(c) << std::endl;
				element_result += A.at(r).at(cA) * B.at(rB).at(c);
			}

			//std::cout << "----\n" << std::endl;

			row.push_back(element_result);
		}
		C.push_back(row);
	}

	return 0;
}