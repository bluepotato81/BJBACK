#include <stdio.h>

int his[100000]; 
int stack[100000]; 
int top = -1;       

void push(int index) {
    stack[++top] = index;
}

int pop() {
    return stack[top--];
}
int peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

long long largestRectangleArea(int n) {
    long long max_area = 0;    
    int i = 0;

    while (i < n) {
        if (isEmpty() || his[peek()] <= his[i]) {
            push(i++);
        } else {
            int tp = pop();

            long long area_with_top = (long long)his[tp] * (isEmpty() ? i : i - peek() - 1);

            if (area_with_top > max_area) {
                max_area = area_with_top;
            }
        }
    }

    while (!isEmpty()) {
        int tp = pop();
        long long area_with_top = (long long)his[tp] * (isEmpty() ? i : i - peek() - 1);
        if (area_with_top > max_area) {
            max_area = area_with_top;
        }
    }

    return max_area;
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &his[i]);
        }

        long long max_area = largestRectangleArea(n);
        printf("%lld\n", max_area);
    }

    return 0;
}
