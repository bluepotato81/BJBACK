#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int top;
    int bottom;
    int dir;
} frac;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int compare(frac a, frac b) {

    return a.dir==b.dir ? (a.top == b.top ? a.bottom < b.bottom : a.top < b.top) : a.dir<b.dir;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<frac> fractions;

    for (int i = 0; i < n; i++) {
        int a, b;
       	scanf("%d %d",&a, &b);

        int g = gcd(a, b);
        frac reduced;
        reduced.top = b / g;
        reduced.bottom = a / g;
    	if(a>0) {
    		reduced.dir=1;
    	}
    	else if(a<0) {
    		reduced.dir=-1;
    	}
    	else{
    		if(b>0) {
    			reduced.dir=1;
    		}
    		else {
    			reduced.dir=-1;
    		}
    	}

        fractions.push_back(reduced);
    }

    sort(fractions.begin(), fractions.end(), compare);

    int maxCount = 1;
    int currentCount = 1;

    for (int i = 1; i < n; i++) {
        if (fractions[i].dir==fractions[i-1].dir && fractions[i].top == fractions[i-1].top && fractions[i].bottom == fractions[i-1].bottom) {
            currentCount++;
        } else {
            maxCount = max(maxCount, currentCount);
            currentCount = 1;
        }
    }

    maxCount = max(maxCount, currentCount); 

    cout << maxCount << endl;

    return 0;
}
