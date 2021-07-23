#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50]; // 제품명
    int weight; // 중량
    int price; // 가격
    int standard_price; // 표준가격
    int starRating; // 별점수(1~5)
} Product;

#endif

int createProduct(Product *p); // 제품을 추가하는 함수

void readProduct(Product p); // 하나의 제품 출력 함수

int updateProduct(Product *p); // 제품 정보 수정 함수

int deleteProduct(Product *p); // 제품 정보 삭제 함수

int loadData(Product *p[]); // File 제품 불러오는 함수

void saveData(Product *p[], int count); // File 제품 저장 함수

void searchName(Product *p[], int count); // 제품명으로 검색하기

void searchPrice(Product *p[], int count); // 가격으로 검색하기

void searchStarRating(Product *p[], int count); // 별점수로 검색하기
