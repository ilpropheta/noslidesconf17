#include <bits/stdc++.h>

using namespace std;

int simpleArraySum(int n, vector <int> ar) 
{
    return accumulate(begin(ar), end(ar), 0);
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    copy_n(istream_iterator<int>(cin), n, begin(ar));
    int result = simpleArraySum(n, ar);
    cout << result << endl;
    return 0;
}