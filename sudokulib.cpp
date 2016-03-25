#include "stdafx.h"

Sudoku::Sudoku(const int matrix[])
{
	ptr_iSudoku = new _sudoku(matrix);
}

Sudoku::Sudoku(const std::vector<int> &matrix)
{
	ptr_iSudoku = new _sudoku(matrix);
}

Sudoku::~Sudoku()
{
	delete ptr_iSudoku;
}

int Sudoku::solve(std::vector<int> &result)
{
	return ptr_iSudoku->solve(result);
}

int Sudoku::solve(int result[])
{
	return ptr_iSudoku->solve(result);
}
