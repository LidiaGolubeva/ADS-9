// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST {
 public:
  BST() :rootNd(nullptr) {}
  void AddValue(const T& value) {
  rootNd = addNode(rootNd, value);
  }
  int search(const T& value) {
  return searchNode(rootNd, value);
  }
  int depth() {
  return getDepth(rootNd) - 1;
  }

 private:
  struct Node {
  Node() :count(0), leftNd(nullptr), rightNd(nullptr) {}
  T value;
  int count;
  Node* leftNd;
  Node* rightNd;
  };
  Node* rootNd;

  Node* addNode(Node* rootNd, const T& value) {
  if (rootNd == nullptr) {
    rootNd = new Node;
    rootNd->value = value;
    rootNd->leftNd = nullptr;
    rootNd->rightNd = nullptr;
    rootNd->count = 1;
  } else if (rootNd->value > value) {
    rootNd->rightNd = addNode(rootNd->rightNd, value);
  } else if (rootNd->value < value) {
    rootNd->leftNd = addNode(rootNd->leftNd, value);
  } else {
    rootNd->count++;
  }
  return rootNd;
  }

  int searchNode(Node* root, const T& value) {
  if (root == nullptr) {
    return 0;
  } else if (root->value < value) {
    return searchNode(root->leftNd, value);
  } else if (root->value > value) {
    return searchNode(root->rightNd, value);
  } else if (root->value == value) {
    return root->count;
  }
  return 0;
  }

  int getDepth(Node* rootNd) {
  if (!rootNd) {
    return 0;
  }
  int rightTree = getDepth(rootNd->rightNd);
  int leftTree = getDepth(rootNd->leftNd);
  if (rightTree > leftTree) {
    return rightTree + 1;
  } else {
    return leftTree + 1;
  }
  }
};

#endif  // INCLUDE_BST_H_
