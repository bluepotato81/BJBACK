#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int visited[10000];

int d(int n) {
    return (2*n)%10000;
}

int s(int n) {
    if(n==0) {
        return 9999;
    }
    else {
        return n-1;
    }
}

int l(int n) {
    int a=n/1000;
    int b=(n/100)%10;
    int c=((n/10)%100)%10;
    int d=n%10;

    return b*1000+c*100+d*10+a;
}

int r(int n) {
    int a=n/1000;
    int b=(n/100)%10;
    int c=((n/10)%100)%10;
    int d=n%10;

    return d*1000+a*100+b*10+c;
}

string bfs(int start, int target) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, string>> q;

    q.push({start, ""});
    visited[start] = 1;

    while (!q.empty()) {
        int current = q.front().first;
        string ops = q.front().second;
        q.pop();


        if (current == target) {
            return ops;
        }


        int next_d = d(current);
        if (!visited[next_d]) {
            visited[next_d] = 1;
            q.push({next_d, ops + "D"});
        }

        int next_s = s(current);
        if (!visited[next_s]) {
            visited[next_s] = 1;
            q.push({next_s, ops + "S"});
        }

        int next_l = l(current);
        if (!visited[next_l]) {
            visited[next_l] = 1;
            q.push({next_l, ops + "L"});
        }

        int next_r = r(current);
        if (!visited[next_r]) {
            visited[next_r] = 1;
            q.push({next_r, ops + "R"});
        }
    }

}



int main() {
    int t;
    scanf("%d", &t);

    for(int i=0; i<t; i++) {
        int a,b;
        scanf("%d %d", &a, &b);

        string result = bfs(a,b);
        cout << result << endl;
    }

    return 0;
}
