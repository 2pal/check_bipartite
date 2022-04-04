#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int> >& graph) {
        int graphSize = graph.size();
        int colorArr[graphSize];
        for(int i=0; i<graphSize; i++){
            colorArr[i] = -1;
        }        
        queue <int> q;
        q.push(0);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            unsigned vertexSize = graph[u].size();
            for (int v = 0; v < vertexSize; ++v)
            {
                int edge = graph[u][v];
                if (colorArr[edge] == -1)
                {
                    colorArr[edge] = 1 - colorArr[u];
                    q.push(edge);
                }
     
                else if (colorArr[edge] == colorArr[u])
                    return false;
            }
        }
        return true;
    }
};

// This function is provided to check if your graph data is stored well or not
void printv(vector <vector <int> > v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    // Solution class for bipartite-ness problem
    Solution s;

    // Read data filename from std input stream and open it with file handler/pointer
    string fname;
    cin >> fname;
    ifstream graphFileHandler(fname);

    // An array of integers to store neighbours of a vertex
    vector <int> adj;
    // A 2D array of integers to store neighbours of each vertex in a graph
    vector<vector <int> > graph;

    string line;
    // Read from the file until there is no new line left
    while (graphFileHandler >> line) {
        // Save line as string stream object
        stringstream ss(line);
        // Get a string variable
        string substr;

        // Until the end of the line, read the line as substings separated by commas
        while (ss.good()) {
            getline(ss, substr, ',');
            // Push the substring in adjacency list, we got a neighbour here
            adj.push_back(stoi(substr));
        }

        // When line ends, push all the neighbours of the vertex into the graph
        graph.push_back(adj);

        // Clear the array, before the next iteration begins
        // Next iteration, we will read the subsequent line from the file and it will contain neighbours of some other guy
        adj.clear();
    }
    printv(graph);

    // Save the return value of the function
    bool answer = s.isBipartite(graph);

    // If answer is True, print True otherwise False
    if (answer == 1)
        cout << "True" <<endl;
    else
        cout << "False" << endl;

    return 0;
}
