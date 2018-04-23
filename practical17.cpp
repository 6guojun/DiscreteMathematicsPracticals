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
};

int main()
{
    int size;
    cout<<"Enter size of graph: ";
    cin>>size;
    Graph G(size);
    cout<<"Degree of Each Vertex"<<endl<<endl;
    G.showDegreeOfEachVertex();
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