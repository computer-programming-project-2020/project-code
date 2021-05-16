#include <stdio.h>

int main(){
    int onebath=0, twobath=0, fivebath=0, tenbath=0, twentybath=0, fiftybath=0, hundredbath=0, fivehundredbath=0, thousandbath=0;
    int pdprice, money, change = 0, i=0;
    printf("Product Price ");
    scanf("%d", &pdprice);
    printf("Money ");
    scanf("%d", &money);
    change += money - pdprice;
    printf("Change Money %d bath\n", change);
    for(i = 0; change > 0; i++){
        if(change - 1000 >= 0){
            change -= 1000;
            thousandbath++;
        }
        else if(change - 500 >= 0){
            change -= 500;
            fivehundredbath++;
        }
        else if(change - 100 >= 0){
            change -= 100;
            hundredbath++;
        }
        else if(change - 50 >= 0){
            change -= 50;
            fiftybath++;
        }
        else if(change - 20 >= 0){
            change -= 20;
            twentybath++;
        }
        else if(change - 10 >= 0){
            change -= 10;
            tenbath++;
        }
        else if(change - 5 >= 0){
            change -= 5;
            fivebath++;
        }
        else if(change - 2 >= 0){
            change -= 2;
            twobath++;
        }
        else if(change - 1 >= 0){
            change -= 1;
            onebath++;
        }
    }
    printf("1000 = %d\n500 = %d\n100 = %d\n50 = %d\n20 = %d\n10 = %d\n5 = %d\n2 = %d\n1 = %d", thousandbath, fivehundredbath, hundredbath, fiftybath, twentybath, tenbath, fivebath, twobath, onebath);
    return 0;
}