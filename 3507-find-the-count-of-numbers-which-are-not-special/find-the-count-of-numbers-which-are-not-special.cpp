
template<const int n>
class Sieve {
public:
    static constexpr int binarySearchSqrt() {
        size_t l=0,r=n;
        size_t ans=0;
        while(l<=r){
            size_t mid=l+(r-l)/2;
            if(mid*mid<=n){
                ans=mid;
                l=mid+1;
            }else
                r=mid-1;
        }
        return ans;
    }
    static constexpr size_t v=binarySearchSqrt();
    static const int lim= v>=(int)1e5? 1e5:v;
    bitset<lim> bs;  
    using ll = long long;
    vector<int> primes;

    Sieve(){
        build();
    }

    void build(){
        bs.set();
        bs[0] = bs[1] = 0;
        bs[2] = 1;
        for (ll i = 4; i < lim; i += 2)
            bs[i] = 0;
        primes.push_back(2);
        for (int i = 3; i < lim; i += 2) {
            if (bs[i]) {
                primes.push_back(i);
                for (ll j = i * i; j < lim; j += i)
                    bs[j] = 0;
            }
        }
    }

    vector<int> getPrimes() {
        return vector<int> (primes.begin(),primes.end());
    };

     int isPrime(ll v) {
        if (v < 2) return 0;
        if (v < lim) return (int)bs[v];
        // For large numbers, check divisibility by known primes
        for (ll p : primes) {
            if (p * p > v) break;
            if (v % p == 0) return 0;
        }
        return 1;
    }

     unordered_map<ll, int> primeDivisors(ll v) {
        unordered_map<ll, int> mp;
        for (ll p : primes) {
            if (p * p > v) break;
            int c = 0;
            while (v % p == 0) {
                c++;
                v /= p;
            }
            if (c)
                mp[p] = c;
        }
        if (v > 1) mp[v] = 1;  // Remaining value is a prime factor
        return mp;
    }

    long long countDivisors(int v) {
        if (v < 0) v = -v;
        auto mp = primeDivisors(v);
        long long ans = 1;
        for (auto& [k, v] : mp) {
            ans *= (v + 1);
        }
        return ans;
    }
};

class Solution {
public:
    Sieve<(int)1e9> s;
    vector<int> primes;
    Solution(){
        primes=s.getPrimes();
    }
    int nonSpecialCount(int l, int r) {
        int cnt=0;
        int ll=sqrt(l);
        auto p=lower_bound(primes.begin(),primes.end(),ll)-primes.begin();
        for(;p<primes.size() ;p++){
            if(primes[p]*primes[p]>r) break;
            if(primes[p]*primes[p]>=l)
                cnt++;
        }
        return r-l+1-cnt;
    }
};