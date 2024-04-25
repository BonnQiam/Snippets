
这个例子展示变长形参，我们将 `is_same` / [[is_same]] 推广一下，给定一个类型 `T`，和一堆类型列表，判定 `T` 是否包含在这个列表之中。

```cpp
template <typename T, typename U, typename... Rest>
struct is_one_of : bool_constant<is_one_of<T, U>::value || is_one_of<T, Rest...>::value> {};

template <typename T, typename U>
struct is_one_of<T, U> : is_same<T, U> {};

int i = 0;
std::cout << is_one_of_v<decltype(i), float, double> << std::endl;               // 0, #1
std::cout << is_one_of_v<decltype(i), float, int, double, char> << std::endl;    // 1, #2
```

- `is_one_of` 的主模板形参分为三个部分：类型 `T`，类型 `U`，和变长形参列表（Parameter Pack）`Rest`，另有一个特化模板，只接受两个参数 `T` 和 `U`，这个特化的逻辑等效于 `is_same` / [[is_same]]。
- 主模板的递归逻辑是一个析取表达式，判定 `T` 和 `U` 是否相等，或者判定 `T` 是不是包含在剩余的参数中。这里的 `Rest...` 是对变长形参列表的展开，当我们要引用一个变长形参列表内的内容时，就需要这样写。这个递归会一直持续遍历所有的参数，直到只剩下 `T` 和 最后一个参数，这时匹配模板特化，递归终止。

要注意的是，这个析取表达式的求值与运行时不同，运行时的析取表达式遵循 “短路求值（short-circuit evaluation）” 的规则，对 `a || b` 如果 `a` 为 `true`，就不再对 `b` 求值了。但是在编译期，在模板实例化的时候，析取表达式的短路求值是不生效的，例如对 `#2`，虽然在遍历到 `bool_constant<is_one_of<int, int> || is_one_of<int, double, char>>` 的时候，虽然前面的表达式已经可以确定为 `true` 了，但是后半部分的表达式 `is_one_of<int, double, char>` 依旧会被实例化。感兴趣的同学可以尝试用代码证明这个问题。

另外，有一个元编程的小技巧是，有时我们可以通过一个简单地别名来实现一个新的 Metafunction。例如：

```cpp
// alias template
template <typename T>
using is_integral = is_one_of<T, bool, char, short, int, long, long long>;
```