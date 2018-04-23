#include<iostream>

using namespace std;

void bruteForce(int num,int constant);
void calculatePermutation(int*,int,int,int);
void printArray(int*,int);
int sumArray(int*,int);

int main()
{
    int constant, num;
    cout<<"Enter number of digits: ";
    cin>>num;
    cout<<"Enter sum constant: ";
    cin>>constant;
    bruteForce(num,constant);
    return 0;
}

void bruteForce(int num,int constant)
{
    int* array = new int[num];
    calculatePermutation(array,0,num,constant);
    delete[] array;
}

void calculatePermutation(int* array,int start,int end,int constant)
{
    if(start==end)
    {
        if(sumArray(array,end)<=constant)
            printArray(array,end);
        return;
    }
    for(int i=0;i<=constant;i++)
    {
        array[start] = i;
        calculatePermutation(array,start+1,end,constant);
    }
}

void printArray(int* array,int size)
{
    cout<<"{ ";
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<"}"<<endl;
}

int sumArray(int* array,int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
        sum+=array[i];
    return sum;
}
