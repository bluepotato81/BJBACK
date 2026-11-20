#include <iostream>
#include <queue>

using namespace std;

typedef struct{
    int start;
    int dest;
}bridge;

queue<int> loc;

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    int visited[101]={0};

    bridge ladder[n];
    bridge snake[m];

    for(int i=0; i<n; i++) {
        scanf("%d %d", &ladder[i].start, &ladder[i].dest);
    }

    for(int i=0; i<m; i++) {
        scanf("%d %d", &snake[i].start, &snake[i].dest);
    }

    loc.push(1);
    visited[1]=1;

    int moves=0;
    int check=0;

    while(!check) {
        moves++;
        int queuelen=loc.size();
        for(int i=0; i<queuelen;i++) {
            int cur=loc.front();
            loc.pop();
            for(int j=1; j<=6; j++) {
                int next=cur+j;
                if(next>100) {
                    continue;
                }
                for(int k=0;k<n; k++) {
                    if(next==ladder[k].start) {
                        next=ladder[k].dest;
                        break;
                    }
                }

                for(int k=0; k<m; k++) {
                    if(next==snake[k].start) {
                        next=snake[k].dest;
                        break;
                    }
                }

                if (!visited[next]) {
                    visited[next] = 1;
                    loc.push(next);
                }

                if (next == 100) {
                    check = true;
                    break;
                }

            }
            if(check) {
                break;
            }
        }
    }

    printf("%d", moves);



    return 0;
}
