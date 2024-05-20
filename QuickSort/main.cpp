//QuickSort class
#include <iostream>
#include <vector>
using namespace std;

template <typename T> class QuickSort{
    private:
        vector<T> MyVector;
    
    public:
        QuickSort(vector<T> _MyVector):MyVector(_MyVector){}//Constructor 
        ~QuickSort(){}//Destructor 
    
    //---Methods---
    void Display();
    int QuickS(int low , int high); 
    void SetQuickSort(int low, int high);
};

//                  |return|Class
template <typename T> void QuickSort <T> ::Display(){
    int SizeV=MyVector.size();
    cout<<"\nDisplaying vector: ";
    for(auto P:MyVector){
        cout<<P<<" ";
    }
    cout<<endl;
}
//------------------------------------------------------------------------------
template <typename T> int QuickSort <T>::QuickS(int low, int high){
    int i=low-1;
    int pivot=high;
    
    for(int j=low;j<high;j++){
        if(MyVector[j]<MyVector[pivot])
            swap(MyVector[++i], MyVector[j]);
    }
    swap(MyVector[++i], MyVector[pivot]);
    return i;
}
//------------------------------------------------------------------------------

template <typename T> void QuickSort <T>::SetQuickSort(int low, int high){
    if(low < high){
        int LR=QuickS(low,high);//Left and right side
        SetQuickSort(0,LR-1);//Left
        SetQuickSort(LR+1,high);//Right
    }
}


int main(){
    
    vector<int> A={2,5,9,4};
    QuickSort<int> QS1(A);

    QS1.Display();
    QS1.SetQuickSort(0,A.size()-1);
    QS1.Display();
    
    //-----------------------------
    
    vector<char> B={'h','a','f','b'};
    QuickSort<char> QS2(B);

    QS2.Display();
    QS2.SetQuickSort(0,B.size()-1);
    QS2.Display();
    
    return 0;
}



