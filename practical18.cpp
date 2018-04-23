#include<iostream>

using namespace std;

class Graph
{
    int** adjajencyMattrix;
    const int size;
    int calculateInDegree(int vertex);
    int calculateOutDegree(int vertex);
public:
    Graph(int size);
    Graph(const Graph& graph);
    ~Graph();
    bool isComplete();
    void showDegreeOfEachVertex();
    int noOfPathsBetween(int vertexA,int vertexB,int length);
};

int main()
{
    int size;
    int vertexA,vertexB,length;
    cout<<"Enter graph size: ";
    cin>>size;
    Graph G(size);
    cout<<"Enter vertex A: ";
    cin>>vertexA;
    cout<<"Enter vertex B: ";
    cin>>vertexB;
    cout<<"Enter length of path: ";
    cin>>length;
    cout<<"No of paths between vertexA and vertexB = "<<G.noOfPathsBetween(vertexA,vertexB,length)<<endl;    
}

Graph::Graph(int size):size(size)
{
    adjajencyMattrix = new int*[size];
    for(int i=0; i<size; i++)
        adjajencyMattrix[i] = new int[size];

    for(int i=0; i<size; i++)
    {
        cout<<"Enter row number "<<i+1<<" of adjajency mattrix("<<size<<" X "<<size<<"): ";
        for(int j=0; j<size; j++)
        {
            cin>>adjajencyMattrix[i][j];
        }
    }
}

Graph::~Graph()
{
    for(int i=0; i<size; i++)
        delete[] adjajencyMattrix[i];
    delete[] adjajencyMattrix;
}

Graph::Graph(const Graph& graph):size(graph.size)
{
    adjajencyMattrix = new int*[size];
    for(int i=0; i<size; i++)
        adjajencyMattrix[i] = new int[size];

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            adjajencyMattrix[i][j] = graph.adjajencyMattrix[i][j];
    }
}

bool Graph::isComplete()
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++){
            if(i==j)
                continue;
            if(adjajencyMattrix[i][j]==0)
                return false;
        }
    }
    return true;
}

int Graph::calculateInDegree(int vertex)
{
    int total = 0;
    for(int i=0;i<size;i++)
    {
        if(adjajencyMattrix[i][vertex]==1)
            total++;
    }
    return total;
}

int Graph::calculateOutDegree(int vertex)
{
    int total = 0;
    for(int i=0;i<size;i++)
    {
        if(adjajencyMattrix[vertex][i]==1)
            total++;
    }
    return total;
}

void Graph::showDegreeOfEachVertex()
{
    for(int i=0;i<size;i++)
    {
        cout<<"Vertex "<<i+1<<": Indegree = "<<calculateInDegree(i)<<" ; OutDegree = "<<calculateOutDegree(i)<<endl;
    }
}

int Graph::noOfPathsBetween(int vertexA,int vertexB,int length)
{
    int count = 0;
    if(vertexA == vertexB && length == 0)
        return 1;
    if(adjajencyMattrix[vertexA-1][vertexB-1]==1&&length==1)
        return 1;
    if(length==0)
        return 0;
    for(int i=1;i<=size;i++)
    {
        if(adjajencyMattrix[vertexA-1][i]==1)
            count+=noOfPathsBetween(i,vertexB,length-1);
    }
    return count;
}