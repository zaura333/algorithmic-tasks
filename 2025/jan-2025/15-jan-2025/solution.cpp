// 2429. Minimize XOR

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        unsigned int num2Set = countSetBits(num2);
        unsigned int num1Set = countSetBits(num1);
        int bitsToAdd = num2Set - num1Set;
        
        if (bitsToAdd == 0) return num1;

        int result = num1;
        int bitsLeft =  bitsToAdd;

        if (bitsToAdd > 0) {
            int i = 0;

            while (bitsLeft) {
                if (!(result & (1 << i))) {
                    result = result | 1 << i;
                    bitsLeft--;
                }
                i++;
            }
        } else {
            int i = 0;

            while (bitsLeft < 0) {
                if (result & (1 << i)) {
                    result = result  & ~(1 << i);
                    bitsLeft++;
                }
                i++;
            }
        }
        
        return result;
    }
    
    unsigned int countSetBits(unsigned int n)
    {
        unsigned int count = 0;

        while (n) {
            count += n & 1;
            n >>= 1;
        }

        return count;
    }
};
