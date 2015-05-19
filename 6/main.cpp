// Jonathan Tan
// 861108230
// 5/19
// Different print function for pairs and non-pairs.
// Nested loops to find smallest value, swap it to the front and then move on with list size -1 because front is sorted

#include "selectionsort.h"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    cout << "Selection Sort: LIST -->\n";
    // cout << "Pre: ";
    list<int> L;
    L.push_back(9);
    L.push_back(8);
    L.push_back(1);
    L.push_back(5);
    L.push_back(4);
    L.push_back(2);
    // for(auto i = L.begin(); i != L.end(); ++i)
    // {
    //     cout << *i << " ";
    // }
    // cout << endl;
    selectionsort(L);
    // cout << "Post: ";
    // for(auto i = L.begin(); i != L.end(); ++i)
    // {
    //     cout << *i << " ";
    // }
    cout << endl << endl;
    
    cout << "Selection Sort: EMPTY LIST -->\n";
    // cout << "Pre: ";
    list<int> EL;
    selectionsort(EL);
    cout << endl << endl;
    
    cout << "Selection Sort: VECTOR -->\n";
    vector<int> V;
    V.push_back(10);
    V.push_back(-3);
    V.push_back(-8);
    V.push_back(1);
    V.push_back(1);
    V.push_back(0);
    V.push_back(10);
    V.push_back(5);
    V.push_back(5);
    V.push_back(0);
    V.push_back(10);
    // cout << "Pre: ";
    // for(auto i = V.begin(); i != V.end(); ++i)
    // {
    //     cout << *i << " ";
    // }
    // cout << endl;
    selectionsort(V);
    // cout << "Post: ";
    // for(auto i = V.begin(); i != V.end(); ++i)
    // {
    //     cout << *i << " ";
    // }
    cout << endl << endl;
    
    cout << "Selection Sort: VECTOR PAIR -->\n";
    vector<pair<int,int>> V2;
    V2.push_back(make_pair(1,2));
    V2.push_back(make_pair(3,-1));
    V2.push_back(make_pair(-1,3));
    V2.push_back(make_pair(0,0));
    V2.push_back(make_pair(2,3));
    V2.push_back(make_pair(1,2));
    V2.push_back(make_pair(1,-2));
    V2.push_back(make_pair(8,10));
    
    // (10,2) (-3,-1) (-8,0) (1,1) (1,1) (0,0) (10,2) (5,5) (5,-5) (0,0) (10,2
    // cout << "Pre: ";
    // for(auto i = V2.begin(); i != V2.end(); ++i)
    // {
    //     cout << "(" << i->first << ", " << i->second << ") ";
    // }
    // cout << endl;
    selectionsort(V2);
    // cout << "Post: ";
    // for(auto i = V2.begin(); i != V2.end(); ++i)
    // {
    //     cout << "(" << i->first << ", " << i->second << ") ";
    // }
    cout << endl << endl;
    
    cout << "Selection Sort: LIST PAIR -->\n";
    list<pair<int,int>> L2;
    L2.push_back(make_pair(10,2));
    L2.push_back(make_pair(-3,-1));
    L2.push_back(make_pair(-8,0));
    L2.push_back(make_pair(1,1));
    L2.push_back(make_pair(1,1));
    L2.push_back(make_pair(0,0));
    L2.push_back(make_pair(10,2));
    L2.push_back(make_pair(5,5));
    L2.push_back(make_pair(5,-5));
    L2.push_back(make_pair(0,0));
    L2.push_back(make_pair(10,2));
    selectionsort(L2);
    cout << endl << endl;
    
    // (-1,3) (0,0) (1,-2) (1,2) (1,2) (2,3) (3,-1) (8,10)
    cout << "Selection Sort: LIST PAIR 2 -->\n";
    list<pair<int,int>> L3;
    L3.push_back(make_pair(-1,3));
    L3.push_back(make_pair(0,0));
    L3.push_back(make_pair(1,-2));
    L3.push_back(make_pair(1,2));
    L3.push_back(make_pair(1,2));
    L3.push_back(make_pair(2,3));
    L3.push_back(make_pair(3,-1));
    L3.push_back(make_pair(8,10));
    selectionsort(L3);
    cout << endl << endl;
    
    
    return 0;
}