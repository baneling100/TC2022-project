#ifndef _lcp_h
#define _lcp_h

#include <tuple>
#include <vector>

/**
 * @brief Given text of length n, calculate suffix array with O(nlogn) algorithm
 * using counting sort
 *
 * @param n length of text
 * @param text last character should be a special character
 * @param pos suffix array
 */
void SuffixArray(int n, char text[], int pos[]);

/**
 * @brief Given text and suffix array of length n, calculate height array with
 * linear time algorithm.
 *
 * @param n length of text and pos
 * @param text last character should be a special character
 * @param pos suffix array, value range [0, n)
 * @param height lcp array
 */
void KasaiHeight(int n, char text[], int pos[], int height[]);

/**
 * @brief Given text and suffix array of length n, calculate height array with
 * naive algorithm of O(n^2)
 *
 * @param n length of text and pos
 * @param text last character should be a special character
 * @param pos suffix array, value range [0, n)
 * @param height lcp array
 */
void NaiveHeight(int n, char text[], int pos[], int height[]);

/**
 * @brief Algorithm that computes in O(n) time the list of all triples generated
 * by the post-order traversal of the suffix tree when the suffix array and
 * height array is given.
 *
 * @param n length of pos and height
 * @param pos suffix array, value range [0, n)
 * @param height lcp array
 * @param result result vector
 */
void TraverseWithArray(int n, int pos[], int height[],
                       std::vector<std::tuple<int, int, int>> &result);

/**
 * @brief A naive algorithm that traverse only with suffix array and binary
 * search.
 *
 * @param n length of pos
 * @param text
 * @param pos suffix array
 * @param result result vector
 */
void TraverseWithBinary(int n, char text[], int pos[],
                        std::vector<std::tuple<int, int, int>> &result);

#endif // _lcp_h
