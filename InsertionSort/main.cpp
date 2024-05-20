//Insertion sort template class 
//Programmer Paul Manriquez December 2023
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> class InsertionSort{
    private:
        vector <T> &MyVector;
    public:
        InsertionSort(vector <T> &_MyVector):MyVector(_MyVector){}//Constructor
        ~InsertionSort(){}//Default destructor 
    
    //---Methods---
    void DisplayVector();
    void SetInsertionSort(vector <T> &_MyVector);
};

template <typename T> void InsertionSort <T>::SetInsertionSort(vector <T> &_MyVector){
    int key=0; int j=0;
    for(int idx=1;idx<_MyVector.size();idx++){
        key=_MyVector[idx];
        j=idx-1;
        while(j>=0 && key<_MyVector[j]){
            swap(_MyVector[j+1],_MyVector[j]);
            j--;
        }
        _MyVector[j+1]=key;
    }
}

template <typename T> void InsertionSort <T>::DisplayVector(){
    cout<<"Displaying Vector: ";
    for(auto P:MyVector){
        cout<<P<<" ";
    }
    cout<<endl;
}

int main(){
    
    vector <int> A={2,4,1,9,5};
    InsertionSort <int> IS1(A);
    
    IS1.SetInsertionSort(A);
    IS1.DisplayVector();
    
    cout<<endl;
    for(auto P:A){
        cout<<P<<" ";    
    }
    
    return 0;
}

