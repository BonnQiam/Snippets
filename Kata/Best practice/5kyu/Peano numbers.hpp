// 这段代码定义了一种用于表示皮亚诺数（Peano numbers）的C++模板元编程结构
// 这段代码通过C++的模板元编程和继承机制，建立了一个用于表示和操作皮亚诺数的类型系统。通过这种方式，可以在编译时进行数学运算和逻辑判断，而不是在运行时。

struct Peano {
};

// inherit from Peano
struct Zero: Peano {
    static constexpr int value = 0;
};

// inherit from Peano
template<class T>
struct Succ: Peano {
    static constexpr int value = T::value + 1;
};

struct Error {};
struct NoError : Error {};
struct Negative : Error {};
struct Infinity : Error {};

struct Ordreing {};
struct EQ: Ordreing {};
struct GT: Ordreing {};
struct LT: Ordreing {};

struct Bool {};
struct True: Bool {};
struct False: Bool {};

// Above are preloaded.

// Addition
template<typename A, typename B>
struct Add;

template<typename B>
struct Add<Zero, B> {
    using type = B;
};

template<typename A, typename B>
struct Add<Succ<A>, B> {
    using type = Succ<typename Add<A, B>::type>;
};

// Subtraction
template<typename A, typename B>
struct Sub;

template<typename A>
struct Sub<A, Zero> {
    using type = A;
};

//template<typename A, typename B>
template<typename B>
struct Sub<Zero, Succ<B>> {
    using type = Negative; // Error: Negative result
};

template<typename A, typename B>
struct Sub<Succ<A>, Succ<B>> {
    using type = typename Sub<A, B>::type;
};

// Multiplication
template<typename A, typename B>
struct Mul;

template<typename B>
struct Mul<Zero, B> {
    using type = Zero;
};

template<typename A, typename B>
struct Mul<Succ<A>, B> {
    using type = typename Add<B, typename Mul<A, B>::type>::type;
};

// Division (Helper to handle division)
template<typename A, typename B>
struct DivHelper;

template<typename A>
struct DivHelper<A, Zero> {
    using type = Infinity; // Error: Division by zero
};

template<typename A>
struct DivHelper<Zero, A> {
    using type = Zero;
};

template<typename A, typename B>
struct DivHelper {
    using type = typename std::conditional_t<
        std::is_same<A, Zero>::value || std::is_same<Succ<B>, Zero>::value,
        Zero,
        Succ<typename DivHelper<typename Sub<A, B>::type, B>::type>
    >;
};

// Division
template<typename A, typename B>
struct Div {
    using type = typename DivHelper<A, B>::type;
};

// Even
template<typename A>
struct Even;

template<>
struct Even<Zero> {
    using type = True;
};

template<typename A>
struct Even<Succ<A>> {
    using type = typename Even<typename Sub<Succ<A>, Succ<Succ<Zero>>>::type>::type;
};

// Odd
template<typename A>
struct Odd;

template<>
struct Odd<Zero> {
    using type = False;
};

template<typename A>
struct Odd<Succ<A>> {
    using type = typename Odd<typename Sub<Succ<A>, Succ<Succ<Zero>>>::type>::type;
};

// Comparison
template<typename A, typename B>
struct Compare;

template<>
struct Compare<Zero, Zero> {
    using type = EQ;
};

template<typename B>
struct Compare<Zero, Succ<B>> {
    using type = LT;
};

template<typename A>
struct Compare<Succ<A>, Zero> {
    using type = GT;
};

template<typename A, typename B>
struct Compare<Succ<A>, Succ<B>> {
    using type = typename Compare<A, B>::type;
};
