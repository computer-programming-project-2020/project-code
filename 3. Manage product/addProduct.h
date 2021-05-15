#include <stdio.h>
#include <stdlib.h>

void addProduct() {
    FILE* file = fopen("3. Manage product/product.csv", "a+");
    if (!file) {
        printf("ERR: DATABASE CAN NOT OPEN\n");
        exit(0);
    }
    char name[100];
    int price, amount;
    printf("Product name : ");
    scanf("%s", name);
    printf("Product price : ");
    scanf(" %d", &price);
    printf("Product amount : ");
    scanf(" %d", &amount);
    fprintf(file, "%s, %d, %d\n", name, price, amount);
    fclose(file);
    printf("Product added!\n");
}