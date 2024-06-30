#define _GLIBCXX_DEBUG

#pragma GCC optimize(1,2,"inline","Ofast,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,bmi,bmi2,lzcnt,tune=native")

#include <immintrin.h>

#define fO0 __attribute__ ((__optimize__ ("-O0")))
// #pragma GCC unroll 8
// 放在循环的前面