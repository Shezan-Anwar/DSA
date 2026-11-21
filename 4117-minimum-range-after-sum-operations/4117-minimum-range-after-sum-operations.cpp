class Solution {
public:
    int minRange(int a, int b, int c) {
        int x = a, y = b, z=c;
        if(x>y){
            swap(x,y);
        }
        if(y>z){
            swap(y,z);
        }
        if(x>y){
            swap(x,y);
        }
        if(z>x+y){
            return y;
        }
        return z-x;
    }
};