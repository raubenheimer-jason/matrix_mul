#pragma once

#include <vector>
#include <iostream>

// utility functions that are used with matrices

void mat_rand(const int rows, const int cols, std::vector<std::vector<int>>& X, int start = 0, int end = 9); // make random matrix
void mat_print(const std::vector<std::vector<int>>& X);
bool mat_mul_check_dims(const std::vector<std::vector<int>>& A, const  std::vector<std::vector<int>>& B);
bool mat_square_check_size(const std::vector<std::vector<int>>& A, const size_t size);



