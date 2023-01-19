#include "BinaryTree.h"


BTNode* BinaryTreeCreate(BTDataType* a, int* pi){
	assert(a);
	assert(pi);
	if(a[*pi] == '#') return NULL;
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	assert(root);
	root->data = a[*pi];
	(*pi)++;
	root->left = BinaryTreeCreate(a,pi);
	(*pi)++;
	root->right = BinaryTreeCreate(a,pi);
	return root;
}

void BinaryTreeDestory(BTNode* root) {
    if(root == NULL) return;
    BinaryTreeDestory(root->left);
    BinaryTreeDestory(root->right);
	free(root);
}

int BinaryTreeSize(BTNode* root) {
	
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root) {
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL) return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k) {
	assert(k > 0);
	if(root == NULL) return 0;
	if(k == 1) return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	if(root == NULL) return NULL;
	if(root->data == x) return root;
	BTNode* left = BinaryTreeFind(root->left, x);
	if(left) return left;
	
	BTNode* right = BinaryTreeFind(root->right, x);
	if(right) return right;
	return NULL;
}

void BinaryTreePrevOrder(BTNode* root) {
	if(root == NULL) return;
	printf("%d ",root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

void BinaryTreeInOrder(BTNode* root) {
	if(root == NULL) return;
	
	BinaryTreeInOrder(root->left);
	printf("%d ",root->data);
	BinaryTreeInOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root) {
	if(root == NULL) return;
	
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%d ",root->data);
}

void BinaryTreeLevelOrder(BTNode* root) {
	Queue queue;
	QueueInit(&queue);
	if(root) QueuePush(&queue, root);
	while(!QueueEmpty(&queue)) {
		BTNode* front = QueueFront(&queue);
		QueuePop(&queue);
		printf("%d ",front->data);
		if(front->left) QueuePush(&queue, front->left);
		if(front->right) QueuePush(&queue, front->right);
	}
	printf("\n");
	QueueDestroy(&queue);
}

bool BinaryTreeComplete(BTNode* root) {
	Queue queue;
	QueueInit(&queue);
	if(root) QueuePush(&queue, root);
	while(!QueueEmpty(&queue)) {
		BTNode* front = QueueFront(&queue);
		QueuePop(&queue);
		if(front == NULL) break;
		QueuePush(&queue, front->left);
		QueuePush(&queue, front->right);
	}
	while(!QueueEmpty(&queue)) {
		BTNode* front = QueueFront(&queue);
		QueuePop(&queue);
		if(front != NULL) {
			QueueDestroy(&queue);
			return false;
		}
	}
	QueueDestroy(&queue);
	return true;
}