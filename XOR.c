#include <stdlib.h>

// Trie node structure format
typedef struct TrieNode {
    struct TrieNode* children[2];
} TrieNode;

// Puthiya Trie node create panna function
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->children[0] = NULL;
    node->children[1] = NULL;
    return node;
}

// Number ah binary bits ah Trie la insert panna function
void insert(TrieNode* root, int num) {
    TrieNode* curr = root;
    for (int i = 30; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (curr->children[bit] == NULL) {
            curr->children[bit] = createNode();
        }
        curr = curr->children[bit];
    }
}

// Entha number kooda XOR panna maximum value varumnu check panna function
int getMaxXOR(TrieNode* root, int num) {
    TrieNode* curr = root;
    int maxXOR = 0;
    for (int i = 30; i >= 0; i--) {
        int bit = (num >> i) & 1;
        // Maximum XOR varanum na namaku opposite bit venum (0 ku 1, 1 ku 0)
        int oppositeBit = 1 - bit; 
        
        if (curr->children[oppositeBit] != NULL) {
            maxXOR |= (1 << i); // Bit set panrom
            curr = curr->children[oppositeBit];
        } else {
            curr = curr->children[bit];
        }
    }
    return maxXOR;
}

// Memory leak aagama iruka Trie nodes ah free panna function
void freeTrie(TrieNode* root) {
    if (root == NULL) return;
    freeTrie(root->children[0]);
    freeTrie(root->children[1]);
    free(root);
}

int findMaximumXOR(int* nums, int numsSize) {
    if (numsSize < 2) return 0;
    
    TrieNode* root = createNode();
    int globalMaxXOR = 0;
    
    // First number ah mattum trie la podrom
    insert(root, nums[0]);
    
    // Aduthu vara numbers ku max XOR kandupடிச்சு, parallel ah trie layum insert panrom
    for (int i = 1; i < numsSize; i++) {
        int currentMax = getMaxXOR(root, nums[i]);
        if (currentMax > globalMaxXOR) {
            globalMaxXOR = currentMax;
        }
        insert(root, nums[i]);
    }
    
    freeTrie(root); // Memory clean up
    return globalMaxXOR;
}
