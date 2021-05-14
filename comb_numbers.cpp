#include <cmath>
#include <new>

unsigned int U(unsigned int m, unsigned int n, bool& error) {
  unsigned int result = 1;
  
  if (m == 1)
    error = false;
    return 1;

  for (unsigned int i = 0; i < n; i++) {
    if (_UI32_MAX / m < result) {
      error = true;
      return result;
    }
    else {
      result *= m;
    }
  }
  error = false;
  return result;
}

unsigned int A(unsigned int m, unsigned int n, bool& error) {
  unsigned int result = 1;
  if (n > m) {
    error = false;
    return 0;
  }
  for (unsigned int i = m; i > m - n; i--) {
    if (_UI32_MAX / i < result) {
      error = 1;
      return result;
    }
    else {
      result *= i;
    }
  }
  error = false;
  return result;
}

unsigned int P(unsigned int n,bool& error) {
  unsigned int result = 1;
  for (unsigned int i = 2; i <= n; i++) {
    if (_UI32_MAX / i < result) {
      error = true;
      return result;
    }
    else {
      result *= i;
    }
  }
  error = false;
  return result;
}

unsigned int C(unsigned int m, unsigned int n, bool& error) {
  if (n == 1 || m == n + 1)
    return m;
  if (n > m)
    return 0;
  if (n == m || n == 0)
    return 1;

  if (n > m - n)
    n = m - n;

  unsigned int a = m - n + 1;
  unsigned int k = m - n + 2;
  for (unsigned int i = 2; i <= n; i++) {
    //unsigned adiv = a / i, amod = a % i;
    if (a / i > _UI32_MAX / k || a % i > _UI32_MAX / k * i || a / i * k > _UI32_MAX - a % i * k / i || k == _UI32_MAX) {
      error = true;
      return 0;
    }
    a = a / i * k + a % i * k / i;
    k++;
  }
  return a;
}

unsigned int S(unsigned int m, unsigned int n, bool& error) {
  if (n == m || n == 1)
    return 1;
  if (n == 0 || n > m)
    return 0;

  unsigned int d = n < m - n + 1 ? n : m - n + 1;
  unsigned int s = n > m - n + 1 ? n : m - n + 1;
  unsigned int* arr = NULL;
  try {
    arr = new unsigned int[d];
    //std::bad_alloc alloc;
    //throw alloc;
  }
  catch (std::bad_alloc){
    error = true;
    return 0;
  }

  for (unsigned int i = 0; i < d; i++) {
    arr[i] = 1;
  }

  for (unsigned int i = 2; i <= s; i++) {
    for (unsigned int j = 1; j < d; j++) {
      if (d == n) {
        if (arr[j] > _UI32_MAX / (j + 1) || arr[j - 1] > _UI32_MAX - (j + 1) * arr[j]) {
          error = true;
          delete[] arr;
          return 0;
        }
        arr[j] = arr[j - 1] + (j + 1) * arr[j];
      }
      else {
        if (arr[j - 1] > _UI32_MAX / i || arr[j] > _UI32_MAX - i * arr[j - 1]) {
          error = true;
          delete[] arr;
          return 0;
        }
        arr[j] = arr[j] + i * arr[j - 1];
      }
    }
  }

  error = false;
  unsigned result = arr[d - 1];
  delete[] arr;
  return result;
}

unsigned int B(unsigned int m, bool& error) {
  if (m == 0)
    return 1;
  if (m > 20) {
    error = true;

    return 0;
  }

  unsigned int* arr = NULL;
  try {
    arr = new unsigned int[m];
    //std::bad_alloc alloc;
    //throw alloc;
  }
  catch (std::bad_alloc) {
    error = true;
    return 0;
  }

  arr[0] = 1;
  for (unsigned int i = 1; i < m; i++) {
    unsigned int t = arr[0];
    arr[0] = arr[i - 1];
    for (unsigned int k = 1; k <= i; k++) {
      unsigned int s = arr[k];
      if (arr[k - 1] > _UI32_MAX - t) {
        error = true;
        delete[] arr;
        return 0;
      }
      arr[k] = arr[k - 1] + t;
      t = s;
    }
  }

  error = false;
  unsigned int res = arr[m - 1];
  delete[] arr;
  return res;
}