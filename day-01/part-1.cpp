#include <algorithm> // fold_left_first, sort, transform
#include <cmath> // abs
#include <iostream> // cin, cout
#include <ranges> // elements
#include <utility> // pair
#include <vector>

using namespace std;

int main() {
    vector<pair<int, int>> location_ids{};

    while (cin) {
        auto& [lhs, rhs] = location_ids.emplace_back();
        cin >> lhs >> rhs;
    }
    location_ids.pop_back();  // drop failed read from empty line

    ranges::sort(views::elements<0>(location_ids));
    ranges::sort(views::elements<1>(location_ids));
    auto difference = [](pair<int, int> const& p) -> int { return abs(p.first - p.second); };

    const auto total_distance = ranges::fold_left_first(
      views::transform(location_ids, difference),
      plus{});
    cout << *total_distance << '\n';
}
