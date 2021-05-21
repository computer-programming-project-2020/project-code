#include <time.h>
#include "../2. Product/productInterface.h"
#define BST +7

void electronicBills(struct Product product[1000], int n_pc, int total, int receive, int change) {
    time_t timer;
    struct tm* tm_info;
    char day[3];
    char month[3];
    char year[5];
    time(&timer);
    tm_info = localtime(&timer);
    printf("\t7-11 PAKNAMPO\n");
    strftime(day, 3, "%d", tm_info);
    strftime(month, 3, "%m", tm_info);
    strftime(year, 5, "%Y", tm_info);
    printf("%s/%s/%s ", day, month, year);
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = gmtime(&rawtime );
    printf("%2d:%02d\n", (info->tm_hour+BST)%24, info->tm_min);
    printf("--------------------------\n");
    for (int i = 0; i < n_pc; i++) {
        printf("%s x%d\t%d\n", product[i].name, product[i].amount, product[i].price);
    }
    printf("\nTotal\t%d ฿\n", total);
    printf("Receive\t%d ฿\n", receive);
    printf("Change\t%d ฿\n", change);
    printf("--------------------------\n");
}
