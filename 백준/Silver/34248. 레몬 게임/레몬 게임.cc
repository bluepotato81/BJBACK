#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int lemons[n];

    for(int i=0; i<n; i++) {
        scanf("%d", &lemons[i]);
    }

    stack<int> notdone;

    notdone.push(lemons[0]);
    for(int i=1; i<n;i++) {
        if(notdone.empty()) {
            notdone.push(lemons[i]);
            continue;
        }
        if(notdone.top()==1) {
            if(lemons[i]==2) {
                notdone.pop();
            }
            else {
                notdone.push(lemons[i]);
            }
        }
        else {
            if(lemons[i]==1) {
                notdone.pop();
            }
            else {
                notdone.push(lemons[i]);
            }
        }
    }

    int onum=0;
    while(!notdone.empty()) {
        int k=notdone.top();
        notdone.pop();
        if(k==2) {
            printf("No");
            return 0;
        }
        else {
            onum++;
        }
    }

    if(onum%3==0) {
        printf("Yes");
    }
    else {
        printf("No");
    }


    return 0;
}
