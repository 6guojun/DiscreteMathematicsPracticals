#include<iostream>

using namespace std;

int fibonacci(int n);

int main()
{
    int elementNumber;
    cout<<"Enter element number of fibonacci sequence: ";
    cin>>elementNumber;
    cout<<"Element at "<<elementNumber<<" in fibonacci sequence is: "<<fibonacci(elementNumber)<<endl;
    return 0;
}

int fibonacci(int n)
{
    if(n<=1)
        return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}