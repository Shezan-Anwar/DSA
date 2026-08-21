class Solution {
public:
    long long lcm (long long a, long long b){
        return (a/gcd(a,b))*b;
    }
    void getCount(int idx, int count , long long currLcm,long long M, const vector<int>& coins, long long& total){
        if(idx == coins.size()){
            if(count>0){
                if(count % 2 ==1){
                    total+= M/currLcm;
                }else{
                    total-=M/currLcm;
                }
            }
            return;
        }
        getCount(idx+1,count,currLcm,M,coins,total);

        long long nextLcm = lcm(currLcm , coins[idx]);
        if(nextLcm <= M){
            getCount(idx + 1, count + 1, nextLcm, M, coins, total);
        }
    }
    long long countMul(long long M, const vector<int>& coins){
        long long total = 0;
        getCount(0,0,1,M,coins,total);
        return total;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
       long long low =1 ;
       long long minCoin = *min_element(coins.begin(),coins.end());
       long long high = minCoin * k;
       long long ans = high;

       while(low<=high){
        long long mid = low + (high-low)/2;
        if(countMul(mid,coins)>=k){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
       }
       return ans;
    }
};