// Jonathan Tan
// 861108230
// 5/2
// ?
#ifndef lab4_H
#define lab4_H
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void treeRecursion(int m, int n, int k)
{
    cout << m << " " << n << endl;
    int left_child_sum = 2*m-n+m;
    int mid_child_sum = 2*m+n+m;
    int right_child_sum = m+2*n+n;
    if( (left_child_sum) < k)
    {
        // cout << 2*m-n << " " << m << endl;
        treeRecursion(2*m-n, m, k);
    }
    if( (mid_child_sum) < k)
    {
        // cout << 2*m+n << " " << m << endl;
        treeRecursion(2*m+n, m, k);
    }
    if( (right_child_sum) < k)
    {
        // cout << 2*n+m << " " << n << endl;
        treeRecursion(m+2*n, n, k);
    }
}

void treeRecursion2(int m, int n, int k)
{
    int left_child_sum = 2*m-n+m;
    int mid_child_sum = 2*m+n+m;
    int right_child_sum = m+2*n+n;
    if( (left_child_sum) < k)
    {
        // cout << 2*m-n << " " << m << endl;
        treeRecursion2(2*m-n, m, k);
    }
    if( (mid_child_sum) < k)
    {
        // cout << 2*m+n << " " << m << endl;
        treeRecursion2(2*m+n, m, k);
    }
    if( (right_child_sum) < k)
    {
        // cout << 2*n+m << " " << n << endl;
        treeRecursion2(m+2*n, n, k);
    }
    cout << m << " " << n << endl;
}

typedef pair<int,int> Entry;
void pushOn_priorityQueue(int m, int n, int k, priority_queue<pair<int,int>> &q)
{
    int left_child_sum = 2*m-n+m;
    int mid_child_sum = 2*m+n+m;
    int right_child_sum = m+2*n+n;
    if( (left_child_sum) < k)
    {
        // cout << 2*m-n << " " << m << endl;
        Entry temp(2*m-n, m);
        q.push(temp);
        pushOn_priorityQueue(2*m-n, m, k, q);
    }
    if( (mid_child_sum) < k)
    {
        // cout << 2*m+n << " " << m << endl;
        Entry temp(2*m+n, m);
        q.push(temp);
        pushOn_priorityQueue(2*m+n, m, k, q);
    }
    if( (right_child_sum) < k)
    {
        // cout << 2*n+m << " " << n << endl;
        Entry temp(m+2*n, n);
        q.push(temp);
        pushOn_priorityQueue(m+2*n, n, k, q);
    }
}

void print_preOrder(int k) {
    if(k < 4)
        return;
    cout << "pre-order" << endl;
    treeRecursion(2, 1, k);
    if(k > 4)
        treeRecursion(3, 1, k);
}

void print_postOrder(int k) {
    if(k < 4)
        return;
    cout << "pre-order" << endl;
    treeRecursion2(2, 1, k);
    if(k > 4)
        treeRecursion2(3, 1, k);
}

typedef pair<int,int> Entry;
void print_inOrder(int k) {
    if(k < 4)
        return;
    cout << "sorted" << endl;
    priority_queue<pair<int,int>> q;
    pushOn_priorityQueue(2, 1, k, q);
    if(k > 4)
    {
        pushOn_priorityQueue(3, 1, k, q);
    }
    Entry temp1(2, 1);
    Entry temp2(3, 1);
    q.push(temp1);
    if(k > 4) {
        q.push(temp2);
    }
    // cout << "BOOM" << endl;
    stack<pair<int,int>> q_fixed;
    while(!q.empty())
    {
        Entry temp3(q.top().first, q.top().second);
        q_fixed.push(temp3);
        // cout << "Q_FIXED: " << q_fixed.top().first << " " << q_fixed.top().second << endl;
        q.pop();
    }
    while(!q_fixed.empty())
    {
        cout << q_fixed.top().first << " " << q_fixed.top().second << endl;
        q_fixed.pop();
    }
}
// Finally, modify your program to print out all pairs whose sum is less than k in
// sorted order. Do NOT place the values into a list and then sort it. Use a
// priority queue and the property from part a that all nodes have sums less than
// their subtrees to print the list out without storing it all at once. Use
// std::priority_queue from header queue. Be careful: It implements a
// max-heap

#endif
