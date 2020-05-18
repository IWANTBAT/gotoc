void inOrder(struct TreeNode* root, int *arr, int* idx){
	if (root){
		//arr[(*idx)++] = root->val;放在这里就是前序遍历
		inOrder(root->left, arr, idx);
		arr[(*idx)++] = root->val;//放在这里就是中序遍历
		inOrder(root->right, arr, idx);
		//arr[(*idx)++] = root->val;放在这里就是后序遍历
	}
}
int getSize(struct TreeNode* root){
	if (root == NULL){
		return 0;
	}
	return getSize(root->left) + getSize(root->right) + 1;
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int num = getSize(root);
	int* ret = (int*)malloc(sizeof(int)*num);
	int idx = 0;
	inOrder(root, ret, &idx);//idx要传指针是因为他是一个局部变量，会导致内存重叠
	*returnSize = num;
	return ret;
}
