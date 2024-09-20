class Solution {
public:
    int lengthOfLastWord(string s) {
        int ssize =s.size();
        int n =ssize-1;
        //first occurence
        while(n>=0 && s[n]==' '){
            n=n-1;
        }

        //now we find the last letter 
        int count =0;
        while (n>=0 && s[n]!=' '){
            count++;
            n--;
        }

        return count;
    }
};