/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * JinJjaHaMa
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
  // x는 0, y는 1을 가지고 있는 패턴을 추출한다. 
  int pattern01 = ~x & y;
  // x는 1, y는 0을 가지고 있는 패턴을 추출한다.
  int pattern10 = x & ~y;
  // pattern01과 pattern10의 or연산이다.
  int ans = ~(~pattern01 & ~pattern10);
  return ans;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  // 1000...0의 형태로 만들기
  int ans = 1 << 31;
  return ans;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  //Tmax + Tmin + 1 = 0
  //Tmin = Tmax + 1
  //Tmax + Tmax + 2 = 0
  int zero = x + x + 2;
  //바로 !zero가 답이 아닐수도 있다. -1(111...1)을 예외처리 해야한다.
  //& 우항은 x가 -1일경우 0이나온다(나머지 경우에는 1).
  int ans = !zero & !(!(~x));
  return ans;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /*
  아래 답안보다 연산자 수가 많아서 주석으로 남겨두는 답안입니다.
  //반으로 계속 접어가면서 홀수 자리를 비교합니다.
  int ban1 = x & (x >> 16);
  int ban2 = ban1 & (ban1 >> 8);
  int ban3 = ban2 & (ban2 >> 4);
  int ban4 = ban3 & (ban3 >> 2);
  // 다 접었다면 1번 비트가 1이여야 allOddBits 입니다.
  int ans = 1 & (ban4 >> 1);
  */
  // 1010...10 만들기
  int allOddBitNumber = (0xAA << 24) + (0xAA << 16) + (0xAA << 8) + 0xAA;
  // 1010...10 & x == 1010...10
  int ans = !((allOddBitNumber & x) ^ allOddBitNumber);
  return ans;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  // two's complement 기본 원리
  int ans = ~x + 1;
  return ans;
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
  int NEG = 1 << 31;
  int isBiggerThen0 = !((x + ~0x30 + 1) & NEG);
  int isSmallerThen9 = !((0x39 + ~x + 1) & NEG);
  int ans = isBiggerThen0 & isSmallerThen9;
  return ans;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // x값이 0이아니면 11...1, 0이면 00...0이 된다.
  int isxtrue = ((!(!x)) << 31) >> 31;
  // isxtrue값에 따라 y(11...1일 경우) 또는 z(00...0일 경우) 중 한가지 값만 나온다.
  int ans = (y & isxtrue) | (z & ~isxtrue);
  return ans;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int signX = x >> 31;
  int signY = y >> 31;
  int ans = (signX & !signY) | (!(signX ^ signY) & !((y + ~x + 1) >> 31));
  return ans;
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
  /*
  잘 안작동하기도 하고 연산도 많은 답안. 0x80000000 넣으면 2가 나오는 이유가 뭘까?
  // 비트 중 1이 하나라도 있으면 ban5의 0번째 비트값은 1이 된다.
  int ban1 = x | (x >> 16);
  int ban2 = ban1 | (ban1 >> 8);
  int ban3 = ban2 | (ban2 >> 4);
  int ban4 = ban3 | (ban3 >> 2);
  int ban5 = ban4 | (ban4 >> 1);
  // ban5의 0번째 비트값이 1이면 ans를 0으로 만들어야 한다.
  int ans = (ban5 & 1) ^ 1;
  */
  // 솔직히 인터넷에서 봤다. 0이 아니라면 x와 -x 둘 중 하나는 부호 비트가 1인 점을 이용.
  int ans = ((x | (~x + 1)) >> 31) + 1;
  return ans;
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
  // 반은 검색, 반은 자력으로 했다.
  // 일단 x의 부호부터 판별해야 할 것 같다.
  int b16, b8, b4, b2, b1, ans;
  int sign = x >> 31;
  // x가 양수면 그대로, x가 음수면 -x로 바꾸기
  x = (~sign & x) | (sign & ~x);
  // 반씩 줄여나가면서 사용하는 비트의 범위를 파악한다.
  b16 = (!!(x >> 16)) << 4;
  x = x >> b16;
  b8 = (!!(x >> 8)) << 3;
  x = x >> b8;
  b4 = (!!(x >> 4)) << 2;
  x = x >> b4;
  b2 = (!!(x >> 2)) << 1;
  x = x >> b2;
  b1 = !!(x >> 1);
  x = x >> b1;
  ans = b16 + b8 + b4 + b2 + b1 + x + 1;
  return ans;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned sign, exp, signMask, expMask, ans;
  signMask = 1u << 31;
  expMask = 0xffu << 23;
  sign = uf & signMask;
  exp = uf & expMask;
  
  if(exp ^ expMask) {
    // Noramalized
    if(exp) {
      // increase exp
      exp = exp + (1u << 23);
      // not inf case
      if(exp ^ expMask) {
        ans = (uf & ~expMask) | exp; 
      }
      // inf case
      else {
        ans = exp | sign;
      }
    }
    // Denormalized
    else {
      // Not Zero
      if(uf & ~sign) {
        ans = (uf << 1) | sign;
      }
      // Zero
      else {
        ans = uf;
      }
    }
  }
  // Infinity or NaN
  else {
    ans = uf;
  }
  return ans;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
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
int floatFloat2Int(unsigned uf) {
  /*
  //Rounding 갱각 안해도 되는 거였구나 으어아ㅏㅏㅏㅏㅏㅏㅏ
  int sign, exp, frac, outOfRange, fracWithMarker, roundPart, roundPointer, valueBeforeRound, howToRound;
  sign = uf >> 31;
  exp = ((uf >> 23) & 0xff) - 127;
  frac = (uf << 9) >> 9;
  outOfRange = 1 << 31;
  fracWithMarker = frac | (1 << 23);
  
  if(exp >= 31) return outOfRange;
  if(exp < -1) return 0;
  if(exp == -1) {
    if(frac < (1 << 22)) return 0;
    else return 1;
  }
  
  roundPointer = exp - 23;
  if(roundPointer >= 0) return fracWithMarker << roundPointer;
  roundPart = frac & ~(outOfRange >> (exp + 8));
  roundPointer = roundPointer * -1;
  valueBeforeRound = fracWithMarker >> roundPointer;
  howToRound = roundPart - (1 << roundPointer);
  if(howToRound < 0) {
    if(sign) return valueBeforeRound * -1;
    return valueBeforeRound;
  }
  valueBeforeRound += 1;
  if(howToRound > 0) {
    if(sign) return valueBeforeRound * -1;
    return valueBeforeRound;
  }
  
  return 2;
  */
  int e = ((uf >> 23) & 0xff)-127;
  int sign = uf >> 31;
  int M = (uf&0x007fffff)|0x00800000;
  if(!(uf&0x7fffffff)) return 0; // 0
  if(e < 0) return 0; // 0.***
  if(e > 31) return 0x80000000; // overflow
  if(!(uf & 0x7fffffff)) return 0; // 0
  if(e > 23) 
    M <<= (e - 23);
  else 
    M >>= (23 - e);

  if(!((M >> 31) ^ sign)) // +
    return M;
  else if(M >> 31) // overflow
    return 0x80000000;
  return ~M + 1; // -
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
