// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <vector>


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

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
