#ifndef SUDOKU_H
#define SUDOKU_H

#include "stdafx.h"

class element
{
public:
	int position;
	int number;
};

class _sudoku :implements iSudoku
{
private:
	int __sudokuMatrix[81];

	int addrow(const int position, const int num, const int linkrow, std::vector<nonZeroPosition> &vec, std::vector<element> &index);
	int convert(std::vector<nonZeroPosition> &exa, std::vector<element> &index);

public:
	_sudoku(const int matrix[]);
	_sudoku(const std::vector<int> &matrix);
	~_sudoku(){}

	int solve(std::vector<int> &res);
	int solve(int *res);
};

#endif