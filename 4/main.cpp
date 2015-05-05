#include "lab4.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) 
{
    if(argc != 2) 
    {
        cout << "User: lab3 <Value>\n";
        exit(-1);
    }
    int i = (int)(argv[1][0] - '0');
    print_preOrder(i);
    print_postOrder(i);
    print_inOrder(i);
    return 0;
}
