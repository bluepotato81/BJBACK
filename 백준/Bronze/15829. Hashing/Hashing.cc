#include <stdio.h>

int main() {
    long long int total = 0;
    int n;
    
    // Read the length of the string
    scanf("%d", &n);
    
    char str[51];
    
    // Read the string
    scanf("%s", str);
    
    long long int power_of_31 = 1;
    const int MOD = 1234567891;

    for (int i = 0; i < n; i++) {
        // Adjust ASCII value to make 'a' = 1, 'b' = 2, ..., 'z' = 26
        int char_value = str[i] - 'a' + 1;
        
        // Update the total hash value
        total = (total + (char_value * power_of_31) % MOD) % MOD;
        
        // Compute the next power of 31, all operations modulo MOD
        power_of_31 = (power_of_31 * 31) % MOD;
    }

    // Print the resulting hash value
    printf("%lld", total);

    return 0;
}
