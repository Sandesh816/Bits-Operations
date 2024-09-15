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
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
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
/* wchar_t uses Unicode 9.0.0.  Version 9.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, fourth edition, plus
   Amd. 1  and Amd. 2 and 273 characters from forthcoming  10646, fifth edition.
   (Amd. 2 was published 2016-05-01,
   see https://www.iso.org/obp/ui/#iso:std:iso-iec:10646:ed-4:v1:amd:2:v1:en) */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y){
       // (-a || -b) == -(a and b). So, one more not operation to get (a and b)                                                                                                                                       
       return ~(~x | ~y);
}
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  // - x & - y -> -(x | y). So, one more negative                                                                                                                                                                     
  int tmp = ~x & ~y;
  return ~tmp;
}
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  return ~x & ~y;
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int a = x & ~y;
  int b = ~x & y;
  // Now, we want a | b. So, -(-a & -b)                                                                                                                                                                               
  return ~(~a & ~b);
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  int start= 1;// I was tempted to use the number 85 that we mentioned in class                                                                                                                                       
  start |= start << 2;
  start |= start << 4;
  start |= start << 8;
  start |= start << 16;
  return start;
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  // To get negative of a number, we flip everything first then add 1 at the end                                                                                                                                      
  return (~1 + 1);
}
/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) {
  // Idea: First get all 1s. Then, get lower 32 - n bits to 0. Initial idea for all 1s: start with base 1, then base |= base << 1, then 2 ... 16. But it will exceed 10 operations overall.                           
  // So, I used ~0 to get all 1s as 0 is 000...000. So, ~0 = 111...111                                                                                                                                                
  int tmp = !n + ~0;
  return tmp << 32 + (~n + 1);
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
  // Initial idea: start with base = 1, then base |= base << 3, 6, 12, 24                                                                                                                                             
  int base = 1;
  base |= base << 3;
  base |= base << 6;
  base |= base << 12;
  base |= base << 24;
  return base;
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  // Idea: first form a number that has all even bits 1                                                                                                                                                               
  // then perform xor with x. It should result in all 0 if the number had all even bits 1. Then, return !result to get 1 in that case                                                                                 
  int y = 1;
  y |= y << 2;
  y |= y << 4;
  y |= y << 8;
  y |= y << 16;
  int result = (x & y) ^ y;// x&y will be equal to y only if x was also all even bits 1. Then, xor converts all bits to 0 only if x&y == y                                                                            
  return !result;
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
  int y = 2;//want all odd bits are 1 and even bits 0                                                                                                                                                                 
  y |= y << 2;
  y |= y << 4;
  y |= y << 8;
  y |= y << 16;
  int result = x & y;// now, all even bits are 0. If there was any odd bit of x set to 1, at least one bit of result will be 1. so, result != 0 in that case                                                          
  return !(!result);// so, if any odd bit in x == 1. Then, result != 1. So, !result = 0. So, !(!result) == 1                                                                                                          
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
  // Idea: get x, then right shift 8*n bits. So, if n==0, dont right shift any, if n==1, right shift 8 and so on. Now, the byte we want is at the spot of LSB. Then, we form a number whose LSB is all 1s             
  // and everything else is 0. Then, we & them and get the result                                                                                                                                                     
  int shifted = x >> (n << 3);
  int number = 255; //11111111                                                                                                                                                                                        
  return shifted & number;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
  // Idea: First, get the nth byte, then get the mth bute                                                                                                                                                             
  // Then, Then, left shift those nth and mth byte to correct spot on different numbers. Then, get corresponding numbers by &ing them with all 1s. Then, & the original x   
  int mthByte = (x >> (m << 3)) & 255;// 255 = 11111111 everything else 0s
  int nthByte = (x >> (n << 3)) & 255;

 // Now, shift them to correct places
  int swapMthByte = mthByte << (n << 3);
  int swapNthByte = nthByte << (m << 3);

  // Now, we clear the mth and nth byte position in x                                                                                                                                                                 
  int clearMthByte = ~(255 << (m << 3));
  int clearNthByte = ~(255 << (n << 3));
  x &= clearMthByte;
  x &= clearNthByte;
 // now, we just add te swappedBytes
  x |= swapMthByte;
  x |= swapNthByte;

  return x;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x + 1);
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  // first, we want to know if highbit > lowbit or not                                                                                                                                                                
  int isValid = highbit + (~lowbit + 1);// We will use this at the end                                                                                                                                                
  // Now, first I want to get 111..111 left shifted by highbit + 1 (to include 0th index), then flip them all to have lowest highbits 1 and everything else 0                                                         
  int highMask = (~0 << highbit) << 1;
  highMask = ~highMask;
  int reverseLowMask = ~0 << lowbit;// now if I do &                                                                                                                                                                  

  int result = highMask & reverseLowMask;
  // we want to return all 0s if isValid was -ve and result if isValid is +ve or 0                                                                                                                                    
  isValid = isValid >> 31;// if the MSB was 1 (to show -ve), I have right shifted by 31. So, it is all 1s now. if the isValid was 0, it is all 0s now                                                                 
  return ~isValid & result;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // if x is != 0, return y else return z                                                                                                                                                                             
  int helper = !!x;// So, if x was not zero, now helper is 1. if x was 0, helper is 0.                                                                                                                                
  helper = (~helper + 1);
  // if helper was 1, now we converted it to 111..111. And, if helper was 0, we converted it to 000..000 by flipping all and adding 1, causing 31st bit th 1 to overflow                                              
  return (y & helper) | (z & ~helper);
  // if helper is all 1111, in that case we want to return y. And, if helper is 000..000, we want to return z.                                                                                                        
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
  // lets say we have to rotate 010101 by 1 -> 101010.                                                                                                                                                                
  // idea: first grab the lowest n bit, in this case 1. make it 100000                                                                                                                                                
  // then, gragb the highest 32-n bits. in this case -> 001010                                                                                                                                                        
  // then, just or the results -> 101010                                                                                                                                                                              

  int lowest = x << (32 + (~n + 1)); // in our example x left shifted by 31                                                                                                                                           
  int highest = x >> n;
  int check = !n + ~0;
  check =  ~(check << 32+(~n+1));
  highest = highest & check;
  return lowest | highest;
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
  //from my understanding,  case for bit overflow, if x & y have different signs and x - y dont have the same sign as x                                                                                               
  int sub = x + (~y + 1);
  int xSign = x >> 31;
  int ySign = y >> 31;
  int subSign = sub >> 31;

  int overflow = (xSign ^ ySign) & (xSign ^ subSign);// if x and y have same sign -> no overflow or if x and sub have same sign -> no overflow                                                                        
  return !overflow;
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  int xSign = x >> 31;
  // if xSign is all 1s, it means the number was negative and if xSign is all 0s, the number was positive                                                                                                             
  // xSign = 0 or -1                                                                                                                                                                                                  
  return (x ^ xSign) + (~xSign + 1);
  // if xSign is -1, then xor with x gives us with all those 1s flipped to 0, but it results in value 1 less eg: -3 -> 2. in that case, ~xSign gives us all 0, + 1 gives us 1. So, 2 + 1 = 3                          
  // if xSign is 0, then xor with x leaves us x. Then, ~xSign is all 1s, we add 1. So, all 0s added to x is x                                                                                                         
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  return 2;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  return 2;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
  return 2;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  return 0;
}
/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
  return 2;
}
