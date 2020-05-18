﻿int maxDepth(struct TreeNode* root){
	if (root == NULL)
	{
		return 0;
	}
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	return l > r ? l + 1 : r + 1;
}