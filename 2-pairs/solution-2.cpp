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
    
    auto cnt = 0;
    for (auto i : v)
    {
        if (binary_search(begin(v), end(v), i-K))
            cnt++;
    }
    cout << cnt;
}
