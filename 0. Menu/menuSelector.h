#include <stdio.h>
#include "printMenuSelector.h"
#include "clearScreen.h"
#include "../3. Manage product/printProductMenu.h"
#include "../3. Manage product/addProduct.h"
#include "../3. Manage product/removeProduct.h"

void productMenu();

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
            // 
            break;
        case 3:
            clearScreen();
            productMenu();
            break;
        case 0:
            clearScreen();
            printf("Good Luck!\n"); 
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
            break;
        case 0:
            clearScreen();
            menuSelector();
            break;
        default:
            menuSelector();
            break;
    }
}