// Search in Rotated Sorted Arrat containing Duplicates

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;

        int pivot = findPivot(nums);

        // if array is not rotated
        if(pivot == -1){
            return binarySearch(nums, target, 0, nums.size() - 1);
        }

        // if pivot itself is target
        if(nums[pivot] == target)
            return pivot;

        // search in left half
        int left = binarySearch(nums, target, 0, pivot - 1);
        if(left != -1)
            return left;

        // search in right half
        return binarySearch(nums, target, pivot, nums.size() - 1);
    }

    int findPivot(vector<int>& nums){
        int start = 0;
        int end = nums.size() - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            // Case 1: mid is pivot
            if(mid < end && nums[mid] > nums[mid + 1])
                return mid;

            // Case 2: mid-1 is pivot
            if(mid > start && nums[mid] < nums[mid - 1])
                return mid - 1;

            // Case 3: duplicates — shrink safely
            if(nums[start] == nums[mid] && nums[mid] == nums[end]){

                // check if start is pivot
                if(start < end && nums[start] > nums[start + 1])
                    return start;
                start++;

                // check if end-1 is pivot
                if(end > start && nums[end - 1] > nums[end])
                    return end - 1;
                end--;
            }
            // Case 4: left side sorted → pivot right
            else if(nums[start] < nums[mid] ||
                   (nums[start] == nums[mid] && nums[mid] > nums[end])){
                start = mid + 1;
            }
            // Case 5: pivot left
            else{
                end = mid - 1;
            }
        }

        return -1;
    }

    int binarySearch(vector<int>& nums, int target, int start, int end){
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(nums[mid] == target)
                return mid;
            else if(target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }

        return -1;
    }
};
