#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

long long countVowels(string word) {
    long long counts = 0;
    int word_length = word.size();
    unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});

    // dpmat
    // contains number of substrings of length i that contain a vowel
    vector<long long> results(word_length, 0);

    results[0] = vowels.count(word[0]);
    for (int i = 1; i < word_length; ++i) {
        results[i] = results[i-1];
        if (vowels.count(word[i])) {
            // current is vowel
            // it adds i + 1 new unique substrings containing vowels
            results[i] += i + 1;
        }
    }

    for_each(results.begin(), results.end(), [&](long long x) {
        counts += x;
    });

    return counts;
}

int main() {
    string word = "aba";
    printf("%lld\n", countVowels(word));
    return 0;
}
