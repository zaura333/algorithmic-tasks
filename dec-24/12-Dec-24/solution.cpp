// 2558. Take Gifts From the Richest Pile

class Solution {
public:
    priority_queue<int> createQueue(vector<int>& gifts) {
        priority_queue<int> q;

        for (int i = 0; i < gifts.size(); i++) {
            q.push(gifts[i]);
        }

        return q;
    }

    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q = createQueue(gifts);

        for (int i = 0; i < k; i++) {
            int g = q.top();
            q.pop();

            q.push(floor(sqrt(g)));
        }

        long long sum = 0;

        for (; !q.empty(); q.pop()) {
            sum += q.top();
        }

        return sum;
    }
};
