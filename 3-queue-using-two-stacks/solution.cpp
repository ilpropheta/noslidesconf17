#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class queue_from_stack
{
public:
  void push(int i)
  {
    in.push(i);
  }
  
  int front()
  {
    if (out.empty())
    {
      while (!in.empty())
      {
        out.push(in.top());
        in.pop();
      }
    }
    return out.top();
  }
  
  void pop()
  {
    front();
    out.pop();
  }
  
private:
  std::stack<int> in;
  std::stack<int> out;
};

int main() 
{
    int q; cin >> q;
    int op, arg;
    queue_from_stack queue;
    while (q--)
    {
        cin >> op;
        switch(op)
        {
        case 1:
            cin >> arg;
            queue.push(arg);
            break;
        case 2:
            queue.pop();
            break;
        case 3:
            cout << queue.front() << "\n";
            break;
        }    
    }    
}