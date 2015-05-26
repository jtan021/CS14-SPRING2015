// Jonathan Tan
// 861108230
// 5/26
// Use high resolution clock to track time before and after insertion/find and find difference to find total time taken to insert/find in tree/hash table
// 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <time.h>
#include <unordered_set>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void randomize(vector<string>& V)
{
    for (unsigned int i = 0; i < V.size(); i++)
    {
        swap(V[rand()%V.size()], V[rand()%V.size()]);
    }
}

int main()
{
    srand(time(NULL));
    ifstream input;
    ofstream output;
    input.open("words.txt");
    output.open("data.txt");
    
    string words;
    vector<string> word_bank;
    
    if(input.is_open())
    {
        while(input >> words)
        {
            word_bank.push_back(words);
        }
        input.close();
    }
    else
    {
        cout << "Error: Unable to open file." << endl;
    }
    
    int n;
    cout << "Input value for N: ";
    cin >> n;
    cout << endl;

    set<string>tree;
    unordered_set<string>hashTable;
    chrono::duration<double> time_span;
    bool endRun = false;
    
    while(n <= 50000 && !endRun)
    {
        // cout << "Current n = " << n << endl;
        output << n << " ";
        
        //Tree insertion
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        for(int i = 0; i < n; ++i)
        {
            tree.insert(word_bank[i]);
        }
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t2 - t1);
		output << time_span.count() << " ";    
		
		//Hash insertion
        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        for(int i = 0; i < n; ++i)
        {
            hashTable.insert(word_bank[i]);
        }
        high_resolution_clock::time_point t4 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t4 - t3);
		output << time_span.count() << " ";
		
		//Tree find
        high_resolution_clock::time_point t5 = high_resolution_clock::now();
        for(int i = 0; i < n; ++i)
        {
            tree.find(word_bank[i]);
        }
        high_resolution_clock::time_point t6 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t6 - t5);
		output << time_span.count() << " ";
		
		//Hash table find
        high_resolution_clock::time_point t7 = high_resolution_clock::now();
        for(int i = 0; i < n; ++i)
        {
            hashTable.find(word_bank[i]);
        }
        high_resolution_clock::time_point t8 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t8 - t7);
		output << time_span.count() << endl;
		
		if(n <= 50000)
		{
		    n+=5000;
		}
		if(n > 50000)
		{
		    endRun = true;
		}

        randomize(word_bank);   
    }
    
    // //Check if words were stored into vector
    // for(int i = 0; i < 15; i++)
    // {
    //     cout << word_bank[i] << " ";
    // }
    // cout << endl;
    // cout << word_bank[word_bank.size()-1];
    
    return 0;
}
