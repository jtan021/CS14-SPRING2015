#ifndef lab_h
#define lab_h
#include <iostream>
#include <stack>

using namespace std;

#define VNAME(x) #x
#define VDUMP(x) cout << #x << " " << x << endl

template <typename T>
class TwoStacksFixed
{
    private:
    int arr_size = 0;
    int stack_size = 0;
    int top1 = 0;
    int top2 = 0;
    T *arr;
    
    public:
    TwoStacksFixed(int size, int maxtop)
    {
        arr_size = size;
        stack_size = maxtop;
        arr = new T[size];
        top1 = -1;
        top2 = arr_size;
    }
    
    void pushStack1(T value)
    {
        if(top1 < stack_size-1)
        {
            top1++;
            arr[top1] = value;
        }
        else
        {
            cout << "Overflow Error: Stack1 is FULL." << endl;
        }
    }
    
    void pushStack2(T value)
    {
        if(top2 > stack_size)
        {
            top2--;
            arr[top2] = value;
        }
        else
        {
            cout << "Overflow Error: Stack2 is FULL." << endl;
        }
    }
    
    T popStack1()
    {
        if(top1 < 0)
        {
            cout << "Underflow Error: Stack1 is EMPTY." << endl;
            return arr[top1];
        }
        return arr[--top1];
    }
    
    T popStack2()
    {
        if(top2 >= arr_size)
        {
            cout << "Underflow Error: Stack2 is EMPTY." << endl;
            return arr[top2];
        }
        return arr[++top2];
    }
    
    bool isFullStack1()
    {
        if(top1 == stack_size-1)
            return true;
        else
            return false;
    }
    
    bool isFullStack2()
    {
        if(top2 == stack_size)
            return true;
        else
            return false;
    }
    
    bool isEmptyStack1()
    {
        if(top1 < 0)
            return true;
        else
            return false;
    }
    
    bool isEmptyStack2()
    {
        if(top2 >= arr_size)
            return true;
        else
            return false;
    }
};

template <typename T>
class TwoStacksOptimal
{
    private:
    int arr_size = 0;
    int top1 = 0;
    int top2 = 0;
    T *arr;
    
    public:
    TwoStacksOptimal(int size)
    {
        arr_size = size;
        arr = new T[size];
        top1 = -1;
        top2 = arr_size;
    }
    
    void pushFlexStack1(T value)
    {
        if(top1 < top2-1)
        {
            top1++;
            arr[top1] = value;
        }
        else
        {
            cout << "Overflow Error: Stack1 is FULL." << endl;
        }
    }
    
    void pushFlexStack2(T value)
    {
        if(top1 < top2-1)
        {
            top2--;
            arr[top2] = value;
        }
        else
        {
            cout << "Overflow Error: Stack2 is FULL." << endl;
        }
    }
    
    T popFlexStack1()
    {
        if(top1 < 0)
        {
            cout << "Underflow Error: Stack1 is EMPTY." << endl;
            return arr[top1];
        }
        return arr[--top1];
    }
    
    T popFlexStack2()
    {
        if(top2 >= arr_size)
        {
            cout << "Underflow Error: Stack2 is EMPTY." << endl;
            return arr[top2];
        }
        return arr[++top2];
    }
    
    bool isFullStack1()
    {
        if(top1 == top2-1)
            return true;
        else
            return false;
    }
    
    bool isFullStack2()
    {
        if(top2 == top1+1)
            return true;
        else
            return false;
    }
    
    bool isEmptyStack1()
    {
        if(top1 < 0)
            return true;
        else
            return false;
    }
    
    bool isEmptyStack2()
    {
        if(top2 >= arr_size)
            return true;
        else
            return false;
    }
};

template <typename T>
void showTowerStates2(int orig, int n, stack<T>& A, stack<T>& B, stack<T>& C, string arr[])
{
    string string0 = arr[0];
    string string1 = arr[1];
    string string2 = arr[2];
    if(n == 1)
    {
        cout << "Moved " << n << " from peg " << arr[0] << " to " << arr[2] << endl;
        return;
    }
    else
    {
        arr[1] = string2;
        arr[2] = string1;
        showTowerStates2(orig, n-1, A, C, B, arr);
        if(n == orig)
        {
            cout << "Moved " << n << " from peg A to C" << endl;
        }
        else 
        {
        cout << "Moved " << n << " from peg " << arr[0] << " to " << arr[1] << endl;
        }
        arr[0] = string1;
        arr[1] = string0;
        arr[2] = string2;
        showTowerStates2(orig, n-1, C, B, A, arr);
    }
}

template <typename T>
void showTowerStates(int n, stack<T>&A, stack<T> &B, stack<T>&C)
{
    string arr[] = {"A","B","C"};
    showTowerStates2(n, n, A, B, C, arr);
    return;
}

#endif