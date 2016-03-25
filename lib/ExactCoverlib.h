#ifndef EXACT_COVER_LIB_H
#define EXACT_COVER_LIB_H

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

class nonZeroPosition
{
public:
	int row;
	int column;
	bool operator < (const nonZeroPosition& element2);
};

DeclareInterface(iExactCover)
virtual int solve(std::vector<int> &res)=0;
EndInterface

class ExactCover:implements iExactCover
{
private:
	iExactCover* ptr_iExactCover;
public:
	ExactCover(const int matrix[], int m, int n);
	ExactCover(const std::vector<int> &matric, int m, int n);
	ExactCover(std::vector<nonZeroPosition> &matric, int m, int n);
	~ExactCover();

	int solve(std::vector<int> &res);
};

#endif
