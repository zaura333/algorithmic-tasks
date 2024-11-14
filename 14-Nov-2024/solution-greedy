public class Solution {
    public int MinimizedMaximum(int n, int[] quantities) {
        int storeCount;
        var typeStorePairs = new PriorityQueue<int[], int>(Comparer<int>.Create((x, y) => y.CompareTo(x)));
        int types = quantities.Length;

        foreach (int q in quantities) {
            typeStorePairs.Enqueue([q, 1], q);
        }

        storeCount = quantities.Length;

        for (int i = 0; i < n - types; i++) {
            int[] currPair = typeStorePairs.Dequeue();
            // Console.WriteLine("pA: {0}, type: {1}", currPair[0], currPair[1]);
            currPair[1] += 1;
            typeStorePairs.Enqueue(currPair, currPair[0] / currPair[1]);
            // Console.WriteLine(currPair[0] / currPair[1]);
            storeCount += 1;
        }

        Console.WriteLine(storeCount);

        var productsAmounts = new int[types];

        for (int i = 0; i < types; i++) {
            int[] currPair = typeStorePairs.Dequeue();
            productsAmounts[i] = currPair[0] / currPair[1];
            Console.WriteLine("pA: {0}, type: {1}, x: {2}", productsAmounts[i], currPair[0], currPair[1]);
        }

        

        return productsAmounts.Max();
    }
}
