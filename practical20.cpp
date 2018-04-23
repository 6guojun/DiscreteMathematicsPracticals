#include<iostream>

using namespace std;

int main()
{
    int m,i;
    cout<<"Enter m of m-ary tree: ";
    cin>>m;
    cout<<"enter i i.e, number of internal vertices: ";
    cin>>i;
    cout<<"total number of leaves are: "<<(m-1)*i+1<<endl;
    return 0;
}