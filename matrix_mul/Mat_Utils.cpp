
#include "Mat_Utils.hpp"

// make random matrix
void mat_rand(const int rows, const int cols, std::vector<std::vector<int>>& X, int start, int end)
{
	//X = { {} };

	for (int r{}; r < rows; ++r)
	{
		std::vector<int> row;
		for (int c{}; c < cols; ++c)
		{
			int random = start + (rand() % end);
			row.push_back(1);
		}
		X.push_back(row);
	}
}


void mat_print(const std::vector<std::vector<int>>& X)
{
	//std::cout << "printing..." << std::endl;

	for (auto& r : X)
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

	//std::cout << A.at(0).size() << "  " << B.size() << std::endl;

	if (A.at(0).size() == B.size())
		return true;

	return false;
}

bool mat_square_check_size(const std::vector<std::vector<int>>& A, const size_t size)
{
	if (A.size() == size && A.at(0).size() == size)
		return true;

	return false;
}