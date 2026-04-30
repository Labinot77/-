
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;

    st.push(5);
    st.push(10);
    st.push(15);

    cout << "Top: " << st.top() << endl;

    return 0;
}

void find_n(stack<int>, int n) {
   
}