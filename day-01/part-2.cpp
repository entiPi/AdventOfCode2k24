#include <algorithm> // fold_left_first, sort
#include <cstddef>  // size_t
#include <iostream> // cin, cout
#include <map>
#include <ranges> // transform
#include <vector>

using namespace std;

int main() {
    vector<int> left_location_ids{};
    map<int, size_t> right_location_ids{};

    for (int lhs, rhs;; cin >> lhs >> rhs) {
        if (not cin) break;

        left_location_ids.push_back(lhs);
        ++right_location_ids[rhs];
    }

    ranges::sort(left_location_ids);

    auto similarity_score = [&](int lhs) -> int {
        return lhs * right_location_ids[lhs];
    };

    const auto total_similarity_score = ranges::fold_left_first(
      ranges::views::transform(left_location_ids, similarity_score),
      plus{});
    cout << *total_similarity_score << '\n';
}
