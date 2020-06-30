class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pointer1 = m - 1;
        int pointer2 = n - 1;
        int pointerResult = nums1.size() - 1;

        while(pointer1 >= 0 && pointer2 >= 0){
        	nums1[pointerResult--] = nums1[pointer1] > nums2[pointer2] ? nums1[pointer1--] : nums2[pointer2--];
        }

        while(pointer1 >= 0){
        	nums1[pointerResult--] = nums1[pointer1--];
        }

        while(pointer2 >= 0){
        	nums1[pointerResult--] = nums2[pointer2--];
        }
    }
};