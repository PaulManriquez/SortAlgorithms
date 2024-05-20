//Bubble Sort template
//Programmer Paul Manriquez December 2023

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T> void BubbleSort(vector<T> &MyVector){//-------------------
    int SizeVec=MyVector.size();
    
    for(int i=0; i< SizeVec-1;i++){
        for(int j=0;j<(SizeVec-1-i);j++){
            if(MyVector[j]>MyVector[j+1]){
                swap(MyVector[j],MyVector[j+1]);
            }
        }
    }
}//-----------------------------------------------------------------------------

template <typename T> void Display(vector<T> &MyVector){//------Display function
    int SizeVec=MyVector.size();
    cout<<"\nDisplaying vector: ";
    for(auto P:MyVector){
        cout<<P<<" ";
    }
    cout<<"\n";
}//-----------------------------------------------------------------------------

int main(){
    
    //Int 
    vector<int> A={64,25,12,22,11};
    Display(A);
    BubbleSort(A);
    Display(A);
    
    //Char
    vector<char> B={'b','c','r','o','a'};
    Display(B);
    BubbleSort(B);
    Display(B);
    
    //String
    vector<string> C={"hiiiii","hiiii","hiii","hii","hi"};
    Display(C);
    BubbleSort(C);
    Display(C);
    return 0;
}



