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
    
	auto count = 0;
	for (auto i=1; i<100; ++i)
	{
		count = max(count, freq[i]+freq[i-1]);
	}
	cout << count;	
}