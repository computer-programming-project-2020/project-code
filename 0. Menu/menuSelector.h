#include <stdio.h>
#include <string.h>
#include "printMenuSelector.h"
#include "clearScreen.h"
#include "../2. Product/printProductMenu.h"
#include "../2. Product/productInterface.h"

struct Product product[1000];
void productMenu();
void printProductList();
void addProduct();
void removeProduct();
void clearCharArray();
void shiftProduct();
void viewAllProduct();
void addToStorage();
int n_pd = 0;

void menuSelector() {
    clearScreen();
    printMenuSelector();
    int menu;
    printf("Select : ");
    scanf("%d", &menu);
    switch (menu) {
        case 1:
            clearScreen();
            // 
            break;
        case 2:
            clearScreen();
            addToStorage();
            menuSelector();
            break;
        case 3:
            clearScreen();
            productMenu();
            break;
        case 0:
            clearScreen();
            printf("Good Luck!\n"); 
            exit(0);
            break;
        default:
            menuSelector();
            break;
    }
}

void productMenu() {
    clearScreen();
    printProductMenu();
    int menu;
    printf("Select : ");
    scanf("%d", &menu);
    switch (menu) {
        case 1:
            clearScreen();
            addProduct();
            productMenu();
            break;
        case 2:
            clearScreen();
            removeProduct();
            productMenu();
            break;
        case 3:
            clearScreen();
            viewAllProduct();
            productMenu();
        case 0:
            clearScreen();
            menuSelector();
            break;
        default:
            productMenu();
            break;
    }
}

void addToStorage() {
    printProductList();
    printf("What product you want add to stock? : ");
    int select, amount, x;
    scanf("%d", &select);
    printf("Amount : ");
    scanf("%d", &amount);
    product[select-1].amount += amount;
    clearScreen();
    printProductList();
    printf("Enter '0' to go back : ");
    scanf("%d", &x);
}

void addProduct() {
    char name[100];
    int price, amount;
    printf("Product name : ");
    scanf(" %[^\n]s", name);
    printf("Product price : ");
    scanf(" %d", &price);
    printf("Product amount : ");
    scanf(" %d", &amount);
    strcpy(product[n_pd].name, name);
    product[n_pd].price = price;
    product[n_pd].amount = amount;
    n_pd++;
}

void printProductList() {
    int printed = 0;
    printf("ID\tName\t\t\t\tPrice\tAmount\n");
    for (int i=0; i < n_pd; i++) {
        if (strlen(product[i].name) > 18) {
            printf("%03d\t%s\t\t%d\t%d\n", i+1, product[i].name, product[i].price, product[i].amount);
        } else if (strlen(product[i].name) > 12) {
            printf("%03d\t%s\t\t\t%d\t%d\n", i+1, product[i].name, product[i].price, product[i].amount);
        } else if (strlen(product[i].name) == 0) {
            break;
        } else {
            printf("%03d\t%s\t\t\t\t%d\t%d\n", i+1, product[i].name, product[i].price, product[i].amount);
        }
    }
}

void viewAllProduct() {
    printProductList();
    int x;
    printf("Enter '0' to go back : ");
    scanf("%d", &x);
}

void removeProduct() {
    int select;
    printProductList();
    printf("What product you want to remove? : ");
    scanf("%d", &select);
    shiftProduct(select);
}

void shiftProduct(int select) {
    select -= 1;
    for (int i=0;i < n_pd;i++) {
        if (i != n_pd - 1) {
            clearCharArray(i);
            strcpy(product[i].name, product[i+1].name);
            product[i].price = product[i+1].price;
            product[i].amount = product[i+1].amount;
        } else {
            clearCharArray(i);
            product[i].price = 0;
            product[i].amount = 0;
        }
    }
}

void clearCharArray(int select) {
    for (int i=0;i<strlen(product[select].name);i++){
        product[select].name[i] = '\0';
    }
}
