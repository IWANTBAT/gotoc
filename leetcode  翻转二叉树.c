void inver(struct TreeNode* root){
	if (root){
		//交换交换
		struct TreeNode* tem = root->left;
		root->left = root->right;
		root->right = tem;
		inver(root->left);
		inver(root->right);
	}
}

struct TreeNode* invertTree(struct TreeNode* root){
	inver(root);
	return root;
}