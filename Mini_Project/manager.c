#include <stdio.h>
#include "manager.h"

void listProduct(Product *p[], int count){
        printf("\nNo ��ǰ�� �߷� ����(ǥ�ذ���) ������\n");
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
        printf("��ȣ�� (���: 0)? ");
        scanf(" %d", &no);
        return no;
}

int searchMenu(){
        int no;

        printf("======================\n");
        printf("1. ��ǰ������ �˻��ϱ�\n");
        printf("2. �������� �˻��ϱ�\n");
        printf("3. �������� �˻��ϱ�\n");
        printf("\n");

        printf("��ȣ�� (���: 0)? ");
        scanf(" %d", &no);

        return no;
}
