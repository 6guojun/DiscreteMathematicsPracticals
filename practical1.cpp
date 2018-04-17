#include<iostream>
#include<cmath>

using namespace std;

class SET{
    int size;
    int* elements;
public:
    SET(int size);
    ~SET();
    int getCardinality();
    bool isMember(int element);
    void powerSet();
};

int main()
{
    cout<<"Please enter the size of set you want to create: ";
    int size;
    cin>>size;
    SET A(size);
    cout<<"cardinality of set A is: "<<A.getCardinality()<<endl;
    cout<<"Is 2 present in set ?\nAns: "<<boolalpha<<A.isMember(2)<<endl;
    cout<<"Power set of A"<<endl;
    A.powerSet();
    return 0;
}

SET::SET(int size)
{
    this->size = size;
    elements = new int[size];
    cout<<"Enter elements in SET"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter elements number "<<i+1<<" of SET : ";
        cin>>elements[i];
    }
}

SET::~SET()
{
    delete[] elements;
}

int SET::getCardinality()
{
    return size;    
}

bool SET::isMember(int element)
{
    for(int i=0; i<size; i++){
        if(element == elements[i])
            return true;
    }
    return false;
}

void SET::powerSet()
{
    int sizeOfPowerSet = pow(2,size);
    for(int i=0; i<sizeOfPowerSet; i++){
        cout<<"{ ";
        for(int j=0; j<size; j++){
            if( i & (1<<j) ){
                cout<<elements[j]<<" ";
            }
        }
        cout<<"}"<<endl;
    }
}