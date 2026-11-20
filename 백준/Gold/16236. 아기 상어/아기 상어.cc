#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct{
    int x;
    int y;
    int moves;
}locin;

int sea[20][20];
int sharksize=2;
int tosize=0;
int sharkx, sharky;
int time;

vector<vector<int>> visited;
queue<locin> loc;

int dx[] = {0,-1,1,0};
int dy[] = {-1,0,0,1};

int bfs(int n, int x, int y) {
    loc = queue<locin>();
    visited.assign(n, vector<int>(n, 0));

    loc.push({x, y, 0});
    visited[y][x] = 1;

    vector<locin> fish;
    int min_distance = -1;

    while(!loc.empty()) {
        locin current=loc.front();
        loc.pop();

        int inx=current.x;
        int iny=current.y;
        int curmoves=current.moves;

        if (min_distance!=-1&&curmoves>min_distance) {
            break;
        }

        for (int i= 0; i< 4;i++) {
            int nx=inx+dx[i];
            int ny=iny+dy[i];

            if (nx>=0&& nx <n &&ny >= 0 && ny<n && sea[ny][nx]<=sharksize&&visited[ny][nx]==0) {
                loc.push({nx, ny, curmoves + 1});
                visited[ny][nx] = 1;

                if (sea[ny][nx] > 0 && sea[ny][nx] < sharksize) {
                    if (min_distance==-1|| curmoves+1==min_distance) {
                        fish.push_back({nx,ny, curmoves+1});
                        min_distance=curmoves+1;
                    }
                }
            }
        }

    }

    if (fish.empty()) {
        return 0;
    }

    sort(fish.begin(), fish.end(), [](locin a, locin b) {
        if (a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });

    locin target = fish[0];
    sharkx=target.x;
    sharky=target.y;
    sea[sharky][sharkx]=0;

    tosize++;
    if (tosize == sharksize) {
        sharksize++;
        tosize = 0;
    }

    return target.moves;

    return 0;

}



int main() {
    int n;
    scanf("%d", &n);

    visited.resize(n);

    for(int i=0; i<n; i++) {
        visited[i].resize(n);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &sea[i][j]);
            if(sea[i][j]==9) {
                sharkx=j;
                sharky=i;
                sea[i][j]=0;
            }
        }
    }

     while (true) {
        int result=bfs(n, sharkx, sharky);
        if (result==0) {
            break;
        }
        time += result;
    }

    printf("%d", time);

    return 0;
}
