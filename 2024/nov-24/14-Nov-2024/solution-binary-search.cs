public class Solution {
    public int MinimizedMaximum(int n, int[] quantities) {
        int left = 0;
        int right = quantities.Max();

        while (left != right) {
            int mid = (left + right) / 2;
            
            if (CanDistribute(mid, quantities, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    public bool CanDistribute(int amount, int[] quantities, int stores) {
        int j = 0;
        int remaining = quantities[j];

        for (int i = 0; i < stores; i++) {
            remaining -= amount;

            if (remaining <= 0) {
                if (j < quantities.Length - 1) {
                    j++;
                    remaining = quantities[j];
                } else {
                    return true;
                }
            }

        }

        return false;
    }
}
