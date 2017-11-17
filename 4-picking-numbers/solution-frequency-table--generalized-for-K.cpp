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
    
    int k=1;
    partial_sum(begin(freq), end(freq), begin(freq));
    cout << inner_product(next(begin(freq),k+1), end(freq), begin(freq), 0,
                          [](int l, int r){ return max(l, r); }, 
                          minus<>{}
            );
}