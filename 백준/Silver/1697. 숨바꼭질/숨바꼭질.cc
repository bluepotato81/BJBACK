#include <iostream>
#include <queue>

using namespace std;

queue<int> location;

int visited[100001];

int main() {
    int n,k;
    scanf("%d %d",&n, &k);

    location.push(n);

    int moves=0;
    int check=0;

    if(n==k) {
        printf("0");
        return 0;
    }

    if(n>k) {
        printf("%d", n-k);
        return 0;
    }

    while(!check) {
        moves++;
        int queuemem=location.size();
        for(int i=0; i<queuemem;i++) {
            int cur=location.front();
            location.pop();
            if(cur-1>=0 && visited[cur-1]==0) {
                location.push(cur-1);
                if(cur-1==k) {
                    check++;
                    break;
                }
                visited[cur-1]=1;
            }
            if(cur+1<=100000 && visited[cur+1]==0) {
                location.push(cur+1);
                if(cur+1==k) {
                    check++;
                    break;
                }
                visited[cur+1]=1;
            }
            if(cur*2<=100000 && visited[cur*2]==0) {
                location.push(cur*2);
                if(cur*2==k) {
                    check++;
                    break;
                }
                visited[cur*2]=1;
            }
        }

    }

    printf("%d", moves);

    return 0;
}
