#include<iostream>

using namespace std;

int binarySearch(int* array,int element,int begin,int end);

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    cout<<"9 is at index: "<<binarySearch(array,9,0,10)<<endl;
}

int binarySearch(int* array,int element,int begin,int end)
{
    if(begin>end)
        return -1;
    int mid = (begin+end)/2;
    if(array[mid]==element)
        return mid;
    else if(array[mid]>element)
        return binarySearch(array,element,begin,mid-1);
    else
        return binarySearch(array,element,mid+1,end);
}