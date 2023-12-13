class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        //to store freq of each char of string s
        vector<int> vec(26,0);
        int count=0;

        //find freq of each char in string s
        for(int i=0; i<s.length(); i++) 
        { 
            vec[s[i]-'a']++;
        }

        while(1)
        {
            for(int i=0; i<target.length(); i++)
            {
                vec[target[i]-'a']--;

                //target cannot be formed from chars. in string s
                if(vec[target[i]-'a'] < 0) 
                {    
                    return count;
                }
            }
            //target can be formed from chars. in string s
            count++;  
        }
    }
};
