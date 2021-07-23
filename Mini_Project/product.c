#include <stdio.h>
#include "product.h"

int createProduct(Product *p){
        printf("제품명은? ");
        scanf(" %[^\n]s", p->name);

        printf("중량은? ");
        scanf(" %d", &p->weight);

        printf("가격은? ");
        scanf(" %d", &p->price);

        p->standard_price = p->price * 10 / p->weight;

        while(1){
                printf("별점수는(1~5)? ");
                scanf(" %d", &p->starRating);

                if(p->starRating < 6 && p->starRating > 0) break;
                else{
                        printf("다시입력하세요\n");
                }
        }

        printf("=> 추가됨!\n");

        return 1;
}

void readProduct(Product p){
        printf("%s %d %d(%d) %d\n", p.name, p.weight, p.price, p.standard_price, p.starRating);

}

int updateProduct(Product *p){

        printf("새 제품명은? ");
        scanf(" %[^\n]s", p->name);

        printf("새 중량은? ");
        scanf(" %d", &p->weight);

        printf("새 가격은? ");
        scanf(" %d", &p->price);

        p->standard_price = p->price * 10 / p->weight;

        while(1){
                printf("새 별점수는(1~5)? ");
                scanf(" %d", &p->starRating);

                if(p->starRating < 6 && p->starRating > 0) break;
                else{
                        printf("다시입력하세요\n");
                }
        }

        printf("=> 수정됨!\n");

        return 1;
}

int loadData(Product *p[]){
        int count = 0;

        FILE *fp = fopen("product.txt", "rt");

        if(fp == NULL){
                printf("=> 파일없음!\n");
                return 0;
        }

        while(!feof(fp)){
                p[count] = (Product *)malloc(sizeof(Product));

                fscanf(fp, "%s %d %d %d %d", p[count]->name, &p[count]->weight, &p[count]->price, &p[count]->standard_price, &p[count]->starRating);

                count++;
        }

        fclose(fp);

        printf("=> 로딩성공!\n");

        return --count;
}

void saveData(Product *p[], int count){
        FILE *fp = fopen("product.txt", "wt");

        for(int i = 0; i < count; i++){
                if(p[i] != NULL){
                        fprintf(fp, "%s %d %d %d %d\n", p[i]->name, p[i]->weight, p[i]->price, p[i]->standard_price, p[i]->starRating);
                }
        }

        fclose(fp);

        printf("=> 저장됨!\n");
}

void searchName(Product *p[], int count){
        int scount = 0;
        char search[20];

        printf("검색할제품? ");
        scanf(" %s", search);

        printf("\nNo 제품명 중량 가격(표준가격) 별점수\n");
        printf("======================================\n");

        for(int i = 0; i < count; i++){
                if(p[i] != NULL){
                        if(strstr(p[i]->name, search)){
                                printf("%2d ", i+1);
                                readProduct(*p[i]);
                                scount++;
                        }
                }
        }

        if(scount == 0) printf("=> 검색된 정보가 없습니다!\n");

        printf("\n");
}

void searchPrice(Product *p[], int count){
        int price_input;
        int cmp_price;
        int cmp2_price;

        printf("검색할 가격대?(1500원: 1500원~1999원) ");
        scanf(" %d", &price_input);

        cmp_price = price_input / 1000;

        printf("%d\n", cmp_price);

        printf("\nNo 제품명 중량 가격(표준가격) 별점수\n");
        printf("======================================\n");

        for(int i = 0; i < count; i++){
                cmp2_price = p[i]->price / 1000;

                if((p[i]->price >= price_input) && (cmp2_price == cmp_price)){
                        printf("%d %10s %d %d(%d) %d\n", i+1, p[i]->name, p[i]->weight, p[i]->price, p[i]->standard_price, p[i]->starRating);
                }
                else if((p[i]->price <= price_input) && (cmp2_price != cmp_price) && (i == count-1)){
                        printf("\n=> 검색된 정보가 없습니다!\n");
                }
        }

}

void searchStarRating(Product *p[], int count){
        int point;
        int n = 0;

        printf("검색할 별점수? ");
        scanf(" %d", &point);

        printf("\nNo 제품명 중량 가격(표준가격) 별점수\n");
        printf("======================================\n");

        for(int i = 0; i < count; i++){
                if(point == p[i]->starRating){
                        printf("%d %10s %d %d(%d) %d\n", i+1, p[i]->name, p[i]->weight, p[i]->price, p[i]->standard_price, p[i]->starRating);
                        n++;
                }
        }

        if(n == 0) printf("=> 검색된 정보가 없습니다!\n");

}
