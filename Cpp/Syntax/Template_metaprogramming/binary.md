# binary

```cpp
template <int N>
struct binary {
  static constexpr int value = binary<N / 10>::value << 1 | N % 10;
};

template <>
struct binary<0> {
  static constexpr int value = 0;
};
```

在上面的代码中，我们先是定义了一个名为 `binary` 的模板，然后定义了一个 `binary` 的特化 (Specialization)，这里可以将它理解为当 `N==0` 时对应的特殊版本。利用这段代码，我们可以*在编译期计算出一个二进制数对应的十进制值*：

```cpp
std::cout << binary<101>::value << std::endl;       // Equivalent to: std::cout << 5 << std::endl;
std::cout << binary<1110>::value << std::endl;      // Equivalent to: std::cout << 14 << std::endl;
std::cout << binary<10110>::value << std::endl;     // Equivalent to: std::cout << 22 << std::endl;
```

> 上述代码可以总结为`binary<x>::value` 在编译期就会被求值，得到一个*常量*，可以通过 [[binary.cpp]] 进行验证

对模板不熟悉的读者可能会对这一点产生怀疑，我们可以用下面的代码来*证明 `binary<x>::value` 是一个常量*，如果不是，那么这句话在编译时就会报错，因为 C++ 要求在编译时就确定静态数组的长度。（在 C++ 中，如果一个东西的名字里包含 `static`，那么它大概率是编译期就决定的东西，如 `static_assert`，`static_cast`；同样的，`dynamic `通常意味着运行时才确定的事物，如 `dynamic_cast`, `dynamic_link`）

```cpp
static char array[binary<101>::value];     // Equivalent to: static char array[5]
```

# Review of binary

```cpp
// primary template
template <int N>  // non-type parameter N
struct binary {
  // an template instantiation inside the template itself, which contructs a recursion
  static constexpr int value = binary<N / 10>::value << 1 | N % 10;
  // 等价于
  //static constexpr int value = ((binary<N / 10>::value) << 1) | (N % 10);
};
// full specialization when N == 0
template <> struct binary<0> {
  static constexpr int value = 0;
};

std::cout << binary<101>::value << std::endl;    // instantiation
```

- 在上面的代码中，我们定义了一个主模板 `binary`，它接受一个非类型形参，更具体地说是一个 `int` 类型的形参。
- 同时，我们定义了一个 `binary` 的特化，它是模板 `binary` 在 `N == 0` 时的一个全特化，在实例化 `binary<0>` 时，编译器会为我们匹配这一个特化。
- 在主模板中，我们定义了一个静态常量 `value`，并将它初始化为 `binary<N / 10>::value << 1 | N % 10`，由于静态常量会在编译期求值，所以编译器在实例化 `binary<101>` 时会尝试求值（Evaluate）这个表达式。这个表达式中包含了一个对 `binary` 的另一个实例化，所以编译器会*递归/[[递归]]地实例化 `binary` 这个模板*。递归的过程如下：

| N   | instantiation | matches        | recursion                    | value |
| --- | ------------- | -------------- | ---------------------------- | ----- |
| 101 | `binary<101>` | primary        | `binary<10>::value << 1 丨 1` | 5     |
| 10  | `binary<10>`  | primary        | `binary<1>::value << 1 丨 0`  | 2     |
| 1   | `binary<1>`   | primary        | `binary<0>::value << 1 丨 1`  | 1     |
| 0   | `binary<1>`   | specialization | 0                            | 0     |

直到 `N == 0` 时，模板的实例化匹配到特化版本，在这个特化中，也定义了一个静态常量 `value = 0`，递归到这里终止，被求值的表达式层层返回，最终计算出 `binary<101>::value = 5`。