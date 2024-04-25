我们已经看到了很多通过类模板特化来实现选择逻辑的例子，更通用地，我们可以实现一个通用的选择，就像是 `if` 语句那样，如果条件为 true，就走一个分支，条件为 false，就走另一个分支。`conditional` 就是编译期的 `if`：

```cpp
template<bool B, typename T, typename F>
struct conditional : type_identity<T> {};

template<typename T, typename F>
struct conditional<false, T, F> : type_identity<F> {};
```

当 B 是 false 时，匹配模板的特化，返回 F；当 B 是 true 时，匹配主模板，返回 T。这里值得一提的是，通过 conditional，我们可以实现一个类似 “短路求值” 的效果。例如我们用 conditional 来实现 is_one_of：

```cpp
// With conditional, we can implement a "short-circuited" is_one_of.
// For is_one_of<int, float, int, double, char>,
// is_one_of<int, double, char> will NOT be instantiated.

template <typename T, typename U, typename... Rest>
struct is_one_of : conditional_t<
  is_same_v<T, U>, true_type, is_one_of<T, Rest...>> {};

template <typename T, typename U>
struct is_one_of<T, U> : conditional_t<
  is_same_v<T, U>, true_type, false_type> {};
```

每一次递归前，我们都先判定了 T 和 剩余所有参数中的第一个 U 是否相等，如果相等，就直接返回 true_type 了，不会再向下递归。所以在上面那个 #2 的例子中，`is_one_of<int, double, char>` 不会再被实例化了。这个技巧有时可以用来优化编译时长。