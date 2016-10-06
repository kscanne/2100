#include "book.h"
#include "BSTNode.h"

// Count the number of nodes in a binary tree
template <typename E>
int count(BinNode<E>* root) {
  if (root == NULL) return 0;  // Nothing to count
  return 1 + count(root->left())
           + count(root->right());
}

int max(int a, int b) {
  if (a>b) return a;
  return b;
}

template <typename E>
int height(BinNode<E>* root) {
  if (root == NULL) return 0;
  return 1+max(height(root->left()), height(root->right()));
}

template <typename E>
int leaf_count(BinNode<E>* root) {
  if (root == NULL) return 0;
  if (root->isLeaf()) return 1;
  return leaf_count(root->left())+leaf_count(root->right());
}

template <typename E>
int sum_nodes(BinNode<E>* root) {
  if (root == NULL) return 0;
  return root->element()+sum_nodes(root->left())+sum_nodes(root->right());
}

template <typename E>
bool search(BinNode<E>* root, const E& val) {
  if (root == NULL) return false;
  if (root->element() == val) return true;
  return (search(root->left(),val) || search(root->right(),val));
}

template <typename E>
void print_tree(BinNode<E>* root) {
  if (root == NULL) return;
  cout << root->element() << endl;
  print_tree(root->left());
  print_tree(root->right());
}

template <typename E>
void print_tree_by_level(BinNode<E>* root) {
}

int main()
{
  BSTNode<int,int>* root = new BSTNode<int,int>(1,1);
  BSTNode<int,int>* left = new BSTNode<int,int>(2,2);
  BSTNode<int,int>* right = new BSTNode<int,int>(3,3);
  left->setLeft(new BSTNode<int,int>(4,4));
  left->setRight(new BSTNode<int,int>(5,5));
  root->setLeft(left);
  root->setRight(right);
  print_tree(root);
  cout << " Node count = " << count(root) << endl;
  cout << " Height = " << height(root) << endl;
  cout << " Leaf count = " << leaf_count(root) << endl;
  cout << " Sum of node values = " << sum_nodes(root) << endl;
  for (int i=0; i <= 6; i++) {
    if (search(root, i)) {
      cout << "Found " << i << " in the tree..." << endl;
    }
    else {
      cout << "Did not find " << i << " in the tree..." << endl;
    }
  }
}
