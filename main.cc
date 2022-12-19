#include "lcp.h"
#include <cassert>
#include <cerrno>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>

char *ReadHarryPotter(int *n) {
  char filename[30];
  FILE *fp[8];
  long filesize[8] = {0};

  for (int i = 1; i <= 7; i++) {
    sprintf(filename, "harryPotter/Book%d.txt", i);
    fp[i] = fopen(filename, "r");
    assert(fseek(fp[i], 0, SEEK_END) == 0 && strerror(errno));
    filesize[i] = ftell(fp[i]);
    assert(filesize[i] != -1 && strerror(errno));
    filesize[i] += filesize[i - 1];
    assert(fseek(fp[i], 0, SEEK_SET) == 0 && strerror(errno));
  }
  char *text = (char *)malloc(filesize[7] + 1);
  for (int i = 1; i <= 7; i++) {
    assert(fread(text + filesize[i - 1], 1, filesize[i] - filesize[i - 1],
                 fp[i]) == filesize[i] - filesize[i - 1] &&
           "error on fread");
    assert(fclose(fp[i]) == 0 && strerror(errno));
  }
  text[filesize[7]] = '\0';
  *n = filesize[7] + 1;
  return text;
}

char *ReadRandomText(int *n) {
  FILE *fp = fopen("random.txt", "r");
  assert(fseek(fp, 0, SEEK_END) == 0 && strerror(errno));
  long filesize = ftell(fp);
  assert(filesize != -1 && strerror(errno));
  assert(fseek(fp, 0, SEEK_SET) == 0 && strerror(errno));
  char *text = (char *)malloc(filesize + 1);
  assert(fread(text, 1, filesize, fp) == filesize && "error on fread");
  assert(fclose(fp) == 0 && strerror(errno));
  text[filesize] = '\0';
  *n = filesize + 1;
  return text;
}

void Test(int n, char text[]) {
  int *pos = (int *)malloc(sizeof(int) * n);
  int *naive = (int *)malloc(sizeof(int) * n);
  int *kasai = (int *)malloc(sizeof(int) * n);
  std::vector<std::tuple<int, int, int>> naiveRes, kasaiRes;

  auto begin = std::chrono::high_resolution_clock::now();
  SuffixArray(n, text, pos);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  printf("    SuffixArray: %lf\n", elapsed.count() * 1e-9);

  begin = std::chrono::high_resolution_clock::now();
  NaiveHeight(n, text, pos, naive);
  end = std::chrono::high_resolution_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  printf("    NaiveHeight: %lf\n", elapsed.count() * 1e-9);

  begin = std::chrono::high_resolution_clock::now();
  KasaiHeight(n, text, pos, kasai);
  end = std::chrono::high_resolution_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  printf("    KasaiHeight: %lf\n", elapsed.count() * 1e-9);

  // correctness check
  for (int i = 1; i < n; i++)
    if (naive[i] != kasai[i]) {
      printf("    Wrong\n");
      break;
    }

  begin = std::chrono::high_resolution_clock::now();
  TraverseNaively(n, text, pos, naiveRes);
  end = std::chrono::high_resolution_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  printf("    TraverseNaively: %lf\n", elapsed.count() * 1e-9);

  begin = std::chrono::high_resolution_clock::now();
  TraverseWithArray(n, pos, kasai, kasaiRes);
  end = std::chrono::high_resolution_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  printf("    TraverseWithArray: %lf\n", elapsed.count() * 1e-9);

  free(pos);
  free(naive);
  free(kasai);
}

int main() {
  int n;
  printf("HarryPotter\n");
  char *text = ReadHarryPotter(&n);
  Test(n, text);
  free(text);

  printf("Random\n");
  text = ReadRandomText(&n);
  Test(n, text);
  free(text);

  return 0;
}
