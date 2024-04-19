#include <iostream>
#include "BinaryTree.h"
using namespace std;

// TODO: solution breath first search
/**
 * traverser all level
*/
/**
 * target function
*/
void Solution::dfs_sum(TreeNode *currentNode, int& sum, int lastNumber)
{
    if (!currentNode) return;

    // colect number
    int number = lastNumber;
    number = number * 10 + currentNode->val;

    // left
    if (currentNode->left) {
        dfs_sum(currentNode->left, sum, number);
    }

    // right
    if (currentNode->right) {
        dfs_sum(currentNode->right, sum, number);
    }

    // leaf
    if (!currentNode->left && !currentNode->right) {
        sum += number;
    }
}

/**
 * target function
*/
int Solution::sumNumbers(TreeNode *root)
{
    int sum = 0;
    dfs_sum(root, sum, 0);
    return sum;
}