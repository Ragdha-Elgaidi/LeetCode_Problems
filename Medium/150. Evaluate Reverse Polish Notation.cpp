class Solution 
{
    long resolves(int a, int b, char op)
    {
        switch(op)
        {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return (long) a * b;
            case '/':
                return a / b;
            default:
                return 0;
        }
    }

public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<long>Stack;
        int n = tokens.size();
        
        for(int i = 0; i < n; i++)
        {
            if(tokens[i].size() == 1 and tokens[i][0] < 48)
            {
                int integer2 = Stack.top();
                Stack.pop();
                int integer1 = Stack.top();
                Stack.pop();

                char op = tokens[i][0];
                long ans = resolves(integer1, integer2, op);

                Stack.push(ans);
            }
            else
            {
                Stack.push(stol(tokens[i]));
            }
        }
        return Stack.top();
    }
};
