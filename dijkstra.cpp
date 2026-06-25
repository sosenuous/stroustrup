#include <vector>
#include <iostream>
// cities 0,1, .... n 
// distances from i -> j ,   which can write down as a matrix


//  we have 3 cities, each entry (0,1) .... how far is it from city 0 to city 1, etc
//      
//       x    1    2  
//       3    x    7  
//       -    4    x 
//
//.  std::v//ector<std::vector<int>>  distances; 
//
//.  starting 0  , ending in 2
// 
//   pair<int, bool> 
//
//   make_pair(vector<pair <int, bool))> .... the shortest path found so far , initialised to infinity 
//. vector<bool> visited ; // initialised to false
//.  vector<int> ... shortest paths // initialised to infinity (or something large)
//. initialised to infinity, starting city initialised to 0, true
//.  in each step, until the target is visited (i.e. it turns visite)
//.  find the city which is not visited and has the shortes path (smallest number) in shortest_paths
//.  following the matrix of distances, we have update all neighbouring cities (where there is a path) 
//   with the new distance, provided that it is shorter than the one found so far


///. 0.   1.   2 <- 
//
///. current length, new candidate for 0 is 1 + 3 = 4 , 
//.  1 +7 = 8   ... 
//. mark 1 as visited
//   


typedef std::vector<std::vector<int>> matrix; 



static matrix distances =
    { 
    { 0, 3, 5, 1, 7}, 
    { 3, 0, 1, 5, 3},
    { 7, 7, 0, 2, 3},
    { 9, 2, 1, 0, 6},
    { 1, 1, 1, 1, 0}}; 


class myClass {
public: 
    myClass(){ number_of_instances++;}

    ~myClass() {number_of_instances--; } 


    int static howMany() { return number_of_instances;}

private:
    static int number_of_instances; 
} ;

 // distances[i][j] ... is the distance from city i to city j

using namespace std;


std::pair<int, int>  disjkstra(int n, matrix dist , int from, int to) 
{ // matrix has dimension  n x n 
    int i; 
    matrix distances; 

    vector< std::pair<bool,int> >  visited ; 

    // 

}

