#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct{
    int x;
    int y;
    int speed;
    int dir;
    int big;
    int exist;
    int moved;
}shark;

vector<vector<vector<int>>> ocean;

shark sharks[10001];

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

void move(int r, int c, int m) {
    vector<vector<vector<int>>> new_ocean(r + 1, vector<vector<int>>(c + 1));
    for (int i = 1; i <= m; i++) {
        if (!sharks[i].exist) continue;

        int x = sharks[i].x, y = sharks[i].y, speed = sharks[i].speed, dir = sharks[i].dir;
        int big = sharks[i].big;

         if (dir == 1 || dir == 2) { 
            int effective_speed = speed % (2 * (r - 1));
            for (int step = 0; step < effective_speed; step++) {
                if (x == 1 && dir == 1) dir = 2; 
                else if (x == r && dir == 2) dir = 1; 
                x += dx[dir];
            }
        } else if (dir == 3 || dir == 4) { 
            int effective_speed = speed % (2 * (c - 1));
            for (int step = 0; step < effective_speed; step++) {
                if (y == 1 && dir == 4) dir = 3;  
                else if (y == c && dir == 3) dir = 4;
                y += dy[dir];
            }
        }

        sharks[i].x = x;
        sharks[i].y = y;
        sharks[i].dir = dir;

        new_ocean[x][y].push_back(i);

    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (new_ocean[i][j].size() > 1) {
                int largest_shark = new_ocean[i][j][0];
                for (int k : new_ocean[i][j]) {
                    if (sharks[k].big > sharks[largest_shark].big) {
                        sharks[largest_shark].exist = 0;
                        //printf("er: %d\n", largest_shark);
                        largest_shark = k;
                    } else if(sharks[k].big < sharks[largest_shark].big){
                        sharks[k].exist = 0;
                        //printf("er: %d\n", k);
                    }
                }
                new_ocean[i][j].clear();
                new_ocean[i][j].push_back(largest_shark);
            }
        }
    }


    ocean = new_ocean;
    /*for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            if(!ocean[i][j].empty()) {
                printf("%d ", ocean[i][j][0]);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");*/
}

int main() {
    int r,c,m;
    scanf("%d %d %d", &r, &c, &m);
    ocean.resize(r+1, vector<vector<int>>(c+1));

    for(int i=1; i<=m; i++) {
        scanf("%d %d %d %d %d", &sharks[i].x,&sharks[i].y,&sharks[i].speed,&sharks[i].dir,&sharks[i].big);
        sharks[i].exist=1;
        ocean[sharks[i].x][sharks[i].y].push_back(i);
    }

    int ans=0;

    for (int col = 1; col <= c; col++) {
        //printf("2e: %d\n", sharks[2].exist);
        for (int row = 1; row <= r; row++) {
            if (!ocean[row][col].empty()) {
                int caught_shark = ocean[row][col][0];
                //printf("%d\n", caught_shark);
                ans += sharks[caught_shark].big;
                sharks[caught_shark].exist = 0;
                ocean[row][col].clear();
                break;
            }
        }
        move(r, c, m);

    }

    printf("%d\n", ans);

    return 0;
}
