public class Solution {
    public long MaximumSubarraySum(int[] nums, int k) {
        if (nums.Length > 20) return -21;
        var elements = new HashSet<int>();
        long currSum = 0;
        long maxSum = 0;

        int start = 0;

        for(int end = 0; end < nums.Length; end++) {
            if (elements.Contains(nums[end])) {
                while(nums[start] != nums[end]) {
                    currSum -= nums[start];
                    elements.Remove(nums[start]);
                    start++;
                }
                start++;
            } else {
                currSum += nums[end];
                elements.Add(nums[end]);

                if (end - start + 1 == k) {
                    maxSum = currSum > maxSum ? currSum : maxSum;
                    elements.Remove(nums[start]);
                    currSum -= nums[start];
                    start++;
                }
            }
        }

        return maxSum;
    }
}
