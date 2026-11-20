#include <iostream>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int>> big;
priority_queue<int> small;

int nums[100000];

void see(int a, int num) {
    if(num%2==1) {
        if(a>=big.top()) {
            big.push(a);
            int k=big.top();
            big.pop();
            small.push(k);
        }
        else {
            small.push(a);
        }
    }
    else {
        small.push(a);
        int k=small.top();
        small.pop();
        big.push(k);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }

    if(n==1) {
        printf("%d", nums[0]);
    }
    if(n==2) {
        if(nums[1]>nums[0]) {
            printf("%d\n%d", nums[0],nums[0]);
        }
        else {
            printf("%d\n%d", nums[0], nums[1]);
        }
    }

    if(nums[0]<nums[1]) {
        big.push(nums[1]);
        small.push(nums[0]);
        printf("%d\n%d\n", nums[0], nums[0]);
    }
    else {
        big.push(nums[0]);
        small.push(nums[1]);
        printf("%d\n%d\n",nums[0],nums[1]);
    }


    for(int i=2;i<n;i++) {
        see(nums[i],i+1);
        printf("%d\n", small.top());
    }


    return 0;
}
