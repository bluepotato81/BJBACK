#include <cstdio>

int main()
{
    int note[10000];
    int n, q;

    scanf("%d %d", &n, &q);

    int ans[q];

    int lisc=0, note_;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &note_);
        for(int j=0; j<note_; j++)
            {
                note[lisc]=i;
                lisc++;
            }
    }

    int que;
    for(int i=0; i<q; i++)
    {
        scanf("%d", &que);
        printf("%d\n", note[que]);
    }





    return 0;

}

