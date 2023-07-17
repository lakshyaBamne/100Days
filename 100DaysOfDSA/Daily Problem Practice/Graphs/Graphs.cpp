#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<utility>

#include "Graphs.h"

using namespace std;


/*
    Ques-1 Find the unit area of the largest region of 1's

    -> This implementation is correct in concept and in practice but gives 
    !Time Limit Exceeded)
*/
// utility function to print a queue anytime
void GraphProblems::show_queue(queue<pair<int,int>> myQueue){
    int queue_size = myQueue.size();
    
    cout << "Queue : <- | ";
    for(int i=0 ; i<queue_size ; i++){
        cout << "<" << myQueue.front().first << "," << myQueue.front().second << "> ";
    
        myQueue.push(myQueue.front());
        myQueue.pop();
    }
    cout << endl;
}


// function takes a point and the dimensions of the grid
// and returns true if the point is inside the grid strictly
bool GraphProblems::is_inside(int row, int col, pair<int,int> point){
    bool row_inside = ( point.first>=0 && point.first<row );
    bool col_inside = ( point.second>=0 && point.second<col );
    
    return (row_inside && col_inside);
}

// function returns a vector of the neighbours of the given grid point
// which are inside the grid boundaries
vector<pair<int,int>> GraphProblems::find_neighbours(int row, int col, pair<int,int> point){
    vector<pair<int,int>> neighbours;
    
    vector<pair<int,int>> possible_index;
    possible_index.push_back( make_pair( point.first-1, point.second-1 ) );
    possible_index.push_back( make_pair( point.first-1, point.second ) );
    possible_index.push_back( make_pair( point.first-1, point.second+1 ) );
    possible_index.push_back( make_pair( point.first, point.second+1 ) );
    possible_index.push_back( make_pair( point.first+1, point.second+1 ) );
    possible_index.push_back( make_pair( point.first+1, point.second ) );
    possible_index.push_back( make_pair( point.first+1, point.second-1 ) );
    possible_index.push_back( make_pair( point.first, point.second-1 ) );
    
    for(auto i : possible_index){
        if( is_inside(row, col, i) ){
            neighbours.push_back(i);
        }
    }
    
    return neighbours;
}


// function takes the grid and the root of start to find the area of 
// a connected region obtained by performing BFS from the given root
int GraphProblems::area_connected_region(vector<vector<int>>& grid, vector<vector<bool>>& visited,pair<int,int> root){
    
    int row = grid.size();
    int col = grid[0].size();
    
    int curr_count = 0;
    
    // we need to maintain a processing queue
    queue<pair<int,int>> processing;
    
    pair<int,int> to_process;
    
    processing.push(root);
    visited[root.first][root.second] = true;
    
    // we stop when there are no more grid points to process
    while( !processing.empty() ){

        to_process = processing.front();
        processing.pop();
        curr_count++;
        
        // add the adjacent nodes to the popped point int the queue
        vector<pair<int,int>> neighbours = find_neighbours(row, col, to_process);
        
        for(auto i : neighbours){
            if( !visited[i.first][i.second] && grid[i.first][i.second]==1 ){
                visited[i.first][i.second] = true;        
                processing.push(i);
            }
        }
        
    }
    
    return curr_count;
    
    
}

// function returns the next root point from where BFS can be restarted to get 
// area of the disconnected region
pair<int,int> GraphProblems::find_next_root(vector<vector<int>>& grid, vector<vector<bool>>& visited,pair<int,int> last_root){    
    int row = grid.size();
    int col = grid[0].size();
    
    // we need to find the next instance of 1 in grid after last_root
    for(int i=last_root.first ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if( grid[i][j]==1 && !visited[i][j] ){
                return make_pair(i,j);
            }
        }
    }
    
    // if control reaches here that means there are no more valid 
    // instances of 1.
    return make_pair(row, col);
}

//Function to find unit area of the largest region of 1s.
int GraphProblems::findMaxArea(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    
    // we need to maintain boolean visited matrix
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    
    int max_area = 0; // current maximum area found among disconnected components
    int curr_area = 0; // area of current connected region
    
    // we need to find a 1 in the grid which can be used as a root for BFS
    pair<int,int> root = make_pair(0,0);
    root = find_next_root(grid, visited, root);
    
    // search for a larger area stops when we have compared areas
    // of all disconnected regions
    while( root.first<row && root.second<col ){        
        curr_area = area_connected_region(grid, visited, root);
        
        if( curr_area > max_area ){
            max_area = curr_area;
        }
        
        root = find_next_root(grid, visited, root);
            
    }
    
    return max_area;
    
}