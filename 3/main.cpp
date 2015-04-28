#include <iostream>
#include "lab.h"
#include <stack>
using namespace std;
int main()
{
    cout << "Start LAB3.1: " << endl;
    TwoStacksFixed<int> StackA(6,3);
    if(StackA.isEmptyStack1())
    {
        cout << "Stack1 is empty." << endl;
    }
    if(StackA.isEmptyStack2())
    {
        cout << "Stack2 is empty." << endl;
    }
    StackA.pushStack1(10);
    if(StackA.isEmptyStack2())
    {
        cout << "Stack2 is still empty." << endl;
    }
    StackA.pushStack1(11);
    StackA.pushStack1(12);
    StackA.pushStack1(13);
    if(StackA.isFullStack1())
    {
        cout << "Stack1 is full." << endl;
    } 
    if(!StackA.isFullStack2())
    {
        cout << "Stack2 is not full." << endl;
    }  
    
    StackA.pushStack2(15);
    StackA.pushStack2(16);
    StackA.pushStack2(17);
    StackA.pushStack2(18); 
    if(StackA.isFullStack2())
    {
        cout << "Stack2 is full." << endl;
    }  
    if(StackA.isEmptyStack1())
    {
        cout << "Stack1 is empty." << endl;
    }
    if(StackA.isEmptyStack2())
    {
        cout << "Stack2 is empty." << endl;
    }
    StackA.popStack1();
    if(StackA.isFullStack1())
    {
        cout << "Stack1 is full." << endl;
    } 
    StackA.popStack1();
    StackA.popStack1();
    StackA.popStack1();
    StackA.popStack2();
    StackA.popStack2();
    StackA.popStack2();
    StackA.popStack2();
    StackA.popStack1();
    if(StackA.isEmptyStack1())
    {
        cout << "Stack1 is empty." << endl;
    }
    if(StackA.isEmptyStack2())
    {
        cout << "Stack2 is empty." << endl;
    }
    cout << "End LAB3.1" << endl << endl;
    
    cout << "Start LAB3.2: " << endl;
    TwoStacksOptimal<int> StackB(4);
    if(StackB.isEmptyStack1())
        cout << "Stack1 is Empty." << endl;
    if(StackB.isEmptyStack2())
        cout << "Stack2 is Empty." << endl;
    StackB.pushFlexStack1(1);
    if(!StackB.isEmptyStack1())
        cout << "Stack1 is NO LONGER Empty." << endl;
    StackB.pushFlexStack2(4);
    if(!StackB.isEmptyStack1())
        cout << "Stack2 is NO LONGER Empty." << endl;
    StackB.pushFlexStack1(2);
    StackB.pushFlexStack1(3);
    StackB.pushFlexStack2(5);
    if(StackB.isFullStack1())
        cout << "Stack1 is FULL" << endl;
    if(StackB.isFullStack2())
        cout << "Stack2 is FULL" << endl;
    StackB.popFlexStack1();
    if(!StackB.isFullStack1())
        cout << "Stack1 is not FULL" << endl;
    if(!StackB.isFullStack2())
        cout << "Stack2 is NOT FULL" << endl;
    StackB.popFlexStack2();
    if(StackB.isEmptyStack2())
        cout << "Stack2 is Empty." << endl;
    StackB.popFlexStack1();
    StackB.popFlexStack1();
    StackB.popFlexStack1();
    StackB.popFlexStack2();
    if(StackB.isEmptyStack1())
        cout << "Stack1 is Empty." << endl;
    cout << "End LAB3.2" << endl << endl;
    
    cout << "Start Tower of Hanoi Test w/ 3: " << endl;
    stack<int> Stack1;
    stack<int> Stack2;
    stack<int> Stack3;
    showTowerStates(3, Stack1, Stack2, Stack3);
    cout << endl;
    return 0;
}