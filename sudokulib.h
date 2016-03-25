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
virtual int solve(std::vector<int> &result) = 0;
virtual int solve(int result[]) = 0;
EndInterface

class Sudoku :implements iSudoku
{
private:
	iSudoku* ptr_iSudoku;

public:
	Sudoku(const int matrix[]);
	Sudoku(const std::vector<int> &matrix);
	~Sudoku();

	int solve(std::vector<int> &result);
	int solve(int result[]);
};

#endif
