class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size()-1;
        int ptr1 = m-1;
        int ptr2 = n-1;

        while(true){
            if(ptr1 < 0 || ptr2 < 0) break;
            if(nums1[ptr1] <= nums2[ptr2]){
                nums1[i] = nums2[ptr2];
                i--;
                ptr2--;
            }else if(nums1[ptr1] > nums2[ptr2]){
                int temp = nums1[ptr1];
                nums1[ptr1] = nums1[i];
                nums1[i] = temp;
                ptr1--;
                i--;
            }
        }
        while(ptr2 >= 0){
            nums1[i] = nums2[ptr2];
            i--;
            ptr2--;
        }
    }
};