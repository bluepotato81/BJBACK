#include <cstdio>

int nums[100005];
int main()
{
    int n, s;
    scanf("%d %d", &n, &s);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&nums[i]);
    }

    //[l, r] = [0, 0]
    //[l, r) = [0, 0)

    int l=0, r=0, sum = nums[0], len=n+1;
    while(r<n)
    {
        if(sum < s)
        {
            if(r == n-1)
                break;
            r++;
            sum+=nums[r];
        }
        else
        {
            if(len > r - l + 1)
                len = r - l + 1;
            sum-=nums[l];
            l++;
        }

    }
    if(len==n+1)
        printf("0");
    else
        printf("%d",len);


    return 0;
}

