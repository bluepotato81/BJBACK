#include <stdio.h>
#include <stdlib.h>

char let[15];

int compare(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

int isvowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

char ans[16];

void solve(int l, int c, int curindex, int curlen, int vowels, int consonants) {
    if(curlen==l) {
        if (vowels >= 1 && consonants >= 2) {
            ans[curlen] = '\0';
            printf("%s\n", ans);
        }
        return;
    }

    for(int i=curindex; i<c;i++) {
        ans[curlen]=let[i];
        if(isvowel(let[i])){
            solve(l,c,i+1,curlen+1,vowels+1,consonants);
        }
        else {
            solve(l,c,i+1,curlen+1,vowels,consonants+1);
        }
    }
}

int main() {
    int l,c;
    scanf("%d %d", &l, &c);



    for(int i=0; i<c; i++) {
        scanf(" %c", &let[i]);
    }

    qsort(let, c, sizeof(char), compare);

    solve(l,c,0,0,0,0);

    return 0;
}
