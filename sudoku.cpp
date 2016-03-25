#include "stdafx.h"

_sudoku::_sudoku(const int matrix[])
{
	for (int ii = 0; ii < 81; ii++)
		__sudokuMatrix[ii] = matrix[ii];
}

_sudoku::_sudoku(const std::vector<int> &matrix)
{
	if (matrix.size() != 81)
		throw std::logic_error("The Sudoku Matrix must has 81 elements.");
	for (int ii = 0; ii < 81; ii++)
		__sudokuMatrix[ii] = matrix[ii];
}

int _sudoku::addrow(const int position, const int num,
	const int linkrow, std::vector<nonZeroPosition> &vec,
	std::map<int, element> &index)
{
	int row, col, uni;
	nonZeroPosition node;
	element ele;

	row = (position - 1) / 9 + 1;
	col = position - 9 * (row - 1);
	uni = ((row - 1) / 3) * 3 + ((col - 1) / 3) + 1;

	//column 1-81
	node.row = linkrow;
	node.column = position;
	vec.push_back(node);

	//column 82-162
	node.row = linkrow;
	node.column = 72 + row * 9 + num;
	vec.push_back(node);

	//column 163-243
	node.row = linkrow;
	node.column = 153 + col * 9 + num;
	vec.push_back(node);

	//column 244-324
	node.row = linkrow;
	node.column = 234 + uni * 9 + num;
	vec.push_back(node);

	ele.eleposition = position;
	ele.elenumber = num;
	index[linkrow] = ele;

	return 0;
}

int _sudoku::convert(std::vector<nonZeroPosition> &exa, std::map<int, element> &index)
{
	int linkrow = 0;

	exa.clear();
	index.clear();

	for (int ii = 0; ii < 81; ii++)
	{
		if (__sudokuMatrix[ii] != 0)
		{
			addrow(ii + 1, __sudokuMatrix[ii], ++linkrow, exa, index);
		}
		else
		{
			for (int jj = 1; jj < 10; jj++)
			{
				addrow(ii + 1, jj, ++linkrow, exa, index);
			}
		}
	}

	return linkrow;
}

int _sudoku::solve(int result[])
{
	std::vector<nonZeroPosition> exactCoverMatrix;
	std::map<int, element> index;
	std::vector<int> exactCoverResult;
	int exactCoverMatrixRowNumber, flag;

	exactCoverMatrixRowNumber = convert(exactCoverMatrix, index);
	//Create an exact cover problem matrix
	ExactCover exactCover(exactCoverMatrix, exactCoverMatrixRowNumber, 324);
	//Solve it!
	flag = exactCover.solve(exactCoverResult);

	//if there is at least one solution.
	if (flag == 1)
	{
		for (int ii = 0; ii < 81; ii++)
			result[index[exactCoverResult.at(ii) - 1].eleposition - 1] = index.at(exactCoverResult.at(ii) - 1).elenumber;
		return 1;
	}
	return 0;
}

int _sudoku::solve(std::vector<int> &result)
{
	int res[81], flag;
	flag = this->solve(res);
	//if there is at least one solution.
	if (flag)
		return 0;

	for (int ii = 0; ii < 81; ii++)
		result[ii] = res[ii];
	return 1;
}
