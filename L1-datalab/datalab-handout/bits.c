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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~((~(x & (~y))) & (~ ((~x) & y)));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
  return (!!(~x)) & (!(~(x ^ (x+1))));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mask8 = 0xaa;
  int mask16 = mask8 | (mask8 << 8);
  int mask32 = mask16 | (mask16 << 16);
  return  !(~x & mask32);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x)+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int three_head = !(3 ^ (x >> 4));
  int last_four_bits = x & 15;
  int is_eight = !(last_four_bits ^ 8);
  int is_nine = !(last_four_bits ^ 9);
  int less_than_eight = !(last_four_bits >> 3);
  return three_head & (is_eight | is_nine | less_than_eight);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int mask1 = !!x;
  int mask2 = mask1 | (mask1 << 1);
  int mask4 = mask2 | (mask2 << 2);
  int mask8 = mask4 | (mask4 << 4);
  int mask16 = mask8 | (mask8 << 8);
  int mask32 = mask16 | (mask16 << 16);
  return (y&mask32) + (z& (~mask32));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // x - y <=0, delta = y - x >= 0
  // special cases:
  //  (~x) + 1 != -x (x == Tmin)
  //  delta overflows
  int delta = y + (~x) + 1;
  int Tmin = 1 << 31;
  // x = Tmin
  int xIsTmin = !(x ^Tmin);
  // overflow when (+) - (-) or (-) - (+)
  if (((unsigned)x >> 31) ^ ((unsigned)y>>31)) {
    return (unsigned)x>>31;
  }
  return !(delta & (1<<31));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int x2 = x | (x >> 16);
  int x4 = x2 | (x2 >> 8);
  int x8 = x4 | (x4 >> 4);
  int x16 = x8 | (x8 >> 2);
  int x32 = x16 | (x16 >> 1);
  return (x32&1) ^ 1;
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
  int n = 0;
  x ^= (x<<1);
  n += ((!!(x&((~0)<<(n+16)))) << 4);
  n += ((!!(x&((~0)<<(n+8)))) << 3);
  n += ((!!(x&((~0)<<(n+4)))) << 2);
  n += ((!!(x&((~0)<<(n+2)))) << 1);
  n += (!!(x&((~0)<<(n+1))));
  return n+1;
}
//float
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
  // 1 | 8 | 23
  // you can use if but not operations like ==
  //extreme case: zero, denorm2denorm, denorm2norm, norm2inf, inf2inf
  // printf("INPUT:\t%.8x\n", uf);
  //zero

  if (!uf)  return 0U;
  unsigned sign_bit = uf >> 31;
  unsigned exp_bits = (uf << 1) >> 24;
  unsigned frac_bits = (uf << 9) >> 9;
  unsigned denorm_bits = 0;
  unsigned inf_bits = (unsigned)((1<<31) >> 8) >> 24;
  unsigned close2inf_bits = inf_bits ^ 1;

  if (!(exp_bits ^ denorm_bits)) {
    //denorm2norm or denorm2denorm
    return (sign_bit << 31) + (frac_bits << 1);
  }

  if (!(exp_bits ^ close2inf_bits) || (!(exp_bits ^ inf_bits) && !frac_bits)) {
    //norm2inf
    return (sign_bit << 31) | (inf_bits << 23);
  }

  if (!(exp_bits ^ inf_bits) && frac_bits) {
    //NaN
    return uf;
  }

  //normal case
  return uf + (1 << 23);
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
  int sign_bit;
  if (!x) return 0;
  if (x & (1 << 31)) {
    //if x is Tmin, there is no +x
    if (!(x ^ (1 << 31))) {
      return (1<<31) | ((31 + (1<<7) - 1) << 23);
    }
    //normal case
    sign_bit = 1;
    x = (~x) + 1;
  } else {
    sign_bit = 0;
  }
  unsigned frac_bits = x;
  int lead_zero_cnt = 0;
  while (!(frac_bits & (1<<31))) {
    frac_bits <<= 1;
    lead_zero_cnt += 1;
  }
  frac_bits <<= 1;
  //if there is loss, we have to do rounding!
  //closer rounding
  if ((frac_bits << 23) & (1<<31)) {
    if (!(frac_bits << 24)) {
      //exact middle, even rounding
      frac_bits = (frac_bits >> 9);
      if (frac_bits & 1) frac_bits += 1;
    } else {
      //upper side
      frac_bits = (frac_bits >> 9) + 1;
    }
  } else {
    //lower side
    frac_bits = frac_bits >> 9;
  }

  //don't consider precision loss here because it's recorded to calculate E
  int num_exact_frac_bits = 32 - lead_zero_cnt - 1;

  int exp_bits;
  int bias = (1<<7) - 1;
  //the loss of precision is not important, E is

  exp_bits = num_exact_frac_bits + bias;
  return (sign_bit << 31) + (exp_bits << 23) + frac_bits;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  int sign;
  if (uf >> 31) sign = -1; else sign = 1;
  unsigned exp_bits = (uf << 1) >> 24;
  unsigned frac_bits = (uf << 9) >> 9;
  unsigned inf_bits = (unsigned)((1<<31) >> 8) >> 24;

  int E = exp_bits - ((1<<7) - 1);
  
  if (E & (1<<31)) return 0;

  if ((31-E) & (1<<31)) return 0x80000000u;

  int int_part, dec_part = (frac_bits << 9);

  if (!(E & (1 << 31))) {
    if (!E) {
      int_part = 1;
    } else {
      int_part = (1 << E) + (dec_part >> (32-E));
      dec_part <<= E;
    }
  }
  if (dec_part >> 31) {
    return (int_part + 1) * sign;
  } else {
    return int_part * sign;
  }



}
