class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0 ; i<nums1.size() ; i++){
            int el = nums1[i];
            for(int j = 0 ; j<nums2.size(); j++){
                int flag = 0;
                if(j == nums2.size()-1 && nums2[j] == el){ ans.push_back(-1); continue;}
                if(nums2[j] == el){
                    flag  = 0;
                    for(int k = j+1; k<nums2.size() ; k++){
                        if(nums2[k] > el){
                            ans.push_back(nums2[k]);flag  = 1; break;
                        }
                        if(k == nums2.size()-1 && flag == 0) ans.push_back(-1);
                    }
                }
                if(flag == 1) break;
            }
        }
        return ans;
    }
};