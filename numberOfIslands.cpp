/*
Task: Given a binary 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 4 islands.

Input: mat[][] = {{1, 1, 0, 0, 0},
                  {0, 1, 0, 0, 1},
                  {1, 0, 0, 1, 1},
                  {0, 0, 0, 0, 0},
                  {1, 0, 1, 0, 0}}
Output: 4

Island is a group of connected 1's, graph above has 4 islands: 1,1,1,1 ; 1,1,1 ; 1 ; 1.
We can use DFS() - Depth-first search.

Solving: 

*/
#include <stdio.h>
#include <cstring>
#include <iostream>

#define ROW 5
#define COL 5

// Check if given cell can be used for DFS
int isSafe(int M[][COL], int row, int col, bool visited[][COL]){
    // row and col is between 0 and 4 (size of our matrix) and if it was visited
    return (row >=0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}

//DFS algorithm
void DFS(int M[][COL], int row, int col, bool visited[][COL]){
/*
rowNbr[0] and colNbr[0] correspond to the top-left neighbor (-1, -1)
rowNbr[1] and colNbr[1] correspond to the top neighbor (-1, 0)
rowNbr[2] and colNbr[2] correspond to the top-right neighbor (-1, 1)
rowNbr[3] and colNbr[3] correspond to the left neighbor (0, -1)
rowNbr[4] and colNbr[4] correspond to the right neighbor (0, 1)
rowNbr[5] and colNbr[5] correspond to the bottom-left neighbor (1, -1)
rowNbr[6] and colNbr[6] correspond to the bottom neighbor (1, 0)
rowNbr[7] and colNbr[7] correspond to the bottom-right neighbor (1, 1)
*/

static int rowNbr[] = {-1,-1,-1,0,0,1,1,1};
static int colNbr[] = {-1,0,1,-1,1,-1,0,1};

visited[row][col]=true;

for(int k = 0;k < 8; ++k){
    if(isSafe(M,row + rowNbr[k],col + colNbr[k],visited))
        DFS(M,row + rowNbr[k],col + colNbr[k],visited);
}

}


int countIslands(int M[][COL]){
    bool visited[ROW][COL];
    memset(visited,0,sizeof(visited));

    int count = 0;
    for(int i = 0; i < ROW; ++i)
        for(int j = 0; j < COL; ++  j)
            if (M[i][j] && !visited[i][j]){
                DFS(M,i,j,visited);
                ++count;
            }
return count;
}

int main(){
    int M[][COL] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 0 } };

    std::cout << "Number of islands: " << countIslands(M) << std::endl;
}