#ifndef MST_H
#define MST_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Union-Find class manages by connecting components in Kruskal's algorithm
// also organizes vertices into disjoint sets. 
class UnionFind {
public:
    unordered_map<string, string> parent;  // maps to pparent
    unordered_map<string, int> rank;  // to track the depth of the tree

    UnionFind(const vector<string>& vertices);   // constructor to initialize sets for each vertex
    string find(const string& vertex);
    void unite(const string& vertex1, const string& vertex2);
};

// structure for represinting the edge of the graph which is crucial in kruskal's algorithm
struct Edge {
    string node1, node2;
    int weight;

    bool operator<(const Edge& other) const;    // sort edges in ascending order
};

// function declarations to be used
pair<int, vector<Edge>> kruskalMST(const vector<string>& vertices, vector<Edge>& edges);  // used algorith kruskal's algorithm
void readGraph(const string& filename, vector<string>& vertices, vector<Edge>& edges);   
void writeMST(const string& filename, int totalWeight, const vector<Edge>& mstEdges);

#endif // _MST_H

