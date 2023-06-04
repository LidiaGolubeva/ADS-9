// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::string("File error!");
  }
  std::string word = "";
  BST<std::string> bst;
  while (!file.eof()) {
    word = "";
    while (1) {
      char character = file.get();
      if ((character >= 65 && character <= 90) || (character >= 97 && character <= 122)) {
        word += tolower(character);
      } else {
        break;
      }
    }
    bst.AddValue(word);
  }
  return bst;
}
