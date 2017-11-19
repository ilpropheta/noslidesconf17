# Bonus

Some examples I did not show at the conference.

## Alternating Characters

[Challenge on HackerRank](https://www.hackerrank.com/challenges/alternating-characters/problem)

Basically, we have to count the number of adjacent equal characters in a string:

    auto cnt = 0;
    for (auto i=1; i<s.size(); ++i)
    {
       if (s[i]==s[i-1])
          cnt++;
    }
    cout << cnt << "\n";

The code above could be rewritten in terms of the **zip | map | fold** pattern, that in C++ is provided by `inner_product`:

    cout << inner_product(begin(s), end(s)-1, next(begin(s)), 0, plus<int>(), equal_to<char>()) << "\n";

Another solution - mutating the string - consists in using `std::erase`:

cout << distance(unique(begin(s), end(s)), end(s)) << endl;

## Roman Numbers

In this problem we have to turn an integral number (between 1 and 3999) into a Roman Number.

The classical approach consists in rolling an *if-cascade*:

    string to_roman_ifcascade(int n)
    {
        string roman;
        while (n)
        {
            if (n >= 1000) { roman += "M"; n -= 1000; }
            else if (n >= 900) { roman += "CM"; n -= 900; }
            else if (n >= 500) { roman += "D"; n -= 500; }
            else if (n >= 400) { roman += "CD"; n -= 400; }
            else if (n >= 100) { roman += "C"; n -= 100; }
            else if (n >= 90) { roman += "XC"; n -= 90; }
            else if (n >= 50) { roman += "L"; n -= 50; }
            else if (n >= 40) { roman += "XL"; n -= 40; }
            else if (n >= 10) { roman += "X"; n -= 10; }
            else if (n >= 9) { roman += "IX"; n -= 9; }
            else if (n >= 5) { roman += "V"; n -= 5; }
            else if (n >= 4) { roman += "IV"; n -= 4; }
            else if (n >= 1) { roman += "I"; n -= 1; }
        }
        return roman;
    }

There are many possible better solutions for this problem. I like to think the code above as kind of an "interpolation": everytime we have to find the "best" position for n into the possible breakpoint values. For instance, suppose we have to covert 17: we find that n is greater than 10 but lesser than 40. Hence the algorithm falls into `else if (n >= 10)`. Then `n` becomes 7, falling into `else if (n >= 5)` and so on. That's very close to an interpolation.

We can exploit this fact by using a **binary search**. For instance, we can use a map:

    string to_roman(int n)
    {
        // defines the correspondence between a decimal number and the Roman symbol
        static const map<int, string> m{
          { 1000, "M" }, { 900, "CM" }, { 500, "D" }, { 400, "CD" }, { 100, "C" },
          { 90, "XC" }, { 50, "L" }, { 40, "XL" }, { 10, "X" }, { 9, "IX" },
          { 5, "V" }, { 4, "IV" }, { 1, "I" },
        };
    
        string roman;
        while (n)
        {
           auto lb = m.lower_bound(n); // find the symbol
           if (lb == end(m) || lb->first != n) // beyond the limit or not exact match?
              lb = prev(lb);
           roman += lb->second;
           n -= lb->first;
        }
        return roman;
    }
	
## Mars Explorarion - in C#

[Challenge on HackerRank](https://www.hackerrank.com/challenges/mars-exploration/problem)

Solution by Simone Busoli. We can mix the power of `yeld` and `Zip` in `Linq`:

    class Solution {
        static IEnumerable<char> Sos() 
		{
           while(true) 
	       {
              yield return 'S';
              yield return 'O';
              yield return 'S';
           }
        }
    
        static void Main(String[] args) 
	    {
            WriteLine(ReadLine().Zip(Sos(), Tuple.Create).Count(t => t.Item1 != t.Item2));
        }
    }