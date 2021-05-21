#include <stdio.h>

int changeCalc(int pdprice, int money){
    int onebaht=0, twobaht=0, fivebaht=0, tenbaht=0, twentybaht=0, fiftybaht=0, hundredbaht=0, fivehundredbaht=0, thousandbaht=0;
    int change = 0;
    change += money - pdprice;
    for(int i = 0; change > 0; i++){
        if(change - 1000 >= 0){
            change -= 1000;
            thousandbaht++;
        }
        else if(change - 500 >= 0){
            change -= 500;
            fivehundredbaht++;
        }
        else if(change - 100 >= 0){
            change -= 100;
            hundredbaht++;
        }
        else if(change - 50 >= 0){
            change -= 50;
            fiftybaht++;
        }
        else if(change - 20 >= 0){
            change -= 20;
            twentybaht++;
        }
        else if(change - 10 >= 0){
            change -= 10;
            tenbaht++;
        }
        else if(change - 5 >= 0){
            change -= 5;
            fivebaht++;
        }
        else if(change - 2 >= 0){
            change -= 2;
            twobaht++;
        }
        else if(change - 1 >= 0){
            change -= 1;
            onebaht++;
        }
    }
    if (thousandbaht || fivehundredbaht || hundredbaht || fiftybaht || twentybaht || tenbaht || fivebaht || twobaht || onebaht) {
        printf("\n-- Change --\n");
    }
    if (thousandbaht) {
        printf("1000 = %d\n", thousandbaht);
    }
    if (fivehundredbaht) {
        printf("500 = %d\n", fivehundredbaht);
    }
    if (hundredbaht) {
        printf("100 = %d\n", hundredbaht);
    }
    if (fiftybaht) {
        printf("50 = %d\n", fiftybaht);
    }
    if (twentybaht) {
        printf("20 = %d\n", twentybaht);
    }
    if (tenbaht) {
        printf("10 = %d\n", tenbaht);
    }
    if (fivebaht) {
        printf("5 = %d\n", fivebaht);
    }
    if (twobaht) {
        printf("2 = %d\n", twobaht);
    }
    if (onebaht) {
        printf("1 = %d\n", onebaht);
    }
    return money - pdprice;
}