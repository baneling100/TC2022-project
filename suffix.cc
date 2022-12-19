#include "lcp.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void SuffixArray(int n, char text[], int pos[]) {
  // allocate memory space to be used
  int *ord = (int *)malloc(sizeof(int) * n);
  int *aux = (int *)malloc(sizeof(int) * n);
  int *nord = (int *)malloc(sizeof(int) * n);
  int cnt_max = std::max(256, n);
  int *cnt = (int *)malloc(sizeof(int) * cnt_max);

  // initialize
  for (int i = 0; i < n; i++) {
    pos[i] = i;
    ord[i] = (unsigned char)text[i];
  }
  int t = 1;
  int pnt = 0;

  while (pnt < n - 1) {
    // first counting sort: compare i + t's
    memset(cnt, 0, sizeof(int) * cnt_max);
    for (int i = 0; i < n; i++)
      cnt[ord[std::min(i + t, n - 1)]]++;
    for (int i = 1; i < cnt_max; i++)
      cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--)
      aux[--cnt[ord[std::min(i + t, n - 1)]]] = i;

    // second counting sort: compare i's
    memset(cnt, 0, sizeof(int) * cnt_max);
    for (int i = 0; i < n; i++)
      cnt[ord[i]]++;
    for (int i = 1; i < cnt_max; i++)
      cnt[i] += cnt[i - 1];

    // renew pos
    for (int i = n - 1; i >= 0; i--)
      pos[--cnt[ord[aux[i]]]] = aux[i];

    // renew order
    pnt = 0;
    nord[pos[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (ord[pos[i - 1]] != ord[pos[i]] ||
          ord[pos[i - 1] + t] != ord[pos[i] + t])
        pnt++;
      nord[pos[i]] = pnt;
    }
    memcpy(ord, nord, sizeof(int) * n);

    // next phase
    t *= 2;
  }

  // deallocate memory space used
  free(ord);
  free(aux);
  free(nord);
  free(cnt);
}
