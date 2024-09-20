class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        int l = size - 1;  // Start from the last character
        string ans = "";

        // Ignore trailing spaces
        while (l >= 0 && s[l] == ' ') {
            l--;
        }

        int last_count = l;  // Mark the last non-space character
        int first_count = l; // Use to track the first character of the current word

        while (l >= 0) {
            // When we find a space, it means the end of a word
            if (s[l] == ' ') {
                if (first_count != last_count) {
                    // Append the word to the result
                    ans += s.substr(first_count + 1, last_count - first_count);
                    ans += ' ';  // Add a space between words
                }

                // Skip over any extra spaces
                while (l >= 0 && s[l] == ' ') {
                    l--;
                }

                // Update the last_count for the next word
                last_count = l;
                first_count = l;
            } else {
                // Move left to continue scanning the word
                first_count--;
                l--;
            }
        }

        // Add the last word (if any)
        if (first_count != last_count) {
            ans += s.substr(first_count + 1, last_count - first_count);
        }

        // Remove trailing spaces (if any) after appending the last word
        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};
