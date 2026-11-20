#include <stdio.h>

int main() {
    int a=0;
    scanf("%d", &a);
    int side_two=1;
    for(int i=0; i<a-1; i++) {
        side_two*=2;
    }
    int side= side_two*2+1;
    printf("%d", side*side);

}
