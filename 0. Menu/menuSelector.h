#include <stdio.h>
#include <string.h>
#include "printMenuSelector.h"
#include "clearScreen.h"
#include "../1. Purchase/changeCalc.h"
#include "../1. Purchase/electronicBills.h"
#include "../2. Product/printProductMenu.h"
// #include "../2. Product/productInterface.h"

struct Product product[1000];
struct Product purchase[1000];
void productMenu();
void printProductList();
void addProduct();
void removeProduct();
void clearCharArray();
void shiftProduct();
void viewAllProduct();
void addToStorage();
void purchased();
void printSelectedList();
void clearSelectedList();
void clearPurchaseArray();
int calcTotalPrice();
void printTotalPrice();
int n_pd = 0, n_pc = 0;

void menuSelector() {
    clearScreen();
    printMenuSelector();
    int menu;
    printf("Select : ");
    scanf("%d", &menu);
    switch (menu) {
        case 1:
            clearScreen();
            purchased();
            menuSelector();
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

void purchased() {
    int productSelect, qty;
    int price = 0, x, money = 0;
    int state_added = 0;
    char printBills;
    while (1) {
        printProductList();
        if (n_pc > 0) {
            printSelectedList();
            price = calcTotalPrice();
            printTotalPrice(price);
        }
        printf("(Enter '0' to finish)\n");
        printf("Select : ");
        scanf("%d", &productSelect); 
        productSelect--;
        if (productSelect == -1) {
            if (n_pc == 0) {
                clearScreen();
                printf("ERR: USER NOT SELECT PRODUCT\n");
                exit(0);
            } else {
                printf("Money receive : ");
                scanf("%d", &money);
                printf("Total Change = %d Baht\n", changeCalc(price, money));
                printf("Print bills? (y/n) : ");
                scanf(" %c", &printBills);
                switch (printBills) {
                    case 'y':
                        clearScreen();
                        electronicBills(purchase, n_pc, price, money, changeCalc(price, money));
                        break;
                    default:
                        break;
                }
                clearSelectedList();
                printf("Enter '0' to go back : ");
                scanf("%d", &x);
                break;
            }
        } else if (productSelect > -1 && productSelect < n_pd) {
            state_added = 0;
            printf("Amount : ");
            scanf("%d", &qty);
            if (n_pc > 0) {
                for (int i = 0; i < n_pc; i++) {
                    if (strcmp(purchase[i].name, product[productSelect].name) == 0) {
                        purchase[i].amount += qty;
                        product[productSelect].amount -= qty;
                        state_added = 1;
                        break;
                    }
                }
            }
            if (!state_added) {
                strcpy(purchase[n_pc].name, product[productSelect].name);
                purchase[n_pc].price = product[productSelect].price;
                purchase[n_pc].amount = qty;
                product[productSelect].amount -= qty;
                n_pc++;
            }
            clearScreen();
        } else {
            clearScreen();
            printf("ERR: INVALID INPUT\n");
            exit(0);
        }
    }
}

int calcTotalPrice() {
    int price = 0;
    for (int i = 0; i < n_pc+1; i++) {
        price += purchase[i].price * purchase[i].amount;
    }
    return price;
}

void printTotalPrice(int price) {
    printf("Total Price = %d Baht\n", price);
}

void printSelectedList() {
    printf("\n-- Selected --\n");
    printf("ID\tName\t\t\t\tPrice\tAmount\n");
    for (int i = 0; i < n_pc; i++) {
        if (strlen(purchase[i].name) >= 16) {
            printf("%03d\t%s\t\t%d\t%d\n", i+1, purchase[i].name, purchase[i].price, purchase[i].amount);
        } else if (strlen(purchase[i].name) >= 8) {
            printf("%03d\t%s\t\t\t%d\t%d\n", i+1, purchase[i].name, purchase[i].price, purchase[i].amount);
        } else if (strlen(purchase[i].name) == 0) {
            break;
        } else {
            printf("%03d\t%s\t\t\t\t%d\t%d\n", i+1, purchase[i].name, purchase[i].price, purchase[i].amount);
        }
    }
}

void clearSelectedList() {
    for (int i = 0; i < n_pc; i++) {
        clearPurchaseArray(i);
        purchase[i].price = 0;
        purchase[i].amount = 0;
    }
    n_pc = 0;
}

void addToStorage() {
    printProductList();
    printf("What product you want add to stock? : ");
    int select, amount, x;
    scanf("%d", &select);
    select--;
    if (select > -1 && select < n_pd) {
        printf("Amount : ");
        scanf("%d", &amount);
        product[select].amount += amount;
        clearScreen();
        printProductList();
        printf("Enter '0' to go back : ");
        scanf("%d", &x);
    } else {
        clearScreen();
        printf("ERR: INVALID INPUT\n");
        exit(0);
    }
}

void addProduct() {
    char name[100];
    int price, amount;
    printf("Product Name : ");
    scanf(" %[^\n]s", name);
    printf("Price : ");
    scanf(" %d", &price);
    printf("Amount : ");
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
        if (strlen(product[i].name) >= 16) {
            printf("%03d\t%s\t\t%d\t%d\n", i+1, product[i].name, product[i].price, product[i].amount);
        } else if (strlen(product[i].name) >= 8) {
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
    select--;
    for (int i = select; i < n_pd; i++) {
        if (i != n_pd - 1) {
            clearCharArray(i);
            strcpy(product[i].name, product[i+1].name);
            product[i].price = product[i+1].price;
            product[i].amount = product[i+1].amount;
        } else {
            clearCharArray(i);
            product[i].price = 0;
            product[i].amount = 0;
            n_pd--;
        }
    }
    if (strlen(product[0].name) == 0) {
        n_pd = 0;
    }
}

void clearCharArray(int select) {
    for (int i = 0; i < strlen(product[select].name); i++){
        product[select].name[i] = '\0';
    }
}

void clearPurchaseArray(int select) {
    for (int i = 0; i < strlen(purchase[select].name); i++){
        purchase[select].name[i] = '\0';
    }
}