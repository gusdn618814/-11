#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Polylist.h"

// 다항식 = 순차 리스트 (항들의 배열)
typedef Polylist polynomial;

// 다항식 입력 (예: 3X^2+2X^1+1X^0)
polynomial* inputPolynomial();

// 다항식 덧셈
polynomial* addPolynomial(polynomial* p1, polynomial* p2);

// 다항식 곱셈
polynomial* multiplyPolynomial(polynomial* p1, polynomial* p2);

// 다항식 출력
void printPolynomial(polynomial* p);

// 다항식 메모리 해제
void destroyPolynomial(polynomial* p);

#endif
