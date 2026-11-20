#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int balloon[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &balloon[i]);
    }
    
    int popped = 0;
    int pos = 0;
    
    while (popped < n-1) {
        // Output the current position (1-based index)
        printf("%d ", pos + 1);
        
        // Determine the movement based on the number on the balloon
        int paper = balloon[pos];
        
        // Mark the current balloon as popped
        balloon[pos] = 0;
        popped++;
        
        // Move to the next balloon based on the number on the paper
        if (paper > 0) {
            // Move forward
            for (int i = 0; i < paper; i++) {
                do {
                    pos = (pos + 1) % n; // Move right in a circular manner
                } while (balloon[pos] == 0); // Skip popped balloons
            }
        } else if (paper < 0) {
            // Move backward
            for (int i = paper; i < 0; i++) {
                do {
                    pos = (pos - 1 + n) % n; // Move left in a circular manner
                } while (balloon[pos] == 0); // Skip popped balloons
            }
        }
    }
    
    for(int i=0; i<n; i++) {
    	if(balloon[i]!=0) {
    		printf("%d", i+1);
    	}
    }
    
    return 0;
}
