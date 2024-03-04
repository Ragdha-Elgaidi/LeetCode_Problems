class Solution 
{
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
    sort(tokens.begin(), tokens.end()); // Sort the tokens array
    int left = 0, right = tokens.size() - 1; // Initialize pointers for leftmost and rightmost elements
    int score = 0;
    int max_score = 0;

    while (left <= right) 
    {
        // If current power is greater than or equal to the leftmost token, play it face-up
        if (power >= tokens[left]) 
        {
            power -= tokens[left];
            left++;
            score++;
            max_score = max(max_score, score); // Update max_score if current score is greater
        }
        // If current score is greater than 0, play the rightmost token face-down
        else if (score >= 1) 
        {
            power += tokens[right];
            right--;
            score--;
        }
        // If neither condition is met, break the loop
        else 
        {
            break;
        }
    }
    return max_score;
}
};
