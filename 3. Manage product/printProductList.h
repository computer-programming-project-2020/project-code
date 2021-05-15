#include <stdio.h>
#include <string.h>

void printProductList() {
    FILE* file = fopen("3. Manage product/product.csv", "r");
    if (!file) {
        printf("ERR: DATABASE CAN NOT OPEN\n");
        exit(0);
    }
    char buffer[1024];
    int row = 0, col = 0;
    while (fgets(buffer, 1024, file)) {
        col = 0;
        row++;
        if (row == 1) {
            continue;
        }
        char* value = strtok(buffer, ", ");
        while (value) {
            if (col == 0) {
                printf("%02d", row-1);
                // printf("\tName : s");
            }
            // if (col == 1) {
            //     printf("\tPrice : ");
            // }
            // if (col == 2) {
            //     printf("\tAmount : ");
            // }
            printf("\t%s", value);
            value = strtok(NULL, ", ");
            col++;
        }
        // printf("\n");
    }
    fclose(file);
}