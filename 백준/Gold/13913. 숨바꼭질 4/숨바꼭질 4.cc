#include <iostream>
#include <queue>

using namespace std;

queue<int> location;

int visited[100001];
int manner[100001];

int main() {
    int n,k;
    scanf("%d %d",&n, &k);

    location.push(n);
    manner[n]=0;

    int moves=0;
    int check=0;

    if(n==k) {
        printf("%d\n%d", moves, n);
        return 0;
    }

    if(n>k) {
        printf("%d\n", n-k);
        for(int i=n; i>=k; i--) {
            printf("%d ", i);
        }
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
                manner[cur-1]=1;
                if(cur-1==k) {
                    check++;
                    break;
                }
                visited[cur-1]=1;
            }
            if(cur+1<=100000 && visited[cur+1]==0) {
                location.push(cur+1);
                manner[cur+1]=2;
                if(cur+1==k) {
                    check++;
                    break;
                }
                visited[cur+1]=1;
            }
            if(cur*2<=100000 && visited[cur*2]==0) {
                location.push(cur*2);
                manner[cur*2]=3;
                if(cur*2==k) {
                    check++;
                    break;
                }
                visited[cur*2]=1;
            }
        }

    }

    int history[moves];
    int index=k;
    int order=moves-1;


    while(index!=n) {
        history[order--]=index;
        if(manner[index]==1) {
            index++;
        }
        else if(manner[index]==2) {
            index--;
        }
        else if(manner[index]==3){
            index/=2;
        }
    }
    printf("%d\n", moves);
    printf("%d ", n);
    for(int i=0; i<moves;i++) {
        printf("%d ", history[i]);
    }





    return 0;
}
