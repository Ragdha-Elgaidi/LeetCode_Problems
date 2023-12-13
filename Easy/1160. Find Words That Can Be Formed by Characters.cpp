class Solution
{
public:
    int countCharacters(vector<string>& words, string chars)
    {
        // Initialize an array to store the counts of each character in chars
        vector<int> counts(26, 0);

        // Count the occurrences of each character in chars
        for (char c : chars)
        {
            counts[c - 'a']++;
        }
        
        int ans = 0;

        // Iterate through each word in the vector
        for (string word : words)
        {
            // Initialize an array to store the counts of each character in the current word
            vector<int> wordCount(26, 0);

            // Count the occurrences of each character in the current word
            for (char c : word)
            {
                wordCount[c - 'a']++;
            }
            
            // Check if the current word can be formed using the characters in chars
            bool good = true;

            // Compare the counts of each character in chars and the current word
            for (int i = 0; i < 26; i++) 
            {
                if (counts[i] < wordCount[i])
                {
                    good = false;
                    break;
                }
            }
            
            // If the current word can be formed, add its length to the total count
            if (good)
            {
                ans += word.size();
            }
        }
        
        // Return the total length of words that can be formed using the characters in chars
        return ans;
    }
};
