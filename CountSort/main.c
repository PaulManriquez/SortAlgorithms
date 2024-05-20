//Count Sort
//Programmer Paul Manriquez november 2023

#include <stdio.h>
#include <stdlib.h>

void DisplayArray(int *A,int SizeA){//---------------------------------Display Array
    for(int i=0;i<SizeA;i++){
        printf("%d ",A[i]);
    }
}//-----------------------------------------------------------------------------

void CountSort(int *A,int SizeA){
    //Found the greatest number in the array
    int Max=A[0];
    for(int i=0;i<SizeA;i++){
        if(A[i]>Max){
            Max=A[i];
        }
    }//------------------------------------
    
    //Create a new array with the value of "Max" size
    int *Aux=(int *)calloc( (Max+1) , sizeof(int));
    if (Aux==NULL){perror("\nError creating espace for AuxArray"); exit(1);}
    
    //In the new array put the number of occurrences acording array A 
    for(int i=1;i<=SizeA;i++){
        Aux[ A[i-1] ]++;
    }//DisplayArray(Aux,Max+1);
    //----------------------------------------------------------------
    
    //Fill the A array with the occurrences the number of times repeated the index
    int i=1;
    int k=0;//Index of A
    do{
        if(Aux[i]>=1){
            for(int j=0;j<Aux[i];j++){
                A[k++]=i;
            }
        }
        i++;
    }while(i<=Max);
    //--------------------------------------------------------------------------
}

int main(){
    int A[]={6,3,9,10,15,6,8,12,3,6};
    int SizeA = sizeof(A) / sizeof(int);
    
    CountSort(A,SizeA);
        
    DisplayArray(A,SizeA);
    return 0;
}



