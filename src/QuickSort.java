class Solution {
    public int[] sortArray(int[] nums) {
        int len = nums.length;
        int l = 0, r = len-1;

        quicksort(nums, l, r);
        return nums;
    }

    public void quicksort(int[] nums, int l, int r) {

        if (l >= r) return;

        int pivot = handlePivot(nums, l, r);
        int guard = nums[r];

        int nextswap = l;
        for (int i = l; i < r; i++) {
            if (nums[i] <= guard) {
                int t = nums[nextswap];
                nums[nextswap] = nums[i];
                nums[i] = t;
                nextswap++;
            }
        }
        nums[r] = nums[nextswap];
        nums[nextswap] = guard;

        quicksort(nums, nextswap + 1, r);
        quicksort(nums, l, nextswap-1);
    }

    public void swap(int[] nums, int i1, int i2) {
        int t = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = t;
    }

    public int handlePivot(int[] nums, int l, int r) {
        int m = l + (r - l)/2;

        if (nums[l] > nums[m]) swap(nums, l, m);
        if (nums[l] > nums[r]) swap(nums, l, r);
        if (nums[m] < nums[r]) swap(nums, m, r);
   }
}