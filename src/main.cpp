// Copyright 2022 NNTU-CS
#include "tree.h"
#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <vector>

void PrintVector(const std::vector<char>& vec) {
  for (char c : vec) {
    std::cout << c;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> sizes = {3, 4, 5, 6, 7};
  std::vector<double> t1;
  std::vector<double> t2;
  std::vector<double> t3;

  std::random_device rd;
  std::mt19937 gen(rd());

  for (int n : sizes) {
    std::vector<char> input;
    for (int i = 0; i < n; ++i) {
      input.push_back('1' + i);
    }

    PMTree tree(input);
    int total = tree.factorial(n);
    std::uniform_int_distribution<> dis(1, total);
    int k = dis(gen);

    auto start = std::chrono::high_resolution_clock::now();
    auto perms = getAllPerms(tree);
    auto end = std::chrono::high_resolution_clock::now();
    t1.push_back(std::chrono::duration<double, std::milli>(end - start).count());

    start = std::chrono::high_resolution_clock::now();
    auto p1 = getPerm1(tree, k);
    end = std::chrono::high_resolution_clock::now();
    t2.push_back(std::chrono::duration<double, std::milli>(end - start).count());

    start = std::chrono::high_resolution_clock::now();
    auto p2 = getPerm2(tree, k);
    end = std::chrono::high_resolution_clock::now();
    t3.push_back(std::chrono::duration<double, std::milli>(end - start).count());

    std::cout << "n = " << n << ", k = " << k << " → getPerm2: ";
    PrintVector(p2);
  }

  std::ofstream out("C:\\Users\\jolly\\CLionProjects\\ADS-9-main\\result\\times.csv");
  out << "n,getAllPerms,getPerm1,getPerm2\n";

  for (size_t i = 0; i < sizes.size(); ++i) {
    out << sizes[i] << "," << t1[i] << "," << t2[i] << "," << t3[i] << "\n";
  }
  out.close();

  std::cout << "Timing results saved to result/times.csv\n";

  return 0;
}
