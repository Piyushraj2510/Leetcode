class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size())
        {
            return false;
        }

        vector<int> count1(26,0);
        vector<int> count2(26,0);
        for(int i=0;i<s.size();i++)
        {
            count1[s[i]-'a']++;
            count2[t[i]-'a']++;
        }
    if(count1==count2)
    {
        return true;
    }

    return false;    
    }
};