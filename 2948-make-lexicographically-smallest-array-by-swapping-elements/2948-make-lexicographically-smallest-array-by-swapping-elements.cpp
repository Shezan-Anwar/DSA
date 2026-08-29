class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> p(n);
        for(int i = 0 ; i < n ; i++){
            p[i]={nums[i],i};
        }

        sort(p.begin(),p.end());

        vector<int> res(n);
        int i = 0;
        while(i<n){
            int j=i+1;
            while(j<n && p[j].first-p[j-1].first<=limit){
                j++;
            }
            vector<int> idx;
            for(int k = i; k < j ; k++){
                idx.push_back(p[k].second);
            }

            sort(idx.begin(),idx.end());

            for(int k = 0 ; k<idx.size();k++){
                res[idx[k]]=p[i+k].first;
            }

            i=j;
        }
        return res;
    }
};