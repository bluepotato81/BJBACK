#include <stdio.h>


int ans;
int student[100001];
int visited[100001];
int finished[100001];

void dfs(int a) {
    visited[a]=1;

    int next=student[a];
    if(!visited[next]) {
        dfs(next);
    }
    else if(!finished[next]) {
        for(int i=next; i!=a; i=student[i]) {
            ans++;
        }
        ans++;
    }
    finished[a]=1;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d", &student[i]);
        }

        for(int i=1; i<=n; i++) {
            visited[i]=0;
            finished[i]=0;
        }

        for(int i=1; i<=n; i++) {
            if(visited[i]==0) {
                dfs(i);
            }
        }
        printf("%d\n", n-ans);
        ans=0;
    }

    return 0;
}
