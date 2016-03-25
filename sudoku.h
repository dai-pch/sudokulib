#ifndef SUDOKU_H
#define SUDOKU_H

#include "stdafx.h"

typedef std::pair<int, int> element;
#define eleposition first
#define elenumber second

class _sudoku :implements iSudoku
{
private:
	int __sudokuMatrix[81];

	int addrow(const int position, const int num, const int linkrow, std::vector<nonZeroPosition> &vec, std::map<int, element> &index);
	int convert(std::vector<nonZeroPosition> &exa, std::map<int, element> &index);

public:
	_sudoku(const int matrix[]);
	_sudoku(const std::vector<int> &matrix);
	~_sudoku(){}

	int solve(std::vector<int> &result);
	int solve(int result[]);
};

#endif