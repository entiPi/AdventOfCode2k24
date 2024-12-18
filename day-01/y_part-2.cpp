#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

int main() {

  std::vector<int> left;
  std::vector<int> right;

  int l, r;
  while (std::cin >> l >> r) {
    left.push_back(l);
    right.push_back(r);
  }

  std::set<int> unique{left.begin(), left.end()};
  std::unordered_map<int, int> counts;

  // could probably use int element : unique
  for (const auto &element : unique) {
    counts[element] = std::count(right.begin(), right.end(), element);
  }

  int res = 0;
  for (const auto &element : left) {
    res += element * counts[element];
  }
  std::cout << "result: " << res << std::endl;
}
