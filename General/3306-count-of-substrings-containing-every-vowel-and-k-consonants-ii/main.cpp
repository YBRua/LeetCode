// 3306-count-of-substrings-containing-every-vowel-and-k-consonants-ii

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool _has_every_vowel(const unordered_map<char, int>& vowels) {
        return (vowels.find('a') != vowels.end() && vowels.find('a')->second > 0) &&
               (vowels.find('e') != vowels.end() && vowels.find('e')->second > 0) &&
               (vowels.find('i') != vowels.end() && vowels.find('i')->second > 0) &&
               (vowels.find('o') != vowels.end() && vowels.find('o')->second > 0) &&
               (vowels.find('u') != vowels.end() && vowels.find('u')->second > 0);
    }

    bool _is_vowel(char ch) { return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; }

    long long countOfSubstrings(string word, int k) {
        unordered_map<char, int> vowels{{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        int n_consonants = 0;
        long long num = 0;
        int left = 0, right = 0;

        // initialize a lookup table to quickly find the next consonant
        vector<int> next_consonant(word.size());
        int next_idx = word.size();
        for (int i = word.size() - 1; i >= 0; --i) {
            next_consonant[i] = next_idx;
            if (!_is_vowel(word[i])) {
                next_idx = i;
            }
        }

        while (right < word.size()) {
            char curr = word[right];

            // expand the window to the right
            if (vowels.find(word[right]) != vowels.end()) {
                vowels[word[right]]++;
            } else {
                n_consonants++;
            }

            // shrink the window from the left when having more than k consonants
            while (n_consonants > k) {
                char start_char = word[left];
                if (_is_vowel(start_char)) {
                    vowels[start_char]--;
                } else {
                    n_consonants--;
                }
                left++;
            }

            // count number of valid substrings when constraint is satisfied
            while (left < word.size() && _has_every_vowel(vowels) && n_consonants == k) {
                num += next_consonant[right] - right;
                char start_char = word[left];
                if (_is_vowel(start_char)) {
                    vowels[start_char]--;
                } else {
                    n_consonants--;
                }
                left++;
            }

            right++;
        }

        return num;
    }
};
