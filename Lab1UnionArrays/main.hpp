#pragma once
#include <iostream>
#include <Windows.h>

void SetConsoleTheme();
void UnionArrays(const int iArray1[], const int iArray2[], const size_t& szArray1, const size_t& szArray2, int **ppiArrayResult, size_t& szArrayResultSize);
void ArrayOut(int iArrayResult[], const size_t& szArrayResultSize);