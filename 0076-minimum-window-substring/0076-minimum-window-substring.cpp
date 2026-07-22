class Solution {
public:
    string minWindow(string s, string t) {
      if(t.length()>s.length()|| s.empty() || t.empty()){
        return "";
      }
      if(s==t){
        return s;
      }
      vector<int> tFreq(128,0);
      for(char i : t){
        tFreq[i]++;
      }
      int left=0,right=0;
      vector<int> currFreq(128,0);
      int uniqueCount = 0;
      for(int i : tFreq){
        if(i>0){
            uniqueCount++;
        }
      }
      int startIdx =0 ;
      int minLen = INT_MAX;
      int formed = 0;
      while(right<s.length()){
        char c = s[right];
        currFreq[c]++;
        if(tFreq[c]>0 && tFreq[c]==currFreq[c]){
            formed++;
        }

        while(left<=right && formed==uniqueCount){
            if(right - left + 1 < minLen){
                minLen = right-left+1;
                startIdx=left;
            }
            char leftChar = s[left];
            currFreq[leftChar]--;
            if(tFreq[leftChar]>0 && currFreq[leftChar]<tFreq[leftChar]){
                formed--;
            }
            left++;
        }
        right++;
      }


      return minLen == INT_MAX ? "":s.substr(startIdx,minLen);
    }
};