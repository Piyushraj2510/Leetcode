class Solution {
public:
    string addStrings(string num1, string num2) {

        string temp="";
        int i=num1.size()-1;
        int j=num2.size()-1;
        int sum=0;
        int carry=0;

        while(i>=0 || j>=0)
        {
            sum=carry;

            if(i>=0)
            {
                int digit1=num1[i]-'0';
                sum = sum+digit1;
                i--;
            }
            if(j>=0)
            {
                int digit2=num2[j]-'0';
                sum = sum+digit2;
                j--;
            }
            if(sum>9)
            {
                carry=sum/10;
                sum=sum%10;
            }
            else
            {
                carry =0;
            }
            
            temp.push_back(sum+'0');
        }
        if(carry)
        {
            temp.push_back(carry+'0');
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};