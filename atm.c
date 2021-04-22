#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

void withdraw(int *money){
    int wd;
    printf("Enter your money : ");
    scanf("%d", &wd);
    printf("\n");
    *money -= wd;
    *money = MAX(*money, 0);
}

void deposit(int *money){
    int dp;
    printf("Enter your money : ");
    scanf("%d", &dp);
    printf("\n");
    *money += dp;
}

void initBalances(int *money){
    printf("Enter your balances. (initial money) : ");
    scanf("%d", money);
    printf("\n");
}

void getBalances(int *money){
    printf("Your balances is : ");
    printf("%d", *money);
    printf("\n");
}

void selectOptions(int *option){
    printf("----------------------\n");
    printf("1. View balances.\n");
    printf("2. Deposit.\n");
    printf("3. Withdraw.\n");
    printf("4. Terminate.\n");
    printf("----------------------\n");
    do {
        printf("Select options : ");
        scanf("%d", option);
        printf("\n");
    } while (*option < 1);
}

int main(){
    int money, option;
    do {
        initBalances(&money);
    } while (money < 0);
    while (1) {
        selectOptions(&option);
        if (option == 1) {
            getBalances(&money);
        } else if (option == 2) {
            deposit(&money);
            getBalances(&money);
        } else if (option == 3) {
            withdraw(&money);
            getBalances(&money);
        } else if (option == 4) {
            break;
        }
    }
    return 0;
}