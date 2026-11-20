#include <stdio.h>
#include <string.h>

int recursion(const char *s, int l, int r, int *a){
    (*a)++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, a);
}

int isPalindrome(const char *s, int *a){
    return recursion(s, 0, strlen(s)-1, a);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        char input[1001];
        scanf("%s", input);
        int a=0;
        int k=isPalindrome(input, &a);
        printf("%d %d\n", k, a);
    }

    return 0;
}
