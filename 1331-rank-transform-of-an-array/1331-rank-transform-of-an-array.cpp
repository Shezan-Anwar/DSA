class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if( arr.size()==0){
            return {};
        }
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());
        int rankC = 1;
        unordered_map<int,int> rank;
        rank[copy[0]]=1;
        for ( int i = 1 ; i < copy.size(); i++){
            rankC = copy[i]>copy[i-1]? rankC+1 : rankC;
            rank[copy[i]]= rankC;
           
        }
        
        for(int i = 0 ;i< arr.size();i++){
            copy[i]=rank[arr[i]];
        }
        return copy; 
    }
};