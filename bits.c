/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /* using de Morgan's Law: x&y == ~(~(x&y)) == ~((~x)|(~y)) */
  return ~((~x)|(~y));
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /* little endian. x contains 4 bytes.
   * 8 bit shift '<<' operation == 1 byte shift operation.
   * (*8) == (<<3)
   * 1 byte masking(&0xFF) the result, return. */
  int bitshiftNUM = n << 3;
  int mask = 0xFF;

  return ((x&(mask<<bitshiftNUM))>>bitshiftNUM)&mask;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  /* this function consists 'MSB copying problem'
   * solution: mask the result */
  int mask = ~((0x01 << 31) >> n << 1);

  return (x >> n) & mask;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /* solution: merge the bitCount.
   * initial - 0 or 1
   * next - 00 or 01 or 10
   * next - 0000 or 0001 or 0010 or 0011 or 0100 */
  int mask0101 = 0x55 + (0x55<<8);
  int mask0011 = 0x33 + (0x33<<8);
  int mask1111 = 0x0F + (0x0F<<8);
  int mask00FF = 0xFF + (0xFF<<16);
  int maskFFFF = 0xFF + (0xFF<<8);
  mask0101 = mask0101 + (mask0101<<16);
  mask0011 = mask0011 + (mask0011<<16);
  mask1111 = mask1111 + (mask1111<<16);

  x = (x&mask0101) + ((x>>1)&mask0101);
  x = (x&mask0011) + ((x>>2)&mask0011);
  x = (x&mask1111) + ((x>>4)&mask1111);
  x = (x&mask00FF) + ((x>>8)&mask00FF);
  x = (x&maskFFFF) + ((x>>16)&maskFFFF);
  return x;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  /* merge bits with OR(|) without masking.
   * return the difference to the 0x01 of LSB. */
  x = (x>>1) | x;
  x = (x>>2) | x;
  x = (x>>4) | x;
  x = (x>>8) | x;
  x = (x>>16) | x;
  return (x^0x01)&0x01;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /* the minimum two's complement integer is 1000000...0
   * for 32 bit int type, it is 0x80000000. 
   * which has 1=MSB, else 0 (31). */
  return 0x01<<31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  /* truncating front, test if same (== XNOR) */
  int front_n = 33 + (~n);

  return !(x ^ ((x << front_n) >> front_n));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  /* returns x>>n for positive.
   * returns (x+n1s) >> n for negative(round toward zero).
   * making n1s: 1<<n (=pwr(2,n)) + ~0 (-1)
   * negative condition: mask 32 MSB's */
  int MSBmask = x>>31;
  int n1s = (0x01<<n) + (~0);

  n1s = n1s & MSBmask;

  return (x+n1s) >> n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /* 2's complement: x + negate(x) = 0
   * x + ~x + 1 == 0. */
  return (~x) + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  /* check MSB of x, use !
   * if x==0, return 0. -> !!x is 0 if and only if x=0 */
  return (!(x>>31))&(!!x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /* issue: overflow
   * solution: check MSBs(signs) of x, y, y-x.
   * x-y's MSB is 0 when x >= y. (when overflow does not occur)
   * y-x's MSB is 0 when y >= x. (when ~)
   * overflow does not occur condition: both MSB are the same.
   * overflow occurs if only x & y MSB differs.
   * different MSB indicates which is the 'less' one.
   *   xMSB=1, yMSB=0 -> return 1 */
  int differ = y + (~x) + 1;
  int guessFromMSBofYminusX = !(differ>>31);

  int xMSB = x>>31;
  int yMSB = y>>31;
  int xyMSBdiffer = xMSB ^ yMSB;

  int noOverflowCmp = (!xyMSBdiffer) & guessFromMSBofYminusX;
  int overflowCmp = xyMSBdiffer & xMSB & 0x01;
  return noOverflowCmp + overflowCmp;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  /* issue: find the largest significant '1' by using bit ops.
   * finding '1' check function: '!' -> returns 0 if at least one 1.
   * divide and conquer. check 16bits, then check 8bits, ...
   * x > 0 -> MSB == 0 */
  int result = 0;
  int left = x>>16;
  int right = x & ((0xFF<<8) + 0xFF);
  int check_mask = ~(((!left)<<31)>>31);

  x = (check_mask & left) + ((~check_mask) & right);
  result = check_mask & 16; /* result was 0. */

  /* '8' part */
  left = x>>8;
  right = x & 0xFF;
  check_mask = ~(((!left)<<31)>>31);

  x = (check_mask & left) + ((~check_mask) & right);
  result = result + (check_mask & 8);

  /* '4' part */
  left = x>>4;
  right = x & 0x0F;
  check_mask = ~(((!left)<<31)>>31);

  x = (check_mask & left) + ((~check_mask) & right);
  result = result + (check_mask & 4);

  /* '2' part */
  left = x>>2;
  right = x & 0x03;
  check_mask = ~(((!left)<<31)>>31);

  x = (check_mask & left) + ((~check_mask) & right);
  result = result + (check_mask & 2);

  /* '1' part : we only need 'left'
   * no check, because left & right is 1 bit. */
  left = x>>1;
  result = result + left;

  return result;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  /* return MSB-inversed uf if it is not NaN.
   * return uf if it is NaN.
   * NaN == all 1's in exponent && not zero of frac. */
  int frac_mask = (1<<23) - 1;
  int exp_mask = 0xFF << 23;
  if (((exp_mask & uf) == exp_mask) && (frac_mask & uf))
    return uf;

  return uf^(1<<31);
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  /* issue #1: conversion into sign&mag expression
   * issue #2: calculation of 'exp' part.
   * issue #3: truncation rounding from mag >> 8 */
  int position = 0;
  int MSB1 = 1<<31;
  int roundbit;
  int stickybit;
  int rounding;

  /* sign&mag expression
   * problem: tmin(0x80000000). */
  int MSBmask = x>>31;
  int mag = (MSBmask & (-x)) + ((~MSBmask) & x);

  if (x==MSB1) /* tmin: exp == 127 + 31 == 158, MSB = 1 */
    return MSB1 + (158<<23);

  /* truncation, calc exp by the position of leading 1 
   * problem: zero(0x00000000 -> no leading 1) */
  if (x==0)
    return 0;

  MSBmask = MSB1;

  while (!(mag & MSBmask)) {
    MSBmask = MSBmask>>1;
    position++;
  }

  mag = mag<<position;
  roundbit = mag&0x80;
  stickybit = mag&0x7f;
  mag = mag>>8;
  rounding = (((mag&0x01)&&roundbit) || (roundbit&&stickybit));

  return (x&MSB1) + ((158-position)<<23) + (mag&0x7fffff) + rounding;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  /* return exp = exp+1
   * if NaN, return uf. (+, if inf, return uf.)
   * if +-0, return uf. 
   * if exp == 0, return frac<<1 */
  int exp_mask = 0xFF << 23;
  int MSB = uf & (0x01<<31);
  if ((uf & exp_mask) == exp_mask)
    return uf;

  if ((uf ^ MSB) == 0)
    return uf;

  if (!(uf & exp_mask))
    return MSB + (uf<<1);

  return uf + (1<<23);
}
