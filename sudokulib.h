#ifndef SUDOKU_LIB_H
#define SUDOKU_LIB_H

#include <vector>

#ifndef DeclareInterface
#define DeclareInterface(name) class name { \
public: \
	virtual ~name() {}
#endif

#ifndef DeclareBasedInterface
#define DeclareBasedInterface(name, base) class name : \
	public base{ \
public: \
	virtual ~name() {}
#endif

#ifndef EndInterface
#define EndInterface };
#endif

#ifndef implements
#define implements public
#endif

DeclareInterface(iSudoku)
virtual int solve(std::vector<int> &res) = 0;
virtual int solve(int *res) = 0;
EndInterface

class Sudoku :implements iSudoku
{
private:
	iSudoku* ptr_iSudoku;

public:
	Sudoku(const int matrix[]);
	Sudoku(const std::vector<int> &matrix);
	~Sudoku();

	int solve(std::vector<int> &res);
	int solve(int *res);
};

#endif
