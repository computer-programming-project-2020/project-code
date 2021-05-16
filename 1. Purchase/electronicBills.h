#include<stdio.h>
#include<time.h>
#define BST (+7)
int main()
{
    time_t timer;
    struct tm* tm_info;
    char day[3];
    char month[3];
    char year[5];
    printf("      7-11 PAKNAMPO\n");
    printf("--------------------------\n");
    time(&timer);
    tm_info = localtime(&timer);
    strftime(day, 3, "%d", tm_info);
    strftime(month, 3, "%m", tm_info);
    strftime(year, 5, "%Y", tm_info);
    printf("Payment          Type\n");
    printf("%s/%s/%s ", day, month, year);

    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = gmtime(&rawtime );
    printf("%2d:%02d\n", (info->tm_hour+BST)%24, info->tm_min);
    printf("mama");
    printf("        40\n");
    printf("\n");
    printf("TOTAL         THB40.00\n");
    printf("--------------------------\n");
    return 0;
}
