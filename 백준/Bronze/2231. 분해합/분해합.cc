#include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);

    for(int i=1; i<n; i++)
    {
        int a=i;
        int sum = i;
        while(a)
        {
            sum += a%10;
            a /= 10;
        }

        /*for(int j=7; j>0; j++)
        {
            int ten=1;
            for(int k=0; k<j; k++)
                ten=ten*10;
            a=a+(a/ten);
        }*/

        if(sum==n)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("0");

    return 0;

}

