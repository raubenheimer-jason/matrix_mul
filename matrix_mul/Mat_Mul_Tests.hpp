#pragma once

#include <vector>
#include <chrono>
#include <iostream>
#include <string>

#include "Mat_Utils.hpp"
#include "Mat_Mul_01basic.hpp"
#include "Mat_Mul_02standard2x2.hpp"

void test_template(const std::string test_name, int(*test_func)(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C), const std::vector<std::vector<int>> A, const std::vector<std::vector<int>> B);
void Mat_Mul_01basic_Test(const std::vector<std::vector<int>> A, const std::vector<std::vector<int>> B);