#include <stdio.h>
#include <string.h>

// Global array allocated in BSS segment to prevent Stack Overflow
char s[200005];

void solve() {
    // Read the large number as a string
    if (scanf("%s", s) != 1) return;
    
    int len = strlen(s);
    int carry = 1; // Initially adding 1 to the number
    
    // Process digits from right to left
    for (int i = len - 1; i >= 0; i--) {
        int current_digit = s[i] - '0';
        int sum = current_digit + carry;
        
        if (sum >= 10) {
            s[i] = '0'; // Current position becomes 0 (e.g., 9 + 1 = 10 -> '0')
            carry = 1;  // Carry moves to the next left digit
        } else {
            s[i] = sum + '0'; // Simply update the digit
            carry = 0;        // No more carry, stop processing
            break;
        }
    }
    
    // If there is still a carry left after the loop (e.g., 99 -> 100)
    if (carry == 1) {
        printf("1"); // Print the leading '1'
    }
    
    // Print the updated string
    printf("%s\n", s);
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
