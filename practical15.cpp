#include<iostream>
#include<cmath>

using namespace std;

void getPolynomial(int* polynomialCoefficients,int degree);
int getValue(int* polynomialCoefficients,int degree,int n);

int main()
{
    int degree,n;
    cout<<"Enter degree of polynomial: ";
    cin>>degree;
    int* polynomialCoefficients = new int[degree+1];
    getPolynomial(polynomialCoefficients,degree);
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Value of polynomial at n = "<<n<<" is: "<<getValue(polynomialCoefficients,degree,n)<<endl;
    return 0;
}

void getPolynomial(int* polynomialCoefficients,int degree)
{
    for(int i = degree; i >= 0; i--)
    {
        cout<<"Enter coefficient of x^"<<i<<": ";
        cin>>polynomialCoefficients[i];
    }
}

int getValue(int* polynomialCoefficients,int degree,int n)
{
    int sum = 0;
    for(int i = degree; i>=0; i--)
    {
        sum+= polynomialCoefficients[i]*pow(n,i);
    }
    return sum;
}