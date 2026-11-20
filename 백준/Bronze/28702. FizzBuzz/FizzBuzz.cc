#include <stdio.h>
#include <stdlib.h>

int main() {
    char fizzbuzz[9];

    int select;
    for(int i=0; i<3; i++) {
        scanf("%s", fizzbuzz);
        int a;
        if(fizzbuzz[0]>'0' && fizzbuzz[0]<='9') {
            a=atoi(fizzbuzz);
            select = a+(3-i);

        }
    }
    if(select%3==0 && select%5==0) {
        printf("FizzBuzz");
    }
    else if(select%3==0) {
        printf("Fizz");
    }
    else if(select%5==0) {
        printf("Buzz");
    }
    else {
        printf("%d", select);
    }
    return 0;
}
