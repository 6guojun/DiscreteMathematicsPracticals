#include<iostream>

using namespace std;

int permutation(int n,int r);
int combination(int n,int r);

int main()
{
    cout<<"Permutation(5,2) = "<<permutation(5,2)<<endl;
    cout<<"Combination(5,2) = "<<combination(5,2)<<endl;
    return 0;
}

int permutation(int n,int r)
{
    if(r==1)
        return n;
    return n*permutation(n-1,r-1);
}

int combination(int n,int r)
{
    if(n==r||r==0)
        return 1;
    return (static_cast<float>(n) / (n - r)) * combination(n-1 ,r);
}