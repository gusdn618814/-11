#ifndef POLYLIST_H
#define POLYLIST_H

// 다항식의 각 항을 저장하는 구조체
// 예: 3X^2 -> coef=3, exp=2
typedef struct {
    float coef; // 계수
    int   exp;  // 지수
} elementPolyList;

// 순차 리스트 구조체
typedef struct {
    elementPolyList *data; // 동적 배열
    int size;              // 현재 저장된 항 수
    int capacity;          // 최대 용량
} polyList;

// 순차 리스트 기본 연산
polyList* createPolyList(int size);
void      destroyPolyList(polyList* pl);
int       isEmptyPolyList(polyList* pl);
int       isFullPolyList(polyList* pl);
int       sizePolyList(polyList* pl);
int       insertPolyList(polyList* pl, int pos, elementPolyList item);
elementPolyList deletePolyList(polyList* pl, int pos);
elementPolyList getItemPolyList(polyList* pl, int pos);
int       replaceItemPolyList(polyList* pl, int pos, elementPolyList item);
void      printPolyList(polyList* pl);

#endif
