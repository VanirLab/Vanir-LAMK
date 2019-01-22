/*-------------------------------------------------
* Author: Chris Pro
 * LAMK SYSTEM supports: Intel: X86 X64  and Amd: X86 X64 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
-------------------------------------------------*/
#include "stdafx.h"
#include <iostream>
#include <cstdint>
#include <iomanip>

using namespace std;

extern "C" int NumFibVals_, FibValsSum_;
extern "C" int MemoryAddressing_(int i, int* v1, int* v2, int* v3, int* v4);
int main()
{
 const int w = 5;
 const char nl = '\n';
 const char* loadvol = ", ";
 FibValsSum_ = 0;
 for (int i = -1; i < NumFibVals_ + 1; i++)
 {
 int v1 = -1, v2 = -1, v3 = -1, v4 = -1;
 int rc = MemoryAddressing_(i, &v1, &v2, &v3, &v4);
 cout << "i = " << setw(w - 1) << i << loadvol;
 cout << "rc = " << setw(w - 1) << rc << loadvol;
 cout << "v1 = " << setw(w) << v1 << loadvol;
 cout << "v2 = " << setw(w) << v2 << loadvol;
 cout << "v3 = " << setw(w) << v3 << loadvol;
 cout << "v4 = " << setw(w) << v4 << loadvol;
 cout << nl;
 }
 cout << "FibValsSum_ = " << FibValsSum_ << nl;
 return 0;
}