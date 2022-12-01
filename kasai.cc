#include <cstdlib>

/**
 * @brief Given text and suffix array positions of length n, calcuate height
 * array of length n
 *
 * @param n length of text and pos
 * @param text
 * @param pos suffix array positions of length n
 * @param height height array to be calcuated
 */
void kasai(int n, char text[], int pos[], int height[]) {
  int *rank = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    rank[pos[i]] = i;
  int h = 0;
  for (int i = 0; i < n; i++)
    if (rank[i] > 0) {
      int k = pos[rank[i] - 1];
      while (text[i + h] == text[k + h])
        h++;
      height[rank[i]] = h;
      if (h > 0)
        h--;
    }
  free(rank);
}

