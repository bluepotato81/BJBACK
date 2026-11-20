#include <cstdio>

int main()
{
    for(int i=0; i<3; i++)
    {
        char in[10];
        scanf("%s", in);

        int r=1, max_=1;
        for(int j=1; j<8; j++)
        {
            if(in[j]==in[j-1])
            {
                r++;
                if(r>max_)
                    max_=r;
            }
            else
                r=1;

        }
        printf("%d\n", max_);
    }


    return 0;

}

