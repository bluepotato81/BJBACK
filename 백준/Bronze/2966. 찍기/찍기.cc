#include <cstdio>


int main()
{
    int n;
    scanf("%d", &n);
    char a[100], b[100], c[100];

    for(int i=0; i<n; i++)
    {
        if(i%3==0)
            a[i]='A';
        else if(i%3==1)
            a[i]='B';
        else
            a[i]='C';

        /*if((i+1)%3==0)
            a[i]='C';
        else if((i+1)%3==1)
            a[i]='A';
        else
            a[i]='B';*/

        if(i%2==0)
            b[i]='B';
        else if(i%4==1)
            b[i]='A';
        else
            b[i]='C';

        if(i%6==0 || i%6==1)
            c[i]='C';
        else if(i%6==2 || i%6==3)
            c[i]='A';
        else
            c[i]='B';

    }

    char ans[100];
    scanf("%s", ans);
    int ac=0, bc=0, cc=0;

    for(int i=0; i<n; i++)
    {
        if(ans[i]==a[i])
            ac++;
        if(ans[i]==b[i])
            bc++;
        if(ans[i]==c[i])
            cc++;
    }

    int max_=ac;
    if(max_<bc)
        max_=bc;
    if(max_<cc)
        max_=cc;
    printf("%d\n", max_);

    if(max_==ac)
        printf("Adrian\n");
    if(max_==bc)
        printf("Bruno\n");
    if(max_==cc)
        printf("Goran");



    return 0;
}

