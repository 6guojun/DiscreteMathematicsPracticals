#include<iostream>

using namespace std;

class SET
{
    int size;
    int* elements;
public:
    SET(int size);
    SET(SET& set);
    ~SET();
    bool subset(SET set);
    bool isMember(int element);
    void Union(SET B);
    void intersect(SET B);
    void complement(SET U);
    void difference(SET B);
    void symmetricDifference(SET B);
    void cartesianProduct(SET B);
};


int main()
{
    int sizeA,sizeB,sizeU;
    cout<<"Enter size of set A: ";
    cin>>sizeA;
    cout<<"Enter size of set B: ";
    cin>>sizeB;
    cout<<"Please input set A"<<endl;
    SET A(sizeA);
    cout<<"Please input set B"<<endl;
    SET B(sizeB);
    cout<<"Is B a subset of A ?"<<endl;
    cout<<"Ans: "<<boolalpha<<A.subset(B)<<endl;
    cout<<"UNION of A and B"<<endl;
    A.Union(B);
    cout<<"Intersection of A and B"<<endl;
    A.intersect(B);
    cout<<"A - B"<<endl;
    A.difference(B);
    cout<<"A symmetric difference B"<<endl;
    A.symmetricDifference(B);
    cout<<"A X B"<<endl;
    A.cartesianProduct(B);
    return 0;
}

SET::SET(int size)
{
    this->size = size;
    elements = new int[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter elements number "<<i+1<<" of SET : ";
        cin>>elements[i];
    }
}

SET::SET(SET& set)
{
    this->size = set.size;
    this->elements = new int[set.size];
    for(int i=0; i<set.size; i++){
        this->elements[i]=set.elements[i];
    }
}

SET::~SET()
{
    delete[] elements;
}

bool SET::isMember(int element)
{
    for(int i=0; i<size; i++){
        if(element == elements[i])
            return true;
    }
    return false;
}

bool SET::subset(SET set){
    for(int i=0; i<set.size; i++)
    {
        if(!this->isMember(set.elements[i]))
            return false;
    }
    return true;
}

void SET::Union(SET set)
{
    cout<<"{ ";
    for(int i=0; i<this->size; i++)
    {
        cout<<this->elements[i]<<" ";
    }
    for(int i=0; i<set.size; i++)
    {
        if(!this->isMember(set.elements[i]))
            cout<<set.elements[i]<<" ";
    }
    cout<<"}"<<endl;
}

void SET::intersect(SET B)
{
    cout<<"{ ";
    for(int i=0; i<this->size; i++)
    {
        if(this->isMember(B.elements[i]))
            cout<<B.elements[i]<<" ";
    }
    cout<<"}"<<endl;
}

void SET::complement(SET U)
{
    cout<<"{ ";
    for(int i=0; i<U.size; i++)
    {
        if(!this->isMember(U.elements[i]))
            cout<<U.elements[i]<<" ";
    }
    cout<<"}"<<endl;
}

void SET::difference(SET B)
{
    cout<<"{ ";
    for(int i=0; i<this->size; i++)
    {
        if(!B.isMember(this->elements[i]))
            cout<<this->elements[i]<<" ";
    }
    cout<<"}"<<endl;
}

void SET::symmetricDifference(SET B)
{
    cout<<"{ ";
    for(int i=0;i<this->size;i++)
    {
        if(!B.isMember(this->elements[i]))
            cout<<this->elements[i]<<" ";
    }
    for(int i=0;i<B.size;i++)
    {
        if(!this->isMember(B.elements[i]))
            cout<<B.elements[i]<<" ";
    }
    cout<<"}"<<endl;
}

void SET::cartesianProduct(SET B)
{
    cout<<"{ ";
    for(int i=0; i<this->size; i++)
    {
        for(int j=0; j<B.size; j++)
        {
            cout<<"("<<this->elements[i]<<","<<B.elements[j]<<") ";
        }
    }
    cout<<"}"<<endl;
}