//Implementation of template class for MergeSort
//Programmer Paul Manriquez December 2023 
//Video explained https://www.youtube.com/watch?v=kOgzXagXpTg
#include <iostream>
#include <vector>
using namespace std;

template <typename T> class MergeSort{
    private:
        vector <T> MyVector;
    void Merge(int L,int Mid, int H);//private method 
    public:
        MergeSort(vector <T> _MyVector):MyVector(_MyVector){}//Constructor
        ~MergeSort(){}//Destructor
    //Methods
    void DisplayVector();
    void SetMergeSort(int L,int H);
};
//------------------------------------------------------------------------------

template <typename T> void MergeSort <T>::DisplayVector(){//------Display Vector
    int Sizev=MyVector.size();
    cout<<"\nDisplaying vector:";
    for(auto P:MyVector){
        cout<<" "<<P;
    }
    cout<<endl;
}//-----------------------------------------------------------------------------

template <typename T> void MergeSort <T>::SetMergeSort(int L,int H){//----------
    if(L<H){
        int Mid = (L+H)/2;//Dive the list - get index
        SetMergeSort(L,Mid);   //Left part
        SetMergeSort(Mid+1,H);//Right part
        Merge(L,Mid,H);  //Merge
    }
}//-----------------------------------------------------------------------------

template <typename T> void MergeSort <T>::Merge(int L,int Mid,int H){
    //---Variables---
    int i=L;       //Low - start left index
    int j=Mid+1;  //Mid+1- start the right index
    int k=0;     //index to temp    
    int Temp[H];//Temporal array copy ordered 
    //---------------
    
    //1) Arrange the elements in the temporal array
    while(i<=Mid && j<=H){//While one of the index don't reach to the limit 
        if(MyVector[i]<MyVector[j]){
            Temp[k++]=MyVector[i++];
        }else{
            Temp[k++]=MyVector[j++];
        }
    }//-----------------------------------------

    //2) If i or j dont reached to the limit - means that are missing to copy elements
    for(;i<=Mid;){
        Temp[k++]=MyVector[i++];
    }
    
    for(;j<=H;){
        Temp[k++]=MyVector[j++];
    }
    
    //3) Copy the arranged array to the original vector-in this point, the elements are already ordered 
    for(int ii=L;ii<=H;ii++){
        MyVector[ii]=Temp[ii - L];//Relatively index 
    }
}

int main(){
    
    vector   <int> A={2,5,9,4};
    MergeSort<int> MS1(A);

    MS1.DisplayVector();
    MS1.SetMergeSort(0,A.size()-1);
    MS1.DisplayVector();
    
    //
    vector   <char> B={'v','c','a','b','z'};
    MergeSort<char> MS2(B);

    MS2.DisplayVector();
    MS2.SetMergeSort(0,B.size()-1);
    MS2.DisplayVector();
    
    return 0;
}


