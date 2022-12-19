#include "lcp.h"
#include <stack>

void TraverseWithArray(int n, int pos[], int height[],
                       std::vector<std::tuple<int, int, int>> &result) {
  std::stack<std::pair<int, int>> s;
  s.emplace(-2, -1);
  height[0] = -1;
  for (int i = 0; i <= n; i++) {
    int Llca = i - 1;
    int Hlca = i == n ? -1 : height[i];
    auto [L, H] = s.top();
    while (H > Hlca) {
      s.pop();
      int R = i - 1;
      result.emplace_back(L, R, H);
      Llca = L;
      auto [p, q] = s.top();
      L = p;
      H = q;
    }
    if (H < Hlca)
      s.emplace(Llca, Hlca);
    s.emplace(i, n - pos[i] + 1);
  }
}
