#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createTreeNode(int val) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (!node) return NULL;
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode *insertBST(TreeNode *root, int val) {
    if (!root) return createTreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else if (val > root->val) root->right = insertBST(root->right, val);
    return root;
}

void inorder(TreeNode *node, int *result, int *idx) {
    if (!node) return;
    inorder(node->left, result, idx);
    result[(*idx)++] = node->val;
    inorder(node->right, result, idx);
}

void bstSort(int *arr, int n) {
    TreeNode *root = NULL;
    int i, idx = 0;
    for (i = 0; i < n; i++) {
        root = insertBST(root, arr[i]);
    }
    inorder(root, arr, &idx);
}

int main() {
    int arr[] = {5, 3, 7, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    
    bstSort(arr, n);
    
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}