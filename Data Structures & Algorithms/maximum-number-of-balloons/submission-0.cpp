class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // use a hash map for char cnt
        vector<int> char_cnt(26, 0);
        for (auto c: text) {
            char_cnt[c - 'a'] += 1;
        }
        // 'b' once
        // 'a' once
        // 'l' twice
        // 'o' twice
        // 'n' once
        return min(
                min(
                min(
                min(
                    char_cnt['l' - 'a'] / 2, char_cnt['o' - 'a'] / 2), 
                char_cnt['n' - 'a']), 
                char_cnt['a' - 'a']), 
                char_cnt['b' - 'a']);
    }
};