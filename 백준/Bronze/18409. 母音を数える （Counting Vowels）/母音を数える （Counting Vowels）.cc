#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    char in[51];
    scanf("%s", in);


    int ans=0;
    for(size_t i=0; i<n;i++) {
        if(in[i]=='a' || in[i]=='e' ||in[i]=='i' ||in[i]=='o' ||in[i]=='u'){
            ans++;
        }
    }
    printf("%d", ans);

    return 0;
}
