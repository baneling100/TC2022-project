#include <cstdlib>

/**
 * @brief Given text and suffix array of length n, calculate height array with
 * linear time algorithm.
 *
 * @param n length of text and pos
 * @param text last character should be a special character
 * @param pos suffix array, value range [0, n)
 * @param height lcp array
 */
void KasaiHeight(int n, char text[], int pos[], int height[]) {
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

/**
 * @brief Given text and suffix array of length n, calculate height array with
 * naive algorithm of O(n^2)
 *
 * @param n length of text and pos
 * @param text last character should be a special character
 * @param pos suffix array, value range [0, n)
 * @param height lcp array
 */
void NaiveHeight(int n, char text[], int pos[], int height[]) {
  for (int i = 1; i < n; i++) {
    height[i] = 0;
    while (text[pos[i - 1] + height[i]] == text[pos[i] + height[i]])
      height[i]++;
  }
}
