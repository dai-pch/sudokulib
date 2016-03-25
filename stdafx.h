// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <vector>


// TODO:  在此处引用程序需要的其他头文件

#include <stdexcept>

#include "sudokulib.h"
#include "lib/exactcoverlib.h"
#include "sudoku.h"

#ifdef _DEBUG
#pragma comment (lib, "./lib/debug/exactcoverlib.lib")
#else
#pragma comment (lib, "./lib/release/exactcoverlib.lib")
#endif
//#define _DEBUG_MODE
