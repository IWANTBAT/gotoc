bool Isvalid(struct TreeNode* root, int val){
	if (root == NULL){
		return true;
	}
	if (root->val != val){
		return false;
	}
	return Isvalid(root->left, val) && Isvalid(root->right, val);
}

bool isUnivalTree(struct TreeNode* root){
	if (root == NULL){
		return true;
	}
	return Isvalid(root, root->val);
}
