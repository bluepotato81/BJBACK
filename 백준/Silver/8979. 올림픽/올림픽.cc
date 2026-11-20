#include <cstdio>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int tab[1005][4];
    int k_id;

    for(int i=0; i<n;i++)
    {
        for(int j=0; j<4; j++)
            scanf("%d", &tab[i][j]);
        if(tab[i][0] == k)
            k_id = i;
    }

    int rak=1;
    int space;
    for(int i=0; i<n; i++)
    {
        if(tab[i][1]>tab[k_id][1])
            rak++;
        else if(tab[i][1]==tab[k_id][1])
        {
            if(tab[i][2]>tab[k_id][2])
                rak++;
            else if(tab[i][2]==tab[k_id][2])
            {
                if(tab[i][3]>tab[k_id][3])
                    rak++;
            }
        }
    }

    printf("%d", rak);



    return 0;
}
