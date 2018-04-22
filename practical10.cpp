#include<iostream>
#include<cmath>

using namespace std;

void permuteSet(int* set,int start,int end);
void swap(int& a,int&b);
void printArray(int* array,int size);

int main()
{
    int size;
    cout<<"Enter size of set: ";
    cin>>size;
    int* set = new int[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter element number "<<i+1<<" of set: ";
        cin>>set[i];
    }
    permuteSet(set,0,size);
    delete[] set;
    return 0;
}

void permuteSet(int* set,int start,int size)
{
    if(start==size)
    {
        printArray(set,size);
    }
    else
    {
        for(int i=0;i<size;i++)
        {
            swap(set[i],set[size-1]);
            permuteSet(set,start+1,size);
            swap(set[i],set[size-1]);
        }
    }
}

void printArray(int* array,int size)
{
    cout<<"{ ";
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"}"<<endl;
}

void swap(int& a,int& b)
{
    int temp = a;
    a = b;
    b = temp;
}