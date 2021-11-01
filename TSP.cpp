#include <iostream>
#include <bits/stdc++.h>

#define N 4

using namespace std;

int travellingSalesMan(int nodes[][N], int s) {
    vector<int> vertex;
    
    for (int i = 0; i < N; i++) {
        if (i != s) {
            vertex.push_back(i);
        }
    }
    
    int min_path = INT_MAX; 
    
    do {
        int k = s;
        int curr_path = 0;
        
        for (int i = 0; i < vertex.size(); i++) {
            curr_path += nodes[k][vertex[i]];
            k = vertex[i];
        }
        
        curr_path += nodes[k][s];
        
        min_path = min(curr_path, min_path);
        
    } while(next_permutation(vertex.begin(), vertex.end()));
    
    return min_path;
}

int main()
{
     int nodes[][N] = { 
         { 0, 10, 15, 20 },
         { 10, 0, 35, 25 },
         { 15, 35, 0, 30 },
         { 20, 25, 30, 0 }
    };
    
    cout<<travellingSalesMan(nodes , 0);

    return 0;
}
