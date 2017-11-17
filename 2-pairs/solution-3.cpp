#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int N, K; cin >> N >> K;
    vector<int> v(N);
    copy_n(istream_iterator<int>(cin), N, begin(v));
    sort(begin(v), end(v));
    cout << count_if(begin(v), end(v), [&](int i){
        return binary_search(begin(v), end(v), i-K);
    });
}

// another approach, using a hash set:
#include <unordered_set>

int main() 
{
    int N, K; cin >> N >> K;
    unordered_set<int> v;
    copy_n(istream_iterator<int>(cin), N, inserter(v, end(v)));
    cout << count_if(begin(v), end(v), [&](int i){
       return v.count(i-K) > 0;  // > 0 only for clarity
    });
}
