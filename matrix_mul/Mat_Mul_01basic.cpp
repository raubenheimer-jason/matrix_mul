
#include "Mat_Mul_01basic.hpp"
#include "Mat_Utils.hpp"

// Function multiplies two matrixes
int mat_mul_01basic(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C)
{
	// first check that matrix dimensions are correct
	if (!mat_mul_check_dims(A, B))
		return -1; // error

	// C holds the result, make sure it is empty
	//C = { {} };

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