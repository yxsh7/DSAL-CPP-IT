/*
SI32 Yash Kamthe
GITHUB: https://github.com/yxsh7
Represent a graph of city using adjacency matrix /adjacency list. Nodes
should represent the various landmarks and links should represent the
distance between them. Find the shortest path using Dijkstra's algorithm
from single source to all destination.
*/
#include <iostream>
using namespace std;

#define NumV 6
#define MaxDistance 2147483647 // Maximum value possible for an integer

class Dijkstra
{
private:
    int FindMinDistance(int ShortestPathDistance[], bool ShortestPathFound[]);
    void print(int ShortestPathDistance[]);

public:
    void findMinPath(int graph[NumV][NumV], int src);
};

int Dijkstra::FindMinDistance(int ShortestPathDistance[], bool ShortestPathFound[])
{

    int Distance = MaxDistance;
    int MinDistanceIndex = 0;

    for (int v = 0; v < NumV; v++)
    {
        if (ShortestPathFound[v] == false && ShortestPathDistance[v] <= Distance)
        {
            Distance = ShortestPathDistance[v];
            MinDistanceIndex = v;
        }
    }
    return MinDistanceIndex;
}
void Dijkstra::findMinPath(int graph[NumV][NumV], int src)
{
    int ShortestPathDistance[NumV];
    bool ShortestPathFound[NumV];

    // Initialising
    for (int i = 0; i < NumV; i++)
    {
        ShortestPathDistance[i] = MaxDistance;
        ShortestPathFound[i] = false;
    }

    ShortestPathDistance[src] = 0; // From Source to Source distance is 0

    for (int count = 0; count < NumV - 1; count++)
    {
        // Find and set Minimum Direct Path
        int ShortestPathFrom = FindMinDistance(ShortestPathDistance, ShortestPathFound);
        ShortestPathFound[ShortestPathFrom] = true;

        // Trying to find an indirect shorter paths where a direct one doesn't exist
        if (ShortestPathDistance[ShortestPathFrom] != MaxDistance)
        {
            for (int vertex = 0; vertex < NumV; vertex++)
            {
                if (
                    ShortestPathFound[vertex] == false &&
                    graph[ShortestPathFrom][vertex] != 0 &&
                    ShortestPathDistance[ShortestPathFrom] + graph[ShortestPathFrom][vertex] < ShortestPathDistance[vertex])
                    ShortestPathDistance[vertex] = ShortestPathDistance[ShortestPathFrom] + graph[ShortestPathFrom][vertex];
            }
        }
    }

    print(ShortestPathDistance);
}
void Dijkstra::print(int ShortestPathDistance[])
{

    char VertexNames[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    cout << "Vertex \t\t Distance from Source" << endl;
    for (int i = 0; i < NumV; i++)
        cout << VertexNames[i] << " \t\t\t" << ShortestPathDistance[i] << endl;
}

int main()
{
    int graph[NumV][NumV] = {
        {14, 0, 0, 3, 0},
        {14, 0, 7, 0, 32, 13},
        {0, 7, 0, 12, 0, 19},
        {78, 0, 12, 0, 6, 0},
        {3, 32, 0, 6, 0, 17},
        {0, 13, 19, 0, 17},
    };

    Dijkstra d;

    d.findMinPath(graph, 0);

    return 0;
}