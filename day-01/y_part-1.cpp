#include <algorithm>
#include <iostream>
#include <vector>

int main() {

  std::vector<int> left;
  std::vector<int> right;

  int l, r;
  while (std::cin >> l >> r) {
    left.push_back(l);
    right.push_back(r);
  }

  std::sort(left.begin(), left.end());
  std::sort(right.begin(), right.end());
  int sum = 0;
  // why do I need size_t here?
  for (std::size_t i = 0; i < left.size(); i++)
    sum += std::abs(left[i] - right[i]);

  std::cout << "result: " << sum << std::endl;
}
