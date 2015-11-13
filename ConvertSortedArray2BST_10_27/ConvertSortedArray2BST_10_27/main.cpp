#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};

TreeNode* generator(vector<int> array);
template<typename RandomAccessIterator>
TreeNode* sortedArrayToBST(RandomAccessIterator first, RandomAccessIterator last);

int main()
{
	vector<int> a({ 1, 2, 3, 4, 5, 6, 7});
	TreeNode *root = generator(a);

	return 0;
}

TreeNode* generator(vector<int> array)
{
	return sortedArrayToBST(array.begin(), array.end());
}

template<typename RandomAccessIterator>//RandomAccessIterator
TreeNode* sortedArrayToBST(RandomAccessIterator first, RandomAccessIterator last)
{
	const auto length = last - first;
	if (length <= 0) return nullptr;

	auto mid = first + length / 2;
	TreeNode *root = new TreeNode(*mid);
	root->left = sortedArrayToBST(first, mid);
	root->right = sortedArrayToBST(mid + 1, last);
	return root;
}