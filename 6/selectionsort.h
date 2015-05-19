// Jonathan Tan
// 861108230
// 5/19
// Different print function for pairs and non-pairs.
// Nested loops to find smallest value, swap it to the front and then move on with list size -1 because front is sorted
#ifndef selectionsort_H
#define selectionsort_H

#include <iostream>
#include <utility>
#include <list>
#include <vector>

using namespace std;

template<typename a, typename b>
void print(const vector <pair<a,b>> &l)
{
    for(auto i = l.begin(); i != l.end(); ++i)
    {
        cout << "(" << i->first << ", " << i->second << ") ";
    }
    cout << endl;
}

template<typename d, typename c>
void print(const list <pair<d,c>> &l)
{
    for(auto i = l.begin(); i != l.end(); ++i)
    {
        cout << "(" << i->first << ", " << i->second << ") ";
    }
    cout << endl;
}

template<typename T>
void print(const T &l)
{
    auto it = l.begin();
    while(it != l.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

template<typename L>
void selectionsort(L &l)
{
    cout << "Pre: ";
    print(l);
    typename L::iterator it = l.begin();
    int move = 0;
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        auto place_holder = it;
        for(typename L::iterator it2 = it; it2 != l.end(); ++it2)
        {
            if(*it2 < *place_holder)
            {
                place_holder = it2;
            }
            // if(*it2 < *it)
            // {
            //     swap(*it, *it2);
            //     move += 3;
            // }
        }
        if(place_holder != it)
        {
            swap(*it, *place_holder);
            move+=3;
        }
    }
    cout << "Post: ";
    print(l);
    cout << "0 copies and " << move << " moves.\n";
}

#endif