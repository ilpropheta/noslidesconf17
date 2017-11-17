#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// KO for timeout on Test Cases: # 10, 11, 12, 13, 14
int main() 
{
    int N, K; cin >> N >> K;
    vector<int> v(N);
    copy_n(istream_iterator<int>(cin), N, begin(v));
    
    auto cnt = 0;
    for (auto i : v)
    {
        for (auto j : v)
        {
            if (i-j == K)
                cnt++;
        }
    }   
    cout << cnt;
}
