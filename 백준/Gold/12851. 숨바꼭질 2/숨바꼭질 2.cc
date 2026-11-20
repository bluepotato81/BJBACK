#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> location;

int visited[100001];

int main() {
    int n,k;
    scanf("%d %d",&n, &k);

    location.push(n);

    int moves=0;
    int check=0;
    int l=0;

    if(n==k) {
        printf("0\n1");
        return 0;
    }

    if(n>k) {
        printf("%d\n1", n-k);
        return 0;
    }

    while(!check) {
        vector<int> o;
        moves++;
        l=0;
        int queuemem=location.size();
        for(int i=0; i<queuemem;i++) {
            int cur=location.front();
            location.pop();
            if(cur-1>=0 && visited[cur-1]==0) {
                location.push(cur-1);
                if(cur-1==k) {
                    check++;
                    l++;
                }
                o.push_back(cur-1);
            }
            if(cur+1<=100000 && visited[cur+1]==0) {
                location.push(cur+1);
                if(cur+1==k) {
                    check++;
                    l++;
                }
                o.push_back(cur+1);
            }
            if(cur*2<=100000 && visited[cur*2]==0) {
                location.push(cur*2);
                if(cur*2==k) {
                    check++;
                    l++;
                }
                o.push_back(cur*2);
            }
        }
        int len=o.size();
        for(int i=0;i<len;i++) {
            visited[o[i]]=1;
        }

    }

    printf("%d\n%d", moves,l);

    return 0;
}
