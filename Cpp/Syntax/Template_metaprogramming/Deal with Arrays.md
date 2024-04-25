最后一组例子，我们来看在 TMP 中是怎么处理数组类型的。

## 3.4.1 rank

rank 返回数组的维度。

```cpp
std::cout << rank_v<int> << std::endl;              // 0
std::cout << rank_v<int[5]> << std::endl;           // 1
std::cout << rank_v<int[5][5]> << std::endl;        // 2
std::cout << rank_v<int[][5][6]> << std::endl;      // 3

template <typename T>
struct rank : integral_constant<std::size_t, 0> {};                          // #1

template <typename T>
struct rank<T[]> : integral_constant<std::size_t, rank<T>::value + 1> {};    // #2

template <typename T, std::size_t N>
struct rank<T[N]> : integral_constant<std::size_t, rank<T>::value + 1> { };  // #3
```

rank 包含一个主模板和两个偏特化。根据模板特化的匹配规则我们知道，当模板实参是数组类型时，会匹配 #2 或 #3 这两个特化，当实参是非数组类型时，匹配主模板。其中，#2 匹配[不定长数组](https://link.zhihu.com/?target=https%3A//en.cppreference.com/w/c/language/array%23Variable-length_arrays)；#3 匹配[定长数组](https://link.zhihu.com/?target=https%3A//en.cppreference.com/w/c/language/array%23Arrays_of_constant_known_size)。整个递归的过程就是对维度做递归，每次递归 value + 1，就可以得到总维度。这里我们可以思考一个问题：对于 `int[5][6]`，毫无疑问会匹配到特化 `#3`，那么这时 #3 的两个参数 T 和 N 被推导为什么呢？是 `int[5]` 和 `6`，还是 `int[6]` 和 `5`？答案我不公布了，你可以尝试写代码来测试看看。

## 3.4.2 extent

extent 接受两个参数，一个数组 T 和一个值 N，它返回 T 的第 N 维的大小。

```cpp
std::cout << extent_v<int[3]> << std::endl;        // 3
std::cout << extent_v<int[3][4], 0> << std::endl;  // 3
std::cout << extent_v<int[3][4], 1> << std::endl;  // 4
std::cout << extent_v<int[3][4], 2> << std::endl;  // 0
std::cout << extent_v<int[]> << std::endl;         // 0


template<typename T, unsigned N = 0>
struct extent : integral_constant<std::size_t, 0> {};

template<typename T>
struct extent<T[], 0> : integral_constant<std::size_t, 0> {};

template<typename T, unsigned N>
struct extent<T[], N> : extent<T, N-1> {};

template<typename T, std::size_t I>
struct extent<T[I], 0> : integral_constant<std::size_t, I> {};

template<typename T, std::size_t I, unsigned N>
struct extent<T[I], N> : extent<T, N-1> {};
```

其实，看懂了 extent 的代码，你也就知道上面那个问题的答案了。extent 共有 4 个偏特化，前两个匹配不定长数组，后两个匹配定长数组，主模板匹配非数组类型。原理类似，我不赘述了。