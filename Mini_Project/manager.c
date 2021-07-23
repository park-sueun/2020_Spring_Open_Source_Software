#include <stdio.h>
#include "manager.h"

void listProduct(Product *p[], int count){
        printf("\nNo 제품명 중량 가격(표준가격) 별점수\n");
        printf("======================================\n");

        for(int i = 0; i < count; i++){
                if(p[i] != NULL){
                        printf("%2d ", i + 1);
                        readProduct(*p[i]);
                }
        }
        printf("\n");
}

int selectDataNo(Product *p[], int count){
        int no;
        listProduct(p, count);
        printf("번호는 (취소: 0)? ");
        scanf(" %d", &no);
        return no;
}

int searchMenu(){
        int no;

        printf("======================\n");
        printf("1. 제품명으로 검색하기\n");
        printf("2. 가격으로 검색하기\n");
        printf("3. 별점수로 검색하기\n");
        printf("\n");

        printf("번호는 (취소: 0)? ");
        scanf(" %d", &no);

        return no;
}
