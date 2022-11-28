#include "HashTable.h"

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <random>

using namespace std;
typedef chrono::high_resolution_clock Clock;

double millisBetween(chrono::_V2::system_clock::time_point t1, chrono::_V2::system_clock::time_point t2){
    return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1000.0;
}

vector<int> createArray(int size){
    vector<int> array;
    int maxN = size * 2;
    int minN = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(minN, maxN);

    //cout << "Creating array of size " << size << endl;

    for (int i = 0; i < size; i++){

        int generated = distr(gen);
        array.push_back(generated);
    }

    return array;
}

int testTable(double maxSize){

    vector<int> testSizes = {500, 1000, 2000, 5000};
    
    vector<vector<int>> intsToAdd;
    
    for(int i = 0; i < testSizes.size(); i++){
        intsToAdd.push_back(createArray(testSizes.at(i)));
    }


    // Print Headers
    cout 
        << setw(15) << left << "Table Size"
        << setw(15) << left << "Process Time (ms)"
    << endl;

    for(int i = 0; i < testSizes.size(); i++){

        int currentSize = testSizes[i];

        HashTable<int, int> table(currentSize * maxSize);

        vector<int> ints = intsToAdd[i];

        auto t1 = Clock::now();

        for(int j = 0; j < ints.size(); j++){
            int k = ints[j];
            table.addItem(k, k);
        }

        auto t2 = Clock::now();

        cout
            << setw(15) << left << currentSize
            << setw(15) << fixed << setprecision(2) << millisBetween(t1, t2)
        << endl;



    }


}

int main(){

    // Test Tables
    cout << "100% SIZE TABLE" << endl;
    testTable(1.0);

    cout << endl << "150% SIZE TABLE" << endl;
    testTable(1.5);

    cout << endl << "200% SIZE TABLE" << endl;
    testTable(2.0);

    cout << endl << "500% SIZE TABLE" << endl;
    testTable(5.0);




}