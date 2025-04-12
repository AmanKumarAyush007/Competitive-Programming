#include <bits/stdc++.h>
using namespace std;

class Heap
{
    vector<int> heap;

public:
    void push(int value)
    {
    }

    int leftChild(int parent)
    {
    }
    int rightChild(int parent)
    {
    }
    int size()
    {
        return heap.size();
    }
    bool isEmpty()
    {
        return size == 0;
    }

    void print()
    {
        for (auto &i : heap)
            cout << i << " ";
        cout << endl;
    }
};