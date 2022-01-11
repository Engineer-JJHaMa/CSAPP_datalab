#line 146 "bits.c"
int bitXor(int x, int y) {

  int pattern01=  ~x & y;

  int pattern10=  x & ~y;

  int ans=  ~(~pattern01 & ~pattern10);
  return ans;
}
#line 161
int tmin(void) {

  int ans=  1 << 31;
  return ans;
}
#line 174
int isTmax(int x) {
#line 178
  int zero=  x + x + 2;


  int ans=  !zero & !(!(~x));
  return ans;
}
#line 192
int allOddBits(int x) {
#line 204
  int allOddBitNumber=(  0xAA << 24) +( 0xAA << 16) +( 0xAA << 8) + 0xAA;

  int ans=  !((allOddBitNumber & x) ^ allOddBitNumber);
  return ans;
}
#line 216
int negate(int x) {

  int ans=  ~x + 1;
  return ans;
}
#line 231
int isAsciiDigit(int x) {
  int NEG=  1 << 31;
  int isBiggerThen0=  !((x + ~0x30 + 1) & NEG);
  int isSmallerThen9=  !((0x39 + ~x + 1) & NEG);
  int ans=  isBiggerThen0 & isSmallerThen9;
  return ans;
}
#line 245
int conditional(int x, int y, int z) {

  int isxtrue=((  !(!x)) << 31) >> 31;

  int ans=(  y & isxtrue) |( z & ~isxtrue);
  return ans;
}
#line 259
int isLessOrEqual(int x, int y) {
  int signX=  x >> 31;
  int signY=  y >> 31;
  int ans=(  signX & !signY) |( !(signX ^ signY) & !((y + ~x + 1) >> 31));
  return ans;
}
#line 274
int logicalNeg(int x) {
#line 287
  int ans=((  x |( ~x + 1)) >> 31) + 1;
  return ans;
}
#line 302
int howManyBits(int x) {


  int b16;int b8;int b4;int b2;int b1;int ans;
  int sign=  x >> 31;

  x =( ~sign & x) |( sign & ~x);

  b16 =( !!(x >> 16)) << 4;
  x = x >> b16;
  b8 =( !!(x >> 8)) << 3;
  x = x >> b8;
  b4 =( !!(x >> 4)) << 2;
  x = x >> b4;
  b2 =( !!(x >> 2)) << 1;
  x = x >> b2;
  b1 = !!(x >> 1);
  x = x >> b1;
  ans = b16 + b8 + b4 + b2 + b1 + x + 1;
  return ans;
}
#line 335
unsigned floatScale2(unsigned uf) {
  unsigned NEG;unsigned e;unsigned s;unsigned ans;
  NEG = 1u << 31;
  e = uf >> 23;
  s = uf & NEG;
  if ((uf>> 7) & 1) {
    ans = uf;
  }
  else {
    e = e << 1;
    ans =( uf |( e << 23)) ^ s;
  }
  return ans;
}
#line 361
int floatFloat2Int(unsigned uf) {
  return 2;
}
#line 377
unsigned floatPower2(int x) {
    return 2;
}
