//  The '->' symbol is used in trailing return type syntax to explicitly specify the return type of a function. This syntax was introduced in C++11 to simplify the declaration of functions with complicated return types or return types that depend on template parameters 

// Minimalist example of a function that uses a trailing return type
auto GetNumber() -> int {
  return 42;
}

// The benefit of the trailing return type is that it now has access to those parameters. This lets the compiler infer the return type based on those values:
auto Add(int x, int y) -> decltype(x + y) {
  return x + y;
}

// More references: https://www.studyplan.dev/pro-cpp/trailing-return-type