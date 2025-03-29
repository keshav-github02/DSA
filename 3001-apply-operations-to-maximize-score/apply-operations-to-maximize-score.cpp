#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        const int MOD = 1e9 + 7;
        
        long long power(long long x, long long y) {
            long long res = 1;
            x = x % MOD;
            if (x == 0) return 0; 
            while (y > 0) {
                if (y & 1) { 
                    res = (res * x) % MOD;
                }
                y = y >> 1;
                x = (x * x) % MOD; 
            }
            return res;
        }
        vector<int> func(int limit) {
            vector<bool> isPrime(limit + 1, true);
            vector<int> primes;
    
            for (int i = 2; i * i <= limit; i++) {
                if (isPrime[i]) {
                    for (int j = i * i; j <= limit; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
    
            for (int i = 2; i <= limit; i++) {
                if (isPrime[i]) {
                    primes.push_back(i);
                }
            }
    
            return primes;
        }
    
        vector<int> ans(vector<int>& nums) {
            int n = nums.size();
            vector<int> primeScores(n, 0);
    
            int maxElement = *max_element(begin(nums), end(nums));
            vector<int> primes = func(maxElement); 
    
            for(int i = 0; i < n; i++) { 
                int num = nums[i];
    
                for(int prime : primes) {
                    if(prime*prime > num) {
                        break;
                    }
    
                    if(num % prime != 0) {
                        continue;
                    }
    
                    primeScores[i]++;
                    while(num%prime == 0) {
                        num /= prime;
                    }
                }
                if(num > 1) { 
                    primeScores[i]++;
                }
            }
    
            return primeScores;
        }
    
        vector<int> findNextGreater(vector<int>& primeScores) {
            int n = primeScores.size();
            vector<int> nextGreator(n, n);
            stack<int> st;
    
            for(int i = n-1; i >= 0; i--) {
                while(!st.empty() && primeScores[st.top()] <= primeScores[i]) {
                    st.pop();
                }
    
                nextGreator[i] = st.empty() ? n : st.top();
                st.push(i);
            }
    
            return nextGreator;
        }
    
        vector<int> findPrevGreater(vector<int>& primeScores) {
            int n = primeScores.size();
            vector<int> prevGreator(n, -1);
            stack<int> st;
    
            for(int i = 0; i < n; i++) {
                while(!st.empty() && primeScores[st.top()] < primeScores[i]) {
                    st.pop();
                }
    
                prevGreator[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
    
            return prevGreator;
        }
    
        int maximumScore(vector<int>& nums, int k) {
            vector<int> primeScores = ans(nums); 
            vector<int> nextGreater = findNextGreater(primeScores); 
            vector<int> prevGreater = findPrevGreater(primeScores); 
    
            int n = nums.size();
            vector<long long> subarrays(n, 0);
    
            for(int i = 0; i < n; i++) { //O(n)
                subarrays[i] = (long long)(nextGreater[i] - i) * (i - prevGreater[i]);
            }
    
            vector<pair<int, int>> sortedNums(n);
            for(int i = 0; i < n; i++) {
                sortedNums[i] = {nums[i], i};
            }
    
            sort(begin(sortedNums), end(sortedNums), greater<>()); 
    
            long long score = 1;
    
            int idx = 0;
            while(k > 0) { 
                auto [num, i] = sortedNums[idx];
    
                long long operations = min((long long)k, subarrays[i]);
    
                score = (score * power(num, operations)) % MOD;
    
                k  = (k - operations);
                idx++;
            }
    
            return score;
            
        }
    };