//Selection Sort
//Programmer Paul Manriquez November 2023
#include <stdio.h>
#include <stdlib.h>

void Swap(int *P,int *Pp){//--------------------------Function to swap 2 numbers
    int Temp=*P;
    *P=*Pp;
    *Pp=Temp;
}//-----------------------------------------------------------------------------

void SelecionSort(int *A,int ArraySize){//-----------------SelecionSort function
    
    int P=0;//Current pointer to place the less number
    int Pp=0;//Current minor number in the iteration
    int Temp=0;//Variable to save in the swap process
    
    for(P=0;P<(ArraySize-1);P++){//Number of iterations (Passes)
        Pp=P;//Update posible less number pointer
        
        for(int i=P+1;i<=(ArraySize-1);i++){
            if(A[Pp]>A[i]){//If A[i] is a minor number
                Pp=i;//Current pointer to the minor number
            }
        }
        Swap(&A[P],&A[Pp]);
    }
}//-----------------------------------------------------------------------------

void Display(int *A,int ArraySize){//---------------Function to display an array
    //Display
    for(int i=0;i<(ArraySize);i++){
        printf("%d ",A[i]);
    }
}//-----------------------------------------------------------------------------

int main(){
    
    int A[]={8,6,3,2,5,4};
    int ArraySize=(sizeof(A)/sizeof(int));
    
    printf("Before SelecionSort:");
    Display(A,ArraySize);
    printf("\nAfter SelecionSort:");
    SelecionSort(A,ArraySize);
    Display(A,ArraySize);
    
    return 0;
}

