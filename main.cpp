#include <iostream>
#include <windows.h>
using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;
    clock_t start;
    double AvaableC[15]={0.5,0.6,0.7,0.8,0.9,0.95,0.99,1.0,1.01,1.1,1.5,2,5,10,50};
    MEMORYSTATUS memstatus;
    std::cout<< memstatus.dwAvailVirtual<<endl;
    int AvailableMem=memstatus.dwAvailPhys;
    int availCsize=15;
    for(int i=0;i< availCsize;i++){
        start= clock();
        int CMultipliedByM=abs((int)(AvaableC[i] * (AvailableMem)));
        GlobalMemoryStatus(&memstatus);
        cout << "Available Physical Memory: " <<memstatus.dwAvailPhys<< endl;
        cout << "Available Page File: " <<memstatus.dwAvailPageFile<< endl;
        cout << "Available Virtual Memory" <<memstatus.dwAvailVirtual << endl;
         int *randomIntsArray = new int[CMultipliedByM/sizeof(int)];
        for (int j=0; j< CMultipliedByM/sizeof(int);j++){
                randomIntsArray[i] = i;
        }
        delete [] randomIntsArray;
        cout << "Time elapsed: " << ((double)(clock() - start) / (double)CLOCKS_PER_SEC) << " seconds " << endl;
        cout << "===============================================================" << endl;
    }


    return 0;
}
