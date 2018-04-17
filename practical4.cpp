#include<iostream>

using namespace std;

class Relation
{
    int** relationMatrix;
    int* domain;
    const int m,n;
    int domainLength;
    bool inDomain(int element);
    bool inRelation(int a,int b);
    int getImage(int element);
public:
    Relation(int size);
    Relation(const Relation& relation);
    ~Relation();
    bool isReflexive();
    bool isSymmetric();
    bool isAntiSymmetric();
    bool isTranisitive();
};

int main()
{
    return 0;
}

Relation::Relation(int size):m(size),n(2)
{
    domainLength = 0;
    relationMatrix = new int*[m];
    for(int i=0; i<m;i ++)
    {
        relationMatrix[i] = new int[2];
    }
    domain = new int[m];
    cout<<"Enter elements of this relation in ordered pairs woth each element separated by space"<<endl;
    for(int i=0; i<m; i++){
        cout<<"Enter element number "<<i+1<<" : ";
        cin>>relationMatrix[i][0];
        cin>>relationMatrix[i][1];
    }
    for(int i=0; i<m; i++)
    {
        if(!inDomain(relationMatrix[i][0]))
        {
            domain[domainLength++] = relationMatrix[i][0];
        }
    }
}

Relation::Relation(const Relation& relation):m(relation.m),n(2)
{
    relationMatrix = new int*[m];
    for(int i=0; i<m;i ++)
    {
        relationMatrix[i] = new int[2];
    }
    for(int i=0; i<m; i++){
        this->relationMatrix[i][0] = relation.relationMatrix[i][0];
        this->relationMatrix[i][1] = relation.relationMatrix[i][1];
    }
    domainLength=relation.domainLength;
    for(int i=0; i<domainLength; i++)
    {
        domain[i]=relation.domain[i];
    }
}

Relation::~Relation(){
    for(int i=0; i<m; i++)
        delete[] relationMatrix[i];
    delete[] relationMatrix;
    delete[] domain;
}

bool Relation::isReflexive()
{
    for(int i=0; i<domainLength; i++)
    {
        if(!inRelation(domain[i],domain[i]))
            return false;
    }
    return true;
}

bool Relation::inDomain(int element){
    for(int i=0; i<domainLength; i++)
        if(domain[i]==element)
            return true;
    return false;
}

bool Relation::inRelation(int a,int b)
{
    for(int i=0; i<m; i++){
        if(relationMatrix[i][0]==a&&relationMatrix[i][1]==b)
            return true;
    }
    return false;
}

bool Relation::isSymmetric()
{
    for(int i=0; i<m; i++)
    {
        if(!(inRelation(relationMatrix[i][0],relationMatrix[i][1])
        &&
        inRelation(relationMatrix[i][1],relationMatrix[i][0])))
            return false;
    }
    return true;
}

bool Relation::isAntiSymmetric()
{
    for(int i=0; i<m; i++)
    {
        if(!(inRelation(relationMatrix[i][0],relationMatrix[i][1])
        &&
        inRelation(relationMatrix[i][1],relationMatrix[i][0])
        &&relationMatrix[i][0]==relationMatrix[i][1]))
            return false;
    }
    return true;
}

bool Relation::isTranisitive()
{
    for(int i=0; i<m; i++)
    {
        if(!(inRelation(relationMatrix[i][0],relationMatrix[i][1])
        &&
        inDomain(relationMatrix[i][1])
        &&
        inRelation(relationMatrix[i][1],getImage(relationMatrix[i][1])))
        &&
        inRelation(relationMatrix[i][0],getImage(relationMatrix[i][1])))
            return false;
    }
    return true;
}

int Relation::getImage(int element)
{
    for(int i=0; i<m; i++)
    {
        if(relationMatrix[i][0]==element)
            return relationMatrix[i][1];
    }
    return -1;
}