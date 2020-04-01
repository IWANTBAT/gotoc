#define SIZE 20000
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int *node = (int *)malloc(sizeof(int)* 1000);
	*returnSize = 0;
	struct TreeNode* stack[SIZE];
	int top = -1;
	struct TreeNode* p = root;
	while (p || top > -1) {
		if (p) {
			stack[++top] = p;
			node[(*returnSize)++] = p->val;
			p = p->left;
		}
		else {
			p = stack[top--];
			p = p->right;
		}
	}
	return node;
}
