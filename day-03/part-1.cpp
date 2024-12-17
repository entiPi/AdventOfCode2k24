#include <algorithm> // fold_left, fold_left_first
#include <iostream>
#include <string> // getline
#include <regex>

using namespace std;

int main() {
    regex mul_token{R"(mul\((\d{1,3}),(\d{1,3})\))"};
    auto sum{0U};
    for (string corrupted_input; getline(cin, corrupted_input); ) {
        sum = ranges::fold_left(
          sregex_iterator{begin(corrupted_input), end(corrupted_input), mul_token},
          sregex_iterator{},
          sum,
          [](unsigned acc, smatch match) { return acc + stoi(match[1]) * stoi(match[2]); }
        );
    }
    cout << sum << '\n';
}
