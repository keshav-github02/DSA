class Solution {
public:
    long long solve(long long inp,string s,int limit){
        string str=to_string(inp);

        if(str.length()<s.length())
        return 0;


        long long ans=0;


        string laststr=str.substr(str.length()-s.length());
        int rem=str.length()-s.length();

        for(int i=0;i<rem;i++){
            int digit=str[i]-'0';
            if(digit<=limit){
                ans+=(digit*(pow(limit+1,rem-i-1)));
            }
            else{
                ans+=(pow(limit+1,rem-i));
                return ans;
            }
        }


        if(laststr>=s){
            ans++;
        }
        return ans;

    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {

        return solve(finish,s,limit)-solve((start-1),s,limit);
        
    }
};