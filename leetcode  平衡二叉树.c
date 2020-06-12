/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
//分别求出左右子树的高度，判断相差的绝对值是否小于等于1
int getH(struct TreeNode* root){
	if (root == NULL){
		return 0;
	}
	int l = getH(root->left);
	int r = getH(root->right);
	return l>r ? l + 1 : r + 1;
}

bool isBalanced(struct TreeNode* root){
	if (root == NULL){
		return true;
	}
	int l = getH(root->left);
	int r = getH(root->right);
	return abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}