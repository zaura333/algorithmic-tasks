// 2516. Take K of Each Character From Left and Right
public class Solution {
    public int TakeCharacters(string s, int k) {

        if (k == 0) return 0;
        
        char[] letters = ['a', 'b', 'c'];
        var frequencies = new Dictionary<char, int>();
        int result = Int32.MaxValue;
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

        for (int end = 0; end < s.Length; end++) {
        frequencies[s[end]] -= 1;

            while (frequencies['a'] < k || frequencies['b'] < k || frequencies['c'] < k) {
                frequencies[s[start]] += 1;
                start++;
            }

            if (frequencies['a'] >= k || frequencies['b'] >= k || frequencies['c'] >= k) {
                int currResult = s.Length - (end - start + 1);
                result = result < currResult ? result : currResult;
            }
            
        }

        return result;
    }
}
