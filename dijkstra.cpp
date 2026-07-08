// Dijkstra's shortest-path algorithm, using the min-heap from heap.h/heap.cpp
// as the priority queue.
//
// The graph is given as an N x N cost matrix: dist[i][j] is the weight of the
// edge i -> j. A non-positive entry off the diagonal means "no edge". The
// diagonal (i == i) is ignored.
//
//   g++ -std=c++20 -Wall -Wextra dijkstra.cpp -o dijkstra && ./dijkstra

#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

#include "heap.h"
#include "heap.cpp"  // template definitions

typedef std::vector<std::vector<int>> matrix;

// The heap orders by operator<, and std::pair compares lexicographically, so a
// (distance, vertex) pair with the smallest distance ends up at the top -- the
// vertex-tie-breaker keeps the ordering total.
typedef std::pair<int, int> DistNode;

static const int INF = std::numeric_limits<int>::max();

// Returns { total distance, path } for the shortest route from `from` to `to`.
// If `to` is unreachable the distance is INF and the path is empty.
std::pair<int, std::vector<int>> dijkstra(const matrix &dist, int from, int to) {
  const int n = static_cast<int>(dist.size());

  std::vector<int> best(n, INF);      // best known distance from `from`
  std::vector<int> prev(n, -1);       // predecessor on the best path
  std::vector<bool> done(n, false);   // finalized vertices

  Heap<DistNode> pq;
  best[from] = 0;
  pq.add({0, from});

  while (pq.size() > 0) {
    auto [d, u] = pq.peek();
    pq.pop();

    // Lazy deletion: skip stale entries left over from an earlier relaxation.
    if (done[u]) continue;
    done[u] = true;
    if (u == to) break;

    for (int v = 0; v < n; ++v) {
      if (v == u) continue;
      const int w = dist[u][v];
      if (w <= 0) continue;                 // no edge
      if (done[v]) continue;

      const int cand = d + w;
      if (cand < best[v]) {
        best[v] = cand;
        prev[v] = u;
        pq.add({cand, v});                  // push relaxed distance
      }
    }
  }

  if (best[to] == INF) return {INF, {}};

  // Reconstruct the path by walking predecessors back from `to`.
  std::vector<int> path;
  for (int at = to; at != -1; at = prev[at]) path.push_back(at);
  std::reverse(path.begin(), path.end());
  return {best[to], path};
}

// distances[i][j] is the distance from city i to city j.
static matrix distances = {
    {0, 3, 5, 1, 7},
    {3, 0, 1, 5, 3},
    {7, 7, 0, 2, 3},
    {9, 2, 1, 0, 6},
    {1, 1, 1, 1, 0}};

int main() {
  const int n = static_cast<int>(distances.size());

  for (int to = 0; to < n; ++to) {
    auto [d, path] = dijkstra(distances, 0, to);
    std::cout << "0 -> " << to << ": ";
    if (d == INF) {
      std::cout << "unreachable\n";
      continue;
    }
    std::cout << "distance " << d << ", path ";
    for (std::size_t i = 0; i < path.size(); ++i) {
      std::cout << path[i] << (i + 1 < path.size() ? " -> " : "\n");
    }
  }
  return 0;
}
