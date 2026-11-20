#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& in, int data, int n) {
    int i = 0;
    for (i = 0; i < n; i++)
        if (in[i] == data)
            return i;
    return i;
}


void fillPre(vector<int>& in, vector<int>& post, int inStrt,
            int inEnd, stack<int> &s, int n, int &postIndex) {
    if (inStrt > inEnd)
        return;


    int val = post[postIndex];
    int inIndex = search(in, val, n);
    postIndex--;


    fillPre(in, post, inIndex + 1, inEnd, s, n, postIndex);


    fillPre(in, post, inStrt, inIndex - 1, s, n, postIndex);

    s.push(val);
}


vector<int> getPreorderTraversal(vector<int>& in, vector<int>& post, int n) {
    int len = n;
    int postIndex = len - 1;
    stack<int> s;
    fillPre(in, post, 0, len - 1, s, n, postIndex);
      vector<int> result;
    while (s.size() > 0) {
          result.push_back(s.top());
        s.pop();
    }
      return result;
}

int main() {
    vector<int> in;
    vector<int> post;
    int n;
    scanf("%d", &n);

    int a;
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        in.push_back(a);
    }

    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        post.push_back(a);
    }

    vector<int> result = getPreorderTraversal(in, post, n);
      for(int i : result) {
        cout << i << " ";
    }
}
