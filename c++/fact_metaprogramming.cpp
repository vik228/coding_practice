#include <iostream>
using namespace std;

/*
  Factorial
*/
template <size_t n> struct fact;

template <>
struct fact<0> {
  const static auto value = 1;
};

template <size_t n>
struct fact {
  const static auto value = n*fact<n-1>::value;
};

/*
  Fibonacci
*/

template <size_t n> struct fib;

template <>
struct fib<0> {
  const static auto value = 1;
};

template <>
struct fib<1> {
  const static auto value = 1;
};

template<size_t n>
struct fib {
  const static auto value = fib<n-1>::value + fib<n-2>::value;
};

/*
  Variadic template example -> Better than printf("%s\n", ); because here
  compiler knowes everything at compile time.
*/

void printStuff() {
  cout << endl;
}

template <typename Tfirst, typename... Trest>
void printStuff(Tfirst first, Trest... rest) {
  cout << first << ' ';
  printStuff(rest...);
}
static_assert(fib<4>::value == 5, "yoo");
/*
  Tuple example
*/

int main() {
  int a = fact<5>::value;
  cout << fact<1>::value << ' ' << fib<5>::value << "\n";
  static_assert(fib<4>::value == 5, "yoo");
  printStuff(3, 3.3, "foo", 42);
}
