//Radix Sort - return a simple linked list sorted 
//Programmer Paul Manriquez November 2023
//I took in count this video to develop this program: https://www.youtube.com/watch?v=_Xz3XyKsCaM

#include <stdio.h>
#include <stdlib.h>

//----Node of the list---
typedef struct NodeList{
    int Data;
    struct NodeList *Next;
}NodeList;
NodeList *Root=NULL;
NodeList *Rear=NULL;
//-----------------------

NodeList *NewNode(int data){//---------------Create space for a new node element
    NodeList *T=(NodeList *)malloc(sizeof(NodeList));
    if(T==NULL){perror("Error Creating space for the node"); exit(1);}
    T->Data=data;
    T->Next=NULL;
    return T;
}//-----------------------------------------------------------------------------

void InsertInList(int data){//--------------------Insert in linked list function
    if(Root==NULL){//Means it is the first element
        Root=NewNode(data);
        Rear=Root;//Actual node
    }else{
        Rear->Next=NewNode(data);
        Rear=Rear->Next;
    }
}//-----------------------------------------------------------------------------

NodeList *GetDirNode(void){//-----------------------------------------GetDirNode
    NodeList *P = Root;
    if (Root != NULL) {
        Root = Root->Next;
        P->Next = NULL;
    }
    return P;
}//-----------------------------------------------------------------------------

void DisplayLinkedList(void){//------------------------------Display Linked list
    NodeList *P=Root;
    while(P){
        printf("%d ",P->Data);
        P=P->Next;
    }
}//-----------------------------------------------------------------------------

int GetMaxNumber(int *A,int SizeArrayA){//-------------Return the largest number
    int Max=A[0];
    for(int i=0;i<SizeArrayA;i++){
        if(Max<A[i]){
            Max=A[i];
        }
    }
    return Max;
}//-----------------------------------------------------------------------------

int GetTimesToRepeat(int Max){//-----------Return n times to repeat the proccess
        int k=1;
        int Times=0;
        do{
            k*=10;
            Times++;
        }while( (Max/k)!=0);
    return Times;
}//-----------------------------------------------------------------------------

void RadixSort(int Times,NodeList **Radix){
    int idx=0;
    NodeList *P=NULL;
    int k=1;
    for(int i=0;i<Times;i++){//Repeat this proccess n times and will be sorted
        k*=10;//This will change in the next iteration <<-----
        do{//5)Store in base units, tens , hundreds...
            P=GetDirNode();
            idx= ((P->Data)%k)/(k/10);//Get index
              //idx= (P->Data/k)%10;
            //How to link the upcomings node in the list?
            if(Radix[idx]!=NULL){//Means that at least exist one direction number
                NodeList *T=Radix[idx];
                while(T->Next!=NULL){//Place before you find the last node direction
                    T=T->Next;
                }
                T->Next=P;//Connect here
                //<<Make the las node point to NULL<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                T=T->Next;//Currently pointing to the last node
                T->Next=NULL;
            }else{
                Radix[idx]=P;
            }

        }while(Root!=NULL);

        Rear=NULL;

        int flag=1;
        //6)Link Again in the current order
        for(int i=0;i<10;i++){
            if(Radix[i]!=NULL && Root==NULL && flag){//Means that there is at least one node
                    Root=Radix[i];
                    Rear=Root;
                    //Means that exist more than one node linked
                        while(Rear->Next!=NULL){
                            Rear=Rear->Next;
                        }
                    flag=0;//If you set the first value you can enter to the else condition
                }else if(!flag){
                    Rear->Next=Radix[i];//Link the next node
                    //Find  and place to the current the last node
                    while(Rear->Next!=NULL){
                            Rear=Rear->Next;
                        }
                }
        }
        //-----Reset Radix----
        for(int i=0;i<10;i++){
            Radix[i]=NULL;
        }//-------------------

    }
}


int main(){
    //1)Create a linked list with numbers in an array
    //int A[]={35,620,56,3,16};
    int A[]={237,146,259,348,152,163,235,48,36,62};
    int SizeArrayA = sizeof(A)/sizeof(int);

    for(int i=0;i<SizeArrayA;i++){//----------------------Create the linked list
        InsertInList(A[i]);
    }//-------------------------------------------------------------------------

    //2)Find the largest number in the array
    int Max=GetMaxNumber(A,SizeArrayA);

    //3)Create an array to store the directions of the nodes in the linked list
    NodeList *Radix[10]={NULL}; //0 to 9 elements


    //It will be repeated the number of digits of the largest number
    //4)Get number of digits
    int Times=GetTimesToRepeat(Max);//Number of times to repeat

    //Radix Sort
    RadixSort(Times,Radix);

    //Display the sorted list
    DisplayLinkedList();
    return 0;
}

/* This was the prototype
 int idx=0;
    NodeList *P=NULL;
    int k=1;
    for(int i=0;i<Times;i++){
        k*=10;//This will change in the next iteration <<-----
        do{

            P=GetDirNode();
            idx= ((P->Data)%k)/(k/10);//Get index
            //How to link the upcomings node in the list?
            if(Radix[idx]!=NULL){//Means that at least exist one direction number
                NodeList *T=Radix[idx];
                while(T->Next!=NULL){//Place before you find the last node direction
                    T=T->Next;
                }
                T->Next=P;//Connect here
                //<<Make the las node point to NULL<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                T=T->Next;//Currently pointing to the last node
                T->Next=NULL;
            }else{
                Radix[idx]=P;
            }

        }while(Root!=NULL);
        Rear=NULL;

        //Link Again in the current order
        for(int i=0;i<10;i++){
            if(Radix[i]!=NULL && Root==NULL){//Means that there is at least one node
                    Root=Radix[i];
                    Rear=Root;
                    //Means that exist more than one node linked
                        while(Rear->Next!=NULL){
                            Rear=Rear->Next;
                        }

                }else{
                    Rear->Next=Radix[i];//Link the next node
                    //Find  and place to the current the last node
                    while(Rear->Next!=NULL){
                            Rear=Rear->Next;
                        }
                }
        }
        //-----Reset Radix----
        for(int i=0;i<10;i++){
            Radix[i]=NULL;
        }//-------------------
    }

*/



