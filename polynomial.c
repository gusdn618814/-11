#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polynomial.h"

#define MAX_CAPACITY 1000

// -----------------------------------------------
// 다항식 입력
// 입력 형식: 3X^2+2X^1+1X^0
// -----------------------------------------------
polynomial* inputPolynomial() {
    char buf[1024];
    polynomial* p = createPolylist(MAX_CAPACITY);

    printf("다항식 입력 (예: 3X^2+2X^1+1X^0): ");
    scanf("%s", buf);

    // '+' 기준으로 각 항 분리
    char* token = strtok(buf, "+");
    while (token != NULL) {
        float coef = 0;
        int   exp  = 0;
        if (sscanf(token, "%fX^%d", &coef, &exp) == 2) {
            elementPolylist item = { coef, exp };
            insertPolylist(p, sizePolylist(p), item);
        }
        token = strtok(NULL, "+");
    }
    return p;
}

// -----------------------------------------------
// 다항식 출력
// -----------------------------------------------
void printPolynomial(polynomial* p) {
    printPolylist(p);
}

// -----------------------------------------------
// 다항식 메모리 해제
// -----------------------------------------------
void destroyPolynomial(polynomial* p) {
    destroyPolylist(p);
}

// -----------------------------------------------
// 다항식 덧셈 (수업 코드 오류 수정 버전)
//
// 방식: p1의 각 항을 결과에 넣고,
//       p2의 각 항은 같은 지수가 있으면 계수를 더하고,
//       없으면 새 항으로 추가한다.
//
// [수업 코드에서 수정한 오류]
// 1. insertPolylist 내부 루프 범위 초과 → Polylist.c에서 수정
// 2. p2에만 있는 항을 결과에 추가하지 않던 문제 → 아래 로직으로 해결
// -----------------------------------------------
polynomial* addPolynomial(polynomial* p1, polynomial* p2) {
    polynomial* result = createPolylist(MAX_CAPACITY);

    // p1의 모든 항을 결과에 복사
    for (int i = 0; i < sizePolylist(p1); i++) {
        elementPolylist item = getItemPolylist(p1, i);
        insertPolylist(result, sizePolylist(result), item);
    }

    // p2의 각 항 처리
    for (int j = 0; j < sizePolylist(p2); j++) {
        elementPolylist termP2 = getItemPolylist(p2, j);
        int found = 0;

        // 결과에 같은 지수의 항이 있으면 계수를 더함
        for (int k = 0; k < sizePolylist(result); k++) {
            elementPolylist termResult = getItemPolylist(result, k);
            if (termResult.exp == termP2.exp) {
                termResult.coef += termP2.coef;
                replaceItemPolylist(result, k, termResult);
                found = 1;
                break;
            }
        }

        // 없으면 새 항으로 추가
        if (!found) {
            insertPolylist(result, sizePolylist(result), termP2);
        }
    }

    return result;
}

// -----------------------------------------------
// 다항식 곱셈
//
// p1의 각 항 × p2의 각 항:
//   지수는 더하고, 계수는 곱해서 결과에 누적
// -----------------------------------------------
polynomial* multiplyPolynomial(polynomial* p1, polynomial* p2) {
    polynomial* result = createPolylist(MAX_CAPACITY);

    for (int i = 0; i < sizePolylist(p1); i++) {
        elementPolylist termP1 = getItemPolylist(p1, i);

        for (int j = 0; j < sizePolylist(p2); j++) {
            elementPolylist termP2 = getItemPolylist(p2, j);

            // 새로운 항: 지수=합, 계수=곱
            elementPolylist newTerm = {
                termP1.coef * termP2.coef,
                termP1.exp  + termP2.exp
            };

            // 결과에 같은 지수의 항이 있으면 계수 누적
            int found = 0;
            for (int k = 0; k < sizePolylist(result); k++) {
                elementPolylist termResult = getItemPolylist(result, k);
                if (termResult.exp == newTerm.exp) {
                    termResult.coef += newTerm.coef;
                    replaceItemPolylist(result, k, termResult);
                    found = 1;
                    break;
                }
            }

            // 없으면 새 항으로 추가
            if (!found) {
                insertPolylist(result, sizePolylist(result), newTerm);
            }
        }
    }

    return result;
}
