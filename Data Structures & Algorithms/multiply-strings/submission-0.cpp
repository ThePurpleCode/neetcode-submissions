class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> ans(n+m,0);

        for(int i =m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int d1 = (num1[i]-'0');
                int d2 = (num2[j]-'0');
                int mul = d1*d2;

                int p1 = i+j; // carry pos;
                int p2 = i+j+1; // unit pos 

                int sum = mul + ans[p2];
                ans[p2] = sum%10;
                ans[p1] += sum/10;
            }
        }

        string res = "";
        bool leading0= true;
        for(auto x:ans){
            if(x!=0) leading0 = false;
            if(x==0 && leading0) continue;
            if(!leading0){
                res += to_string(x);
            }
        }
        if(res.empty()) return "0";
        return res;
        
    }
};
