#include <bits/stdc++.h>
using namespace std;

/* -------------------------------------------------
   BASIC BIT OPERATIONS
------------------------------------------------- */

// Checks whether the i-th bit of n is 1 or 0
bool isBitSet(int n, int i) {
    return (n & (1 << i)) != 0;
}

// Sets (makes 1) the i-th bit of n
int setBit(int n, int i) {
    return n | (1 << i);
}

// Clears (makes 0) the i-th bit of n
int clearBit(int n, int i) {
    return n & ~(1 << i);
}

// Toggles (flips) the i-th bit of n
int toggleBit(int n, int i) {
    return n ^ (1 << i);
}

// Removes the rightmost set bit of n
int removeRightmostSetBit(int n) {
    return n & (n - 1);
}

/* -------------------------------------------------
   COUNTING & CHECKING
------------------------------------------------- */

// Counts number of set bits using Brian Kernighan’s algorithm
int countSetBits(int n) {
    int cnt = 0;
    while (n) {
        n &= (n - 1);
        cnt++;
    }
    return cnt;
}

// Checks if n is a power of 2 (only one set bit)
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Checks if n is power of 4 (single bit at even position)
bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
}

/* -------------------------------------------------
   XOR BASED PROBLEMS
------------------------------------------------- */

// Finds the element appearing once when others appear twice
int singleNumber(vector<int>& arr) {
    int x = 0;
    for (int v : arr) x ^= v;
    return x;
}

// Finds two numbers appearing once when others appear twice
pair<int,int> twoNonRepeating(vector<int>& arr) {
    int xr = 0;
    for (int v : arr) xr ^= v;

    int diffBit = xr & -xr; // rightmost differing bit
    int a = 0, b = 0;

    for (int v : arr) {
        if (v & diffBit) a ^= v;
        else b ^= v;
    }
    return {a, b};
}

// Computes XOR of numbers from 1 to n using pattern
int xorTillN(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

// Computes XOR of range [L, R]
int xorRange(int L, int R) {
    return xorTillN(R) ^ xorTillN(L - 1);
}

/* -------------------------------------------------
   MATH USING BIT MANIPULATION
------------------------------------------------- */

// Adds two integers without using + or -
int add(int a, int b) {
    while (b != 0) {
        int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

// Divides two integers without using /, *, %
int divide(int dividend, int divisor) {
    long long dvd = abs(dividend), dvs = abs(divisor);
    long long ans = 0;

    for (int i = 31; i >= 0; i--) {
        if ((dvd >> i) >= dvs) {
            dvd -= (dvs << i);
            ans += (1LL << i);
        }
    }
    if ((dividend < 0) ^ (divisor < 0)) ans = -ans;
    return (int)ans;
}

// Swaps two numbers using XOR (no extra space)
void swapUsingXor(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

/* -------------------------------------------------
   RANGE & DISTANCE PROBLEMS
------------------------------------------------- */

// Computes bitwise AND of all numbers in range [L, R]
int rangeBitwiseAnd(int L, int R) {
    int shift = 0;
    while (L < R) {
        L >>= 1;
        R >>= 1;
        shift++;
    }
    return L << shift;
}

// Computes Hamming distance between two numbers
int hammingDistance(int x, int y) {
    return countSetBits(x ^ y);
}

/* -------------------------------------------------
   SUBSETS & MASKING
------------------------------------------------- */

// Generates all subsets using bitmasking
vector<vector<int>> generateSubsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;

    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                subset.push_back(nums[i]);
        }
        res.push_back(subset);
    }
    return res;
}

/* -------------------------------------------------
   BIT REVERSAL & GRAY CODE
------------------------------------------------- */

// Reverses bits of a 32-bit unsigned integer
uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
        res <<= 1;
        res |= (n & 1);
        n >>= 1;
    }
    return res;
}

// Generates n-bit Gray code sequence
vector<int> grayCode(int n) {
    vector<int> res;
    for (int i = 0; i < (1 << n); i++)
        res.push_back(i ^ (i >> 1));
    return res;
}

/* -------------------------------------------------
   MISSING NUMBER
------------------------------------------------- */

// Finds missing number from range [0, n] using XOR
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int xr = 0;
    for (int i = 0; i <= n; i++) xr ^= i;
    for (int v : nums) xr ^= v;
    return xr;
}
