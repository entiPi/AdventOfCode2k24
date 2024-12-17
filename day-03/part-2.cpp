#include <iostream>
#include <regex>
#include <string> // getline, stoul

using namespace std;

struct state_machine {
    unsigned sum{0U};

    function<void(smatch const&)> current_state = [&](smatch const& token) {
        regex mul_or_dont_token{R"((don't|mul)\((?:(\d{1,3}),(\d{1,3}))?\))"};
        smatch subtoken;
        const auto token_str = token.str();
        if (not regex_match(token_str, subtoken, mul_or_dont_token))
            return;
        if (subtoken[1] == "don't")
            next_state();
        else if (subtoken[1] == "mul")
            sum += stoul(subtoken[2]) * stoul(subtoken[3]);
    };

    function<void(smatch const&)> passive_state = [&](smatch const& token) {
        if (token[0] == "do()") {
            next_state();
        }
    };

    void next_state() {
        swap(current_state, passive_state);
    }

    void handle_token(smatch const& token) {
        current_state(token);
    }
};

int main() {
    regex any_token{R"(do\(\)|don't\(\)|mul\(\d{1,3},\d{1,3}\))"};
    state_machine sm{};

    for (string corrupted_input; getline(cin, corrupted_input); ) {
        auto corrupted_input_iter = cbegin(corrupted_input);
        smatch next_token;
        while (corrupted_input_iter != cend(corrupted_input)) {
            if (not regex_search(corrupted_input_iter, cend(corrupted_input), next_token, any_token)) {
                break; /* eol */
            }
            sm.handle_token(next_token);
            corrupted_input_iter += next_token.position() + next_token.length();
        }
    }
    cout << sm.sum << '\n';
}
