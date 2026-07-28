/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    // Array oda size n + 1 aaga irukum
    *returnSize = n + 1;
    
    // Memory allocate panrom
    int* ans = (int*)malloc((*returnSize) * sizeof(int));
    
    // Base case: 0 kku binary la 0 ones thaan irukum
    ans[0] = 0;
    
    // Dynamic Programming (DP) use panni solve panrom
    for (int i = 1; i <= n; i++) {
        // i >> 1 engirathu (i / 2) oda bitwise value
        // i & 1 engirathu kadisi bit 1 ah nu check panrathu (Odd number ah iruntha +1 aagum)
        ans[i] = ans[i >> 1] + (i & 1);
    }
    
    return ans;
}
