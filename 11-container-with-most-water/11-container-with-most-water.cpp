class Solution {
public:
    
    // static bool comp(pair<int, int>& a, pair<int, int>& b) {
    //     if(a.second > b.second) return true;
    //     else return false;
    // }
    
    int maxArea(vector<int>& height) {
        // vector<pair<int, int>> vec;
        // for(int i=0; i<height.size(); i++) {
        //     vec.push_back({i, height[i]});
        // }
        // sort(vec.begin(), vec.end(), comp);
        // int area = 0;
        // for(int i=0; i<vec.size()-1; i++) {
        //     for(int j=i+1; j<vec.size(); j++) {
        //         area = max(area, (abs(vec[i].first - vec[j].first) * min(vec[i].second, vec[j].second)));   
        //     }
        // }
        // return area;
        
        int start = 0, end = height.size()-1;
        int area = 0;
        while(start < end) {
            if(height[start] < height[end]) {
                area = max(area, height[start] * abs(end - start));
                start++;
            }
            //if (height[start] > height[end])
            else  {
                area = max(area, height[end] * abs(end - start));
                end--;
            }
            // else {
            //     area = max(area, height[end] * abs(end - start));
            //     if(height[start+1] > height[end-1]) start++;
            //     else end--;
            // }
        }
        return area;
    }
};