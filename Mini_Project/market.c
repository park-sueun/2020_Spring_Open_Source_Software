#include <stdio.h>
#include "product.h"
#include "manager.h"

int selectMenu(){

    int menu;

    printf("\n*** HandongMarket ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("5. 파일저장\n");
    printf("6. 상품검색\n");
    printf("0. 종료\n\n");

    printf("=> 원하는 메뉴는? ");

    scanf("%d", &menu);

    return menu;

}

int main(void){
    Product *p[100];
    int curcount = 0;
    int count = 0, menu;

    count = loadData(p);
    curcount = count;


    while(1){
        menu = selectMenu();

        if(menu == 0) break;

        if(menu == 1 || menu == 3 || menu == 4 || menu == 6){
            if(count == 0){
                printf("저장된정보가없습니다\n");
                continue;
            }
        }

        if(menu == 1){

        #ifdef DEBUG
            printf("Debug[market.c] :call listProduct()\n");
        #endif

            listProduct(p, curcount);
        }

        else if(menu == 2){
            p[curcount] = (Product *)malloc(sizeof(Product));

        #ifdef DEBUG
            printf("Debug[market.c] :call createProduct()\n");
        #endif

            count += createProduct(p[curcount++]);
        }

        else if(menu == 3){

        #ifdef DEBUG
            printf("Debug[market.c] :call selectDataNo()\n");
        #endif

            int no = selectDataNo(p, curcount);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }

        #ifdef DEBUG
            printf("Debug[market.c] :call updateProduct()\n");
        #endif

            updateProduct(p[no-1]);
        }

        else if(menu == 4){

        #ifdef DEBUG
            printf("Debug[market.c] :deleteProduct\n");
        #endif

        #ifdef DEBUG
            printf("Debug[market.c] :call selectDataNo()\n");
        #endif

            int no = selectDataNo(p, curcount);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }

            int deleteok;
            printf("정말로 삭제하시겠습니까? (삭제: 1) ");
            scanf(" %d", &deleteok);

            if(deleteok == 1){
                if(p[no-1]) free(p[no-1]);
                p[no-1] = NULL;
                printf("=> 삭제됨!\n");
            }
            else{
                printf("=> 취소됨!\n");
                continue;
            }
        }

        else if(menu == 5){
            saveData(p, curcount);
        }

        else if(menu == 6){
            int no = searchMenu();

            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            else if(no == 1){
                searchName(p, curcount);
            }
            else if(no == 2){
                searchPrice(p, curcount);
            }
            else if(no == 3){
                searchStarRating(p, curcount);
            }
            else printf("=> 잘못입력하셨습니다\n");

       }
    }

    printf("=> 종료됨!\n");

    return 0;

}
