// Problem : Implement a (ordered)set datastructure that has add(), remove() & print() functions
// Constrainst: 0 <= set[i] <= 60
#include <bits/stdc++.h>

using namespace std;

class MySet
{
private:
    // This `BitSet` will be a 64-bit int
    // hence - all values from 0 to 60 can be easily stored in it by only setting the bits of this
    long long BitSet;

public:
    MySet()
    {
        this->BitSet = 0;
    }

    void add(int n)
    {
        this->BitSet = (this->BitSet | ((long long)(1) << n));
    }

    void remove(int n)
    {
        this->BitSet = (this->BitSet & ~((long long)(1) << n));
    }

    void print()
    {
        for (int i = 0; i < 64; i++)
        {
            if ((this->BitSet & ((long long)(1) << i)) != 0)
                cout << i << ' ';
        }
        cout << endl;
    }
};

int main()
{
    MySet S;
    S.add(3);    // 3
    S.add(23);   // 3, 23
    S.add(4);    // 3, 4, 23
    S.add(23);   // 3, 4, 23
    S.add(3);    // 3, 4, 23
    S.remove(3); // 4, 23
    S.print();
    return 0;
}