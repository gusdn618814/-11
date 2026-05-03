#include <stdio.h>
#include "polynomial.h"

int main(void) {
    printf("=== 다항식 연산 프로그램 ===\n\n");

    printf("[첫 번째 다항식]\n");
    polynomial* p1 = inputPolynomial();

    printf("[두 번째 다항식]\n");
    polynomial* p2 = inputPolynomial();

    printf("\n--- 입력된 다항식 ---\n");
    printf("P1 = "); printPolynomial(p1);
    printf("P2 = "); printPolynomial(p2);

    printf("\n--- 덧셈 결과 ---\n");
    polynomial* sum = addPolynomial(p1, p2);
    printf("P1 + P2 = "); printPolynomial(sum);

    printf("\n--- 곱셈 결과 ---\n");
    polynomial* product = multiplyPolynomial(p1, p2);
    printf("P1 * P2 = "); printPolynomial(product);

    destroyPolynomial(p1);
    destroyPolynomial(p2);
    destroyPolynomial(sum);
    destroyPolynomial(product);

    return 0;
}
