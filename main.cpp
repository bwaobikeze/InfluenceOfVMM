#include <iostream>
#include <windows.h>
using namespace std;


int main() {
    clock_t start;
    double AvaableC[15]={0.5,0.6,0.7,0.8,0.9,0.95,0.99,1.0,1.01,1.1,1.5,2,5,10,50};
    MEMORYSTATUS memstatus;
    int AvailableMem=memstatus.dwAvailPhys;
    int availCsize=15;
    cout << "Physical Memory Before Computation: " <<memstatus.dwAvailPhys<< endl;
    cout << "Page File Before Computation: " <<memstatus.dwAvailPageFile<< endl;
    cout << "Virtual Memory Before Computation: " <<memstatus.dwAvailVirtual << endl;
    for(int i=0;i< availCsize;i++){
        start= clock();
        int CMultipliedByM=abs((int)(AvaableC[i] * (AvailableMem)));
        GlobalMemoryStatus(&memstatus);
        cout<< i<<endl;
        cout << "Physical Memory: " <<memstatus.dwAvailPhys<< endl;
        cout << "Page File: " <<memstatus.dwAvailPageFile<< endl;
        cout << "Virtual Memory " <<memstatus.dwAvailVirtual << endl;
         int *randomIntsArray = new int[CMultipliedByM/sizeof(int)];
        for (int j=0; j< CMultipliedByM/sizeof(int);j++){
                randomIntsArray[j] = j;
        }
        delete [] randomIntsArray;
        cout << "Time elapsed: " << ((double)(clock() - start) / (double)CLOCKS_PER_SEC) << " seconds " << endl;
        cout << "===============================================================" << endl;
    }


    return 0;
}
