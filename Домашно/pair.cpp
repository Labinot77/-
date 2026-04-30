#include <iostream>
#include <utility>

using namespace std;

int main() {
   pair<int, string> p;

   p.first = 10;
   p.second = "String";

   cout << p.first << " " << p.second << endl;
   
    pair<int, int> p2 = make_pair(5, 20);
    cout << p2.first + p2.second << endl;
    
    return 0;
}