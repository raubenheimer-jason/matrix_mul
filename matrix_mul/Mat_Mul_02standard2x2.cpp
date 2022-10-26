#include "Mat_Mul_02standard2x2.hpp"
#include "Mat_Utils.hpp"

/*
Taken from https://www.deepmind.com/blog/discovering-novel-algorithms-with-alphatensor
*/
int mat_mul_02standard2x2(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C)
{

	// first check that matrix dimensions are correct
	if (!mat_mul_check_dims(A, B))
		return -1; // error

	// make sure matrices are both 2x2
	if (!mat_square_check_size(A, 2) && !mat_square_check_size(B, 2))
		return -1; // error

	// rows at A.at(0, 1, 2, ...)
	// cols at A.at(0).at(0, 1, 2, ...)  <-- these are the cols for row 0

	int h1 = A.at(0).at(0) * B.at(0).at(0);
	int h2 = A.at(0).at(0) * B.at(0).at(1);
	int h3 = A.at(0).at(1) * B.at(1).at(0);
	int h4 = A.at(0).at(1) * B.at(1).at(1);
	int h5 = A.at(1).at(0) * B.at(0).at(0);
	int h6 = A.at(1).at(0) * B.at(0).at(1);
	int h7 = A.at(1).at(1) * B.at(1).at(0);
	int h8 = A.at(1).at(1) * B.at(1).at(1);

	C.push_back({ (h1 + h3), (h2 + h4) }); // {c11, c12}
	C.push_back({ (h5 + h7), (h6 + h8) }); // {c21, c22}
}