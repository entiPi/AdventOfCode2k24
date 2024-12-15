#include <algorithm> // count_if
#include <iostream>
#include <string> // getline
#include <sstream>
#include <ranges> // pairwise_transform, istream, to
#include <vector>

using namespace std;

int main() {

    int safe_record_count{0};
    for (string record_str; getline(cin, record_str); ) {
        istringstream record_sstr{record_str};
        auto subtract = [](int lhs, int rhs) -> int { return lhs - rhs; };
        const auto level_diffs = views::istream<int>(record_sstr) | ranges::to<vector>() | views::pairwise_transform(subtract) | ranges::to<vector>();

        auto greater_equal = [](auto limit) { return [limit](auto value) { return value >= limit; }; };
        const auto positive_count = ranges::count_if(level_diffs, greater_equal(0));
        if (positive_count != 0 and positive_count != ssize(level_diffs))
            // "unsafe, because levels are not monotous
            continue;

        auto absolute = [](auto x) { return x >= 0 ? x : -x; };
        const bool all_stepsize_ge_one = ranges::all_of(level_diffs | views::transform(absolute), greater_equal(1));
        if (not all_stepsize_ge_one)
            // "unsafe", because some levels differ by less than 1 (i.e. stay the same)
            continue;

        auto less_equal = [](auto limit) { return [limit](auto value) { return value <= limit; }; };
        const bool all_stepsize_le_three = ranges::all_of(level_diffs | views::transform(absolute), less_equal(3));
        if (not all_stepsize_le_three)
            // "unsafe", because some levels differ by more than 3
            continue;

        ++safe_record_count;
    }

    cout << safe_record_count << '\n';
}
