/**
 * T.C -- O(log(n))
 * S.C -- O(1)
 */




class Solution {
public:

    // Function to check if a bit is set at a given position.
    bool isSet(int &x, int bit) {
        return x & (1 << bit); // Checks if the bit at position `bit` is set (1).
    }

    // Function to set a bit at a given position.
    bool setBit(int &x, int bit) {
        return x |= (1 << bit); // Sets the bit at position `bit` to 1.
    }

    // Function to unset a bit at a given position.
    bool unsetBit(int &x, int bit) {
        return x &= ~(1 << bit); // Sets the bit at position `bit` to 0.
    }

    // Main function to minimize XOR between two numbers.
    int minimizeXor(int num1, int num2) {
        int x = num1; // Start with num1 as the base for the result.

        // Calculate the number of set bits (1s) in num2.
        int requiredSetBitCount = __builtin_popcount(num2);

        // Calculate the number of set bits (1s) in num1 (current `x`).
        int currSetBitCount = __builtin_popcount(x);

        // Position of the bit to examine or modify.
        int bit = 0;

        // Case 1: If current set bits are fewer than required.
        if (currSetBitCount < requiredSetBitCount) {
            while (currSetBitCount < requiredSetBitCount) {
                // If the bit at the current position is not set, set it.
                if (!isSet(x, bit)) {
                    setBit(x, bit);
                    currSetBitCount++; // Update the count of set bits.
                }
                bit++; // Move to the next bit position.
            }
        }
        // Case 2: If current set bits are more than required.
        else if (currSetBitCount > requiredSetBitCount) {
            while (currSetBitCount > requiredSetBitCount) {
                // If the bit at the current position is set, unset it.
                if (isSet(x, bit)) {
                    unsetBit(x, bit);
                    currSetBitCount--; // Update the count of set bits.
                }
                bit++; // Move to the next bit position.
            }
        }

        // Return the modified number `x` that minimizes XOR.
        return x;
    }
};
