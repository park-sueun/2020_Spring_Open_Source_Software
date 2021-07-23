#include <stdio.h>
#include "product.h"
#include "manager.h"

int selectMenu(){

    int menu;

    printf("\n*** HandongMarket ***\n");
    printf("1. �޴���ȸ\n");
    printf("2. �޴��߰�\n");
    printf("3. �޴�����\n");
    printf("4. �޴�����\n");
    printf("5. ��������\n");
    printf("6. ��ǰ�˻�\n");
    printf("0. ����\n\n");

    printf("=> ���ϴ� �޴���? ");

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
                printf("����������������ϴ�\n");
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
                printf("=> ��ҵ�!\n");
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
                printf("=> ��ҵ�!\n");
                continue;
            }

            int deleteok;
            printf("������ �����Ͻðڽ��ϱ�? (����: 1) ");
            scanf(" %d", &deleteok);

            if(deleteok == 1){
                if(p[no-1]) free(p[no-1]);
                p[no-1] = NULL;
                printf("=> ������!\n");
            }
            else{
                printf("=> ��ҵ�!\n");
                continue;
            }
        }

        else if(menu == 5){
            saveData(p, curcount);
        }

        else if(menu == 6){
            int no = searchMenu();

            if(no == 0){
                printf("=> ��ҵ�!\n");
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
            else printf("=> �߸��Է��ϼ̽��ϴ�\n");

       }
    }

    printf("=> �����!\n");

    return 0;

}
