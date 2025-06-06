// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#pragma once
#include <memory>
#include <vector>

class PMTree {
 public:
  char value;
  std::vector<std::shared_ptr<PMTree>> children;

  PMTree() = default;
  PMTree(const std::vector<char>& elements);
  PMTree(const std::vector<char>& elements, const std::vector<char>& path);

  void collectPermutations(std::vector<std::vector<char>>& perms,
                           std::vector<char>& current);
  std::vector<char> getPerm1(int& counter, int target);
  std::vector<char> getPerm2(int target, int& factorialLevel) const;
  int factorial(int n) const;

 private:
  void build(const std::vector<char>& elements, const std::vector<char>& path);
};

std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int num);
std::vector<char> getPerm2(PMTree& tree, int num);

#endif  // INCLUDE_TREE_H_
