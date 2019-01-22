/*-------------------------------------------------
* Author: Chris Pro
 * LAMK SYSTEM supports: Intel: X86 X64  and Amd: X86 X64 
 * zqmem.h
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
-------------------------------------------------*/
#include "stdafx.h"
#include <cstdint>
#include <iostream>
#include <iomanip>
#include "zqmem.h"
using namespace std;
extern "C" void Avx512PackedMathI16_(const ZmmVal* a, const ZmmVal* b, ZmmVal c[6]);
extern "C" void Avx512PackedMathI64_(const ZmmVal* a, const ZmmVal* b, ZmmVal c[5],
uint32_t opmask);
void Avx512PackedMathI16(void)
{
 alignas(64) ZmmVal a;
 alignas(64) ZmmVal b;
 alignas(64) ZmmVal c[6];
 a.m_I16[0] = 10; b.m_I16[0] = 100;
 a.m_I16[1] = 20; b.m_I16[1] = 200;
 a.m_I16[2] = 30; b.m_I16[2] = 300;
 a.m_I16[3] = 40; b.m_I16[3] = 400;
 a.m_I16[4] = 50; b.m_I16[4] = 500;
 a.m_I16[5] = 60; b.m_I16[5] = 600;
 a.m_I16[6] = 70; b.m_I16[6] = 700;
 a.m_I16[7] = 80; b.m_I16[7] = 800;
 a.m_I16[8] = 1000; b.m_I16[8] = -100;
 a.m_I16[9] = 2000; b.m_I16[9] = 200;
 a.m_I16[10] = 3000; b.m_I16[10] = -300;
 a.m_I16[11] = 4000; b.m_I16[11] = 400;
 a.m_I16[12] = 5000; b.m_I16[12] = -500;
 a.m_I16[13] = 6000; b.m_I16[13] = 600;
 a.m_I16[14] = 7000; b.m_I16[14] = -700;
 a.m_I16[15] = 8000; b.m_I16[15] = 800;
 a.m_I16[16] = -1000; b.m_I16[16] = 100;
 a.m_I16[17] = -2000; b.m_I16[17] = -200;
 a.m_I16[18] = 3000; b.m_I16[18] = 303;
 a.m_I16[19] = 4000; b.m_I16[19] = -400;
 a.m_I16[20] = -5000; b.m_I16[20] = 500;
 a.m_I16[21] = -6000; b.m_I16[21] = -600;
 a.m_I16[22] = -7000; b.m_I16[22] = 700;
 a.m_I16[23] = -8000; b.m_I16[23] = 800;
 a.m_I16[24] = 30000; b.m_I16[24] = 3000; // add overflow
 a.m_I16[25] = 6000; b.m_I16[25] = 32000; // add overflow
 a.m_I16[26] = -25000; b.m_I16[26] = -27000; // add overflow
 a.m_I16[27] = 8000; b.m_I16[27] = 28700; // add overflow
 a.m_I16[28] = 2000; b.m_I16[28] = -31000; // sub overflow
 a.m_I16[29] = 4000; b.m_I16[29] = -30000; // sub overflow
 a.m_I16[30] = -3000; b.m_I16[30] = 32000; // sub overflow
 a.m_I16[31] = -15000; b.m_I16[31] = 24000; // sub overflow
 Avx512PackedMathI16_(&a, &b, c);
 cout <<"\nResults for Avx512PackedMathI16\n\n";
 cout << " i a b vpaddw vpaddsw vpsubw vpsubsw vpminsw vpmaxsw\n";
 cout << "--------------------------------------------------------------------------\n";
 for (int i = 0; i < 32; i++)
 {
 cout << setw(2) << i << ' ';
 cout << setw(8) << a.m_I16[i] << ' ';
 cout << setw(8) << b.m_I16[i] << ' ';
 cout << setw(8) << c[0].m_I16[i] << ' ';
 cout << setw(8) << c[1].m_I16[i] << ' ';
 cout << setw(8) << c[2].m_I16[i] << ' ';
 cout << setw(8) << c[3].m_I16[i] << ' ';
 cout << setw(8) << c[4].m_I16[i] << ' ';
 cout << setw(8) << c[5].m_I16[i] << '\n';
 }
}
void Avx512PackedMathI64(void)
{
 alignas(64) ZmmVal a;
 alignas(64) ZmmVal b;
 alignas(64) ZmmVal c[6];
 uint32_t opmask = 0x7f;
 a.m_I64[0] = 64; b.m_I64[0] = 4;
 a.m_I64[1] = 1024; b.m_I64[1] = 5;
 a.m_I64[2] = -2048; b.m_I64[2] = 2;
 a.m_I64[3] = 8192; b.m_I64[3] = 5;
 a.m_I64[4] = -256; b.m_I64[4] = 8;
 a.m_I64[5] = 4096; b.m_I64[5] = 7;
 a.m_I64[6] = 16; b.m_I64[6] = 3;
 a.m_I64[7] = 512; b.m_I64[7] = 6;
 Avx512PackedMathI64_(&a, &b, c, opmask);
 cout << "\nResults for Avx512PackedMathI64\n\n";
 cout << "op_mask = " << hex << opmask << dec << '\n';
 cout << " i a b vpaddq vpsubq vpmullq vpsllvq vpsravq vpabsq\n";
 cout << "----------------------------------------------------------------------\n";
 for (int i = 0; i < 8; i++)
 {
 cout << setw(2) << i << ' ';
 cout << setw(6) << a.m_I64[i] << ' ';
 cout << setw(6) << b.m_I64[i] << ' ';
 cout << setw(8) << c[0].m_I64[i] << ' ';
 cout << setw(8) << c[1].m_I64[i] << ' ';
 cout << setw(8) << c[2].m_I64[i] << ' ';
 cout << setw(8) << c[3].m_I64[i] << ' ';
 cout << setw(8) << c[4].m_I64[i] << ' ';
 cout << setw(8) << c[5].m_I64[i] << '\n';
 }
}
int main()
{
 Avx512PackedMathI16();
 Avx512PackedMathI64();
 return 0;
}