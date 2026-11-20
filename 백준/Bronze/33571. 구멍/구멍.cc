#include <stdio.h>

char letters[]={'A','a', 'b', 'D','d', 'e', 'g', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', '@'};

int main() {
    char ch;
    int holes=0;
    while ((ch = getchar())!='\n'&&ch!=EOF) {
        for(int i=0; i<15;i++) {
            if(ch==letters[i]) {
                holes++;
            }
        }
        if(ch=='B') {
            holes+=2;
        }
    }
    printf("%d", holes);
    return 0;
}
