#include <stdio.h>
#include "product.h"

int createProduct(Product *p){
        printf("��ǰ����? ");
        scanf(" %[^\n]s", p->name);

        printf("�߷���? ");
        scanf(" %d", &p->weight);

        printf("������? ");
        scanf(" %d", &p->price);

        p->standard_price = p->price * 10 / p->weight;

        while(1){
                printf("��������(1~5)? ");
                scanf(" %d", &p->starRating);

                if(p->starRating < 6 && p->starRating > 0) break;
                else{
                        printf("�ٽ��Է��ϼ���\n");
                }
        }

        printf("=> �߰���!\n");

        return 1;
}

void readProduct(Product p){
        printf("%s %d %d(%d) %d\n", p.name, p.weight, p.price, p.standard_price, p.starRating);

}

int updateProduct(Product *p){

        printf("�� ��ǰ����? ");
        scanf(" %[^\n]s", p->name);

        printf("�� �߷���? ");
        scanf(" %d", &p->weight);

        printf("�� ������? ");
        scanf(" %d", &p->price);

        p->standard_price = p->price * 10 / p->weight;

        while(1){
                printf("�� ��������(1~5)? ");
                scanf(" %d", &p->starRating);

                if(p->starRating < 6 && p->starRating > 0) break;
                else{
                        printf("�ٽ��Է��ϼ���\n");
                }
        }

        printf("=> ������!\n");

        return 1;
}

int loadData(Product *p[]){
        int count = 0;

        FILE *fp = fopen("product.txt", "rt");

        if(fp == NULL){
                printf("=> ���Ͼ���!\n");
                return 0;
        }

        while(!feof(fp)){
                p[count] = (Product *)malloc(sizeof(Product));

                fscanf(fp, "%s %d %d %d %d", p[count]->name, &p[count]->weight, &p[count]->price, &p[count]->standard_price, &p[count]->starRating);

                count++;
        }

        fclose(fp);

        printf("=> �ε�����!\n");

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

        printf("=> �����!\n");
}

void searchName(Product *p[], int count){
        int scount = 0;
        char search[20];

        printf("�˻�����ǰ? ");
        scanf(" %s", search);

        printf("\nNo ��ǰ�� �߷� ����(ǥ�ذ���) ������\n");
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

        if(scount == 0) printf("=> �˻��� ������ �����ϴ�!\n");

        printf("\n");
}

void searchPrice(Product *p[], int count){
        int price_input;
        int cmp_price;
        int cmp2_price;

        printf("�˻��� ���ݴ�?(1500��: 1500��~1999��) ");
        scanf(" %d", &price_input);

        cmp_price = price_input / 1000;

        printf("%d\n", cmp_price);

        printf("\nNo ��ǰ�� �߷� ����(ǥ�ذ���) ������\n");
        printf("======================================\n");

        for(int i = 0; i < count; i++){
                cmp2_price = p[i]->price / 1000;

                if((p[i]->price >= price_input) && (cmp2_price == cmp_price)){
                        printf("%d %10s %d %d(%d) %d\n", i+1, p[i]->name, p[i]->weight, p[i]->price, p[i]->standard_price, p[i]->starRating);
                }
                else if((p[i]->price <= price_input) && (cmp2_price != cmp_price) && (i == count-1)){
                        printf("\n=> �˻��� ������ �����ϴ�!\n");
                }
        }

}

void searchStarRating(Product *p[], int count){
        int point;
        int n = 0;

        printf("�˻��� ������? ");
        scanf(" %d", &point);

        printf("\nNo ��ǰ�� �߷� ����(ǥ�ذ���) ������\n");
        printf("======================================\n");

        for(int i = 0; i < count; i++){
                if(point == p[i]->starRating){
                        printf("%d %10s %d %d(%d) %d\n", i+1, p[i]->name, p[i]->weight, p[i]->price, p[i]->standard_price, p[i]->starRating);
                        n++;
                }
        }

        if(n == 0) printf("=> �˻��� ������ �����ϴ�!\n");

}
