#include <stdio.h>
#include <string.h>

typedef struct{
    char type[21];
    int num;
}cloth;

int main() {
    int t;
    scanf("%d", &t);

    for(int i=0; i<t;i++) {
        int n;
        scanf("%d", &n);
        cloth list[n];
        int length=0;


        for(int j=0; j<n; j++) {
            char name[21], cons[21];
            scanf("%s %s", name, cons);
            int check=0;
            for(int k=0; k<length; k++) {
                if(strcmp(list[k].type, cons)==0) {
                    check++;
                    list[k].num++;
                    break;
                }
            }
            if(check==0) {
                strcpy(list[length].type, cons);
                list[length].num=1;
                length++;
            }

        }

        long long ans=1;
        for(int j=0; j<length; j++) {
            ans*=(list[j].num+1);
        }
        ans--;
        printf("%lld\n",ans);

    }

    return 0;
}
