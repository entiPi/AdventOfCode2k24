#include <cmath> // signbit, abs
#include <iostream>
#include <string> // getline
#include <sstream>
#include <ranges> // istream, to
#include <vector>

using namespace std;

template<typename T>
T& read_or_assign(optional<T> &optional_, T const& default_) {
    if (not optional_)
      optional_ = default_;
    return *optional_;
}

bool is_record_safe(auto &&range) {
    auto adjacent_diffs = views::pairwise_transform(minus<>{});
    optional<bool> prev_direction;
    for (auto diff : range | adjacent_diffs) {
        if (
          auto absolute_diff = abs(diff);
          absolute_diff < 1 or absolute_diff > 3
        ) {
            return false;
        }
        if (
          auto curr_direction = signbit(diff);
          curr_direction != read_or_assign(prev_direction, curr_direction)
        ) {
            return false;
        }
    }
    return true;
}

int main() {
    int safe_record_count{0};
    for (string record_str; getline(cin, record_str); ) {
        istringstream record_sstr{record_str};
        auto levels = views::istream<int>(record_sstr) | ranges::to<vector>();

        for (size_t skip_index = 0; skip_index != size(levels); ++skip_index) {

          const int skip_store = levels[skip_index];
          levels.erase(begin(levels) + skip_index);

          if (is_record_safe(levels)) {
              ++safe_record_count;
              break;
          }

          levels.insert(begin(levels) + skip_index, skip_store);
        }
    }

    cout << safe_record_count << '\n';
}
