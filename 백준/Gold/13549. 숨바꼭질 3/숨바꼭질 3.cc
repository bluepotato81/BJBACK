#include <iostream>
#include <queue>

using namespace std;

queue<int> location;

int visited[100001]={0,};

int main() {
    int n,k;
    scanf("%d %d",&n, &k);

    location.push(n);
    visited[n]=1;
    if(n!=0) {
        for(int i=2; i*(n)<=100000 && i*n<=2*k; i*=2) {
            if(n*i<=100000) {
                location.push(n*i);
                if(n*i==k) {
                    printf("0");
                    return 0;
                }
                visited[n*i]=1;
            }
        }

    }
    
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
                if(cur-1!=0) {
                    for(int i=2; i*(cur-1)<=100000 && i * (cur-1) <= 2 * k; i*=2) {
                        if(visited[(cur-1)*i]==0) {
                            location.push((cur-1)*i);
                            if((cur-1)*i==k) {
                                check++;
                                break;
                            }
                            visited[(cur-1)*i]=1;
                        }
                    }
                }


            }
            if(cur+1<=k && visited[cur+1]==0) {
                location.push(cur+1);
                if(cur+1==k) {
                    check++;
                    break;
                }
                visited[cur+1]=1;
                for(int i=2; i*(cur+1)<=100000  && i * (cur+1) <= 2 * k; i*=2) {
                    if(visited[(cur+1)*i]==0) {
                        location.push((cur+1)*i);
                        if((cur+1)*i==k) {
                            check++;
                            break;
                        }
                        visited[(cur+1)*i]=1;
                    }
                }

            }
        }

    }

    printf("%d", moves);

    return 0;
}
