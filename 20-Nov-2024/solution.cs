public class Solution {
    public int TakeCharacters(string s, int k) {
        if (k == 0) return 0;
        char[] letters = ['a', 'b', 'c'];
        var frequencies = new Dictionary<char, int>();
        var results = new List<int>();
        foreach(var l in letters) {
            frequencies.Add(l, 0);
        }
        
        for (int i = 0; i < s.Length; i++) {
            if (frequencies.ContainsKey(s[i]))
                frequencies[s[i]] += 1;
        }

        foreach (var f in frequencies.Values) {
            if (f < k) return -1;
        }

        int start = 0;
        int end = 0;

        while (start < s.Length && end < s.Length - 1) {
            // foreach (var f in frequencies.Values) {
            //     // Console.WriteLine("Elements: " + f);
            // }
            if (frequencies[s[end]] - 1 >= k) {
                frequencies[s[end]] -= 1;
                end++;
            } else {
                frequencies[s[start]] += 1;
                start++;
                if(end < start) {
                    end++;
                }
            }

            if (!frequencies.Values.Any(value => value < k)) {
                // Console.WriteLine(s.Length);
                // Console.WriteLine("added " + (s.Length - end + start));
                results.Add(s.Length - end + start);
            }
            // Console.WriteLine("start: {0}, end: {1}", start, end);
        }

        return results.Min();
    }
}
