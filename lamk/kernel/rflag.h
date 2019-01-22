/*-------------------------------------------------
* Author: Chris Pro
 * LAMK SYSTEM supports: Intel: X86 X64  and Amd: X86 X64 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
-------------------------------------------------*/
#pragma once

#ifdef _LOAD_VOL_FLAG
#define _LOAD_VOL_FLAG


const int carry_flag = 0;
const int reserved = 1;
const int parity_flag = 2;
const int reserved = 3;
const int auxiliary_carry_flag = 4;
const int reserved = 5;
const int zero_flag = 6;
const int sign_flag = 7;
const int trap_flag = 8;
const int interrupt_enable_flag = 9;
const int direction_flag = 10;
const int owerflow_flag = 11;
const int privilege_level_bit_0 = 12;
const int privilege_level_bit_1 = 13;
const int neted_task = 14;
const int reserved = 15;
const int resume_flag = 16; /* BOOL: 0 */
const int virtual_8086_Mode = 17;
const int alignment_check = 18;
const int virtual_interrupt_flag = 19;
const int virtual_interrupt_pending = 20;
const int id_flag = 21;
const int reserved = 22;




#endif /* _LOAD_VOL*/