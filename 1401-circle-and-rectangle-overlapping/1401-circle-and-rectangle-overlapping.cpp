class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int left, int down, int right, int up) {
        int closestX = max(left, min(xCenter, right));
        int closestY = max(down, min(yCenter, up));
    
        int distX = xCenter - closestX;
        int distY = yCenter - closestY;
        
        return (distX * distX + distY * distY) <= (radius * radius);
    }
};