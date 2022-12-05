#pragma once
#include <vector> 
#include <string> 
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <unordered_map>
#include <limits.h>
#include "/workspaces/cs225/Final-Project/lib/cs225/PNG.h"

using namespace std; 
using namespace cs225;
class Graph {
    public:
        struct Node {
            Node(string article) : data(article), degree(0) {}; // Node constructor
            vector<pair<int, Node*>> adjList;  // list of adjacent nodes and their edge weights
            string data; // Article name
            int degree; // Number of total edges connected to node (adjList.size())
            pair<int,int> coord; //coordinate of the center for BFS visualization
        };
       
        Graph(); 
        void removeVertex(Node* v);
        vector<string> incidentEdges(Node* v); //returns the list of edges adjacent to node v
        bool areAdjacent(Node* v1, Node* v2); 
        void insertEdge(Node* v1, Node* v2);
        void insertEdge(Node* v1, Node* v2, int weight);
        int getNodeDegree(Node* v);
        
        //Graph Algorithms:
        vector<Graph::Node*> BFS(Node* start);
        PNG* visualizeBFS();

        //Helper functions for visualizeBFS
        void drawEdge(Node* node1, Node* node2,PNG* image);
        void drawNode(Node* node, PNG* image);

        // vector<Graph::Node*> dijkratasAlgorithm(Node* start,Node* end);
        //functions added so tests will compile
        int getNodeListSize();
        Node* getNode(string article);
        
        // Need to add rule of 3 functions because the nodes are dynamically allocated
        ~Graph();
        Graph(const Graph& other);
        Graph& operator=(const Graph& other);

    private:
        int size = 10000; // Just testing for visualizeBFS
        void readFromFile();
        string decodeHTTP(string title);
        vector<Node*> nodeList_;
        unordered_map<string, string> converted;

        //helpers for rule of three
        void clear();
        void copy(const Graph& other);

        
};

