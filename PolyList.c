#include <stdio.h>
#include <stdlib.h>
#include "Polylist.h"

// -----------------------------------------------
// 순차 리스트 생성
// -----------------------------------------------
Polylist* createPolylist(int size) {
    Polylist* pl = (Polylist*)malloc(sizeof(Polylist));
    pl->data = (elementPolylist*)malloc(sizeof(elementPolylist) * size);
    pl->size = 0;
    pl->capacity = size;
    return pl;
}

// -----------------------------------------------
// 순차 리스트 메모리 해제
// -----------------------------------------------
void destroyPolylist(Polylist* pl) {
    free(pl->data);
    free(pl);
}

// -----------------------------------------------
// 비어있는지 확인
// -----------------------------------------------
int isEmptyPolylist(Polylist* pl) {
    return (pl->size == 0) ? 1 : 0;
}

// -----------------------------------------------
// 꽉 찼는지 확인
// -----------------------------------------------
int isFullPolylist(Polylist* pl) {
    return (pl->size == pl->capacity) ? 1 : 0;
}

// -----------------------------------------------
// 현재 크기 반환
// -----------------------------------------------
int sizePolylist(Polylist* pl) {
    return pl->size;
}

// -----------------------------------------------
// 삽입
// [수업 코드 오류 수정]
// 루프를 al->size부터 시작하면 al->data[size+1] 범위 초과
// → i = pl->size - 1 부터 시작하도록 수정
// -----------------------------------------------
int insertPolylist(Polylist* pl, int pos, elementPolylist item) {
    if (pos < 0 || pos > pl->size) {
        return 0;
    }
    // [오류 수정] i = pl->size - 1 부터 시작 (기존: pl->size)
    for (int i = pl->size - 1; i >= pos; i--) {
        pl->data[i + 1] = pl->data[i];
    }
    pl->data[pos] = item;
    pl->size++;
    return 1;
}

// -----------------------------------------------
// 삭제
// -----------------------------------------------
elementPolylist deletePolylist(Polylist* pl, int pos) {
    elementPolylist item = pl->data[pos];
    for (int i = pos; i < pl->size - 1; i++) {
        pl->data[i] = pl->data[i + 1];
    }
    pl->size--;
    return item;
}

// -----------------------------------------------
// 특정 위치 항목 반환
// -----------------------------------------------
elementPolylist getItemPolylist(Polylist* pl, int pos) {
    return pl->data[pos];
}

// -----------------------------------------------
// 특정 위치 항목 교체
// -----------------------------------------------
int replaceItemPolylist(Polylist* pl, int pos, elementPolylist item) {
    if (pos < 0 || pos > pl->size - 1) {
        return 0;
    }
    pl->data[pos] = item;
    return 1;
}

// -----------------------------------------------
// 출력
// -----------------------------------------------
void printPolylist(Polylist* pl) {
    printf("Poly List: ");
    for (int i = 0; i < pl->size; i++) {
        if (i > 0) printf(" + ");
        printf("%.0fX^%d", pl->data[i].coef, pl->data[i].exp);
    }
    printf("\n");
}
