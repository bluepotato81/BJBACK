#include <iostream>
#include <deque>
#include <string.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        char input[100001];
        scanf("%s", input);
        size_t len = strlen(input);
        int n;
        scanf("%d", &n);


        deque<int> lis;

        char ch;
        scanf(" %c", &ch);

        for (int j = 0; j < n; j++) {
            int a;
            scanf("%d", &a);
            lis.push_back(a);
            if (j < n - 1) scanf(" %c", &ch);;
        }

        scanf(" %c", &ch);

        bool reversed = false;
        bool error = false;

        for (size_t j = 0; j < len; j++) {
            if (input[j] == 'R') {
                reversed = !reversed;
            } else {
                if (lis.empty()) {
                    printf("error\n");
                    error = true;
                    break;
                } else {
                    if (reversed) {
                        lis.pop_back();
                    } else {
                        lis.pop_front();
                    }
                }
            }
        }

        if (!error) {
            printf("[");
            while (!lis.empty()) {
                if (reversed) {
                    printf("%d", lis.back());
                    lis.pop_back();
                } else {
                    printf("%d", lis.front());
                    lis.pop_front();
                }
                if (!lis.empty()) {
                    printf(",");
                }
            }
            printf("]\n");
        }
    }

    return 0;
}
