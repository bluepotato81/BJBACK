#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        priority_queue<int> pq;
        int m;
        scanf("%d", &m);
        printf("%d\n", m/2+1);

        int in1, in2;
        int printed=0;
        scanf("%d", &in1);
        pq.push(in1);
        printf("%d ", in1);
        printed++;

        for(int i=0; i<m/2;i++) {
            scanf("%d %d", &in1, &in2);
            pq.push(in1);
            pq.push(in2);
            queue<int> temp;
            for(int j=0; j<i+1;j++) {
                temp.push(pq.top());
                pq.pop();
            }
            printf("%d ", pq.top());
            for(int j=0;j<i+1;j++) {
                pq.push(temp.front());
                temp.pop();
            }
            printed++;
            if(printed%10==0) {
                printf("\n");
            }
        }


    }

    return 0;
}
