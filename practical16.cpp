#include<iostream>

using namespace std;

class Graph
{
    int** adjajencyMattrix;
    const int size;
public:
    Graph(int size);
    Graph(const Graph& graph);
    ~Graph();
    bool isComplete();
};

int main()
{
    int size;
    cout<<"Enter size of graph: ";
    cin>>size;
    Graph G(size);
    cout<<"Is Graph complete?"<<endl;
    cout<<"Ans: "<<boolalpha<<G.isComplete()<<endl;
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