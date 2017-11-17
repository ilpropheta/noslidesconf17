#include <numeric>
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int n, i; cin >> n;
    array<int, 100> freq{};
    while (cin >> i)
        freq[i]++;
    
    cout << inner_product(next(begin(freq)), end(freq),
                          begin(freq), 0,
                          [](int l, int r){ return max(l, r); }, 
			  plus<int>{});
}
