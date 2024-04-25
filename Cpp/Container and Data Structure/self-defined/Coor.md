#Snippet 

# 坐标类模板

> 这段代码定义了一个名为 `Coor` 的 [[类模板]]，该类表示一个二维坐标。这个类有两个私有成员变量 `x` 和 `y`，分别表示坐标的 $x$ 和 $y$ 值。

```Cpp,nums,{15-29}
template <typename coor_t>
class Coor
{
private:
	coor_t x, y;

public:
	static const int INF = INT_MAX;
	static const int NINF = INT_MIN;

	explicit Coor(coor_t a=0, coor_t b=0) : x(a), y(b) {}
	Coor(const Coor<coor_t>& rhs) : x(rhs.x), y(rhs.y) {}
	virtual ~Coor() {}

	// setter
    void set(coor_t a=0, coor_t b=0);
    void setX(coor_t new_x);
    void setY(coor_t new_y);
	// getter
	coor_t getX() const;
	coor_t getY() const;
	// add value
	void addToX(coor_t value);
	void addToY(coor_t value);

	Coor& operator-= (const Coor<coor_t>& right);
	Coor& operator+= (const Coor<coor_t>& right);
    Coor& operator+= (const coor_t& value);
	Coor& operator-= (const coor_t& value);
};
```

类中定义了一些公有成员函数，包括：
- `set(coor_t a=0, coor_t b=0)`：设置 $x$ 和 $y$ 的值。
- `setX(coor_t new_x)` 和 `setY(coor_t new_y)`：分别设置 $x$ 和 $y$ 的值。
- `getX()` 和 `getY()`：分别获取 $x$ 和 $y$ 的值。
- `addToX(coor_t value)` 和 `addToY(coor_t value)`：分别给 $x$ 和 $y$ 增加一个值。
- `operator-=` 和 `operator+=`：重载了减法和加法运算符，用于坐标的减法和加法运算，进一步参考 [[Coor#运算符 `+=`/ `-=`]]

在函数 `getX()` 和 `getY()` 后面的 `const` 关键字表示这两个函数是常量成员函数，它们不会修改类的任何成员变量。这意味着你可以在一个常量 `Coor` 对象上调用这两个函数。

## 关于构造函数、析构函数

```cpp,nums
explicit Coor(coor_t a=0, coor_t b=0) : x(a), y(b) {}
Coor(const Coor<coor_t>& rhs) : x(rhs.x), y(rhs.y) {}
virtual ~Coor() {}
```

- 构造函数参考 [[C++ 初始化#Initializer List]]：
	- `explicit Coor(coor_t a=0, coor_t b=0) : x(a), y(b) {}` 参考 [[explicit 那些事]]
	- `Coor(const Coor<coor_t>& rhs) : x(rhs.x), y(rhs.y) {}` 则使用对象引用作为函数参数
- `virtual ~Coor() {}` 参考 [[virtual那些事#析构函数可以为虚函数吗 ？]]

## 运算符 `+=`/ `-=`

> 参考 [[引用返回#用于运算符重载]]

For example, if `c1` and `c2` are `Coor` objects, and `v` is a `coor_t` object, then the following code snippets demonstrate the usage of these overloaded operators:
```cpp
c1 += c2; // equivalent to c1 = c1 + c2;
c1 -= c2; // equivalent to c1 = c1 - c2;
c1 += v;  // equivalent to c1 = c1 + v;
c1 -= v;  // equivalent to c1 = c1 - v;
```

## Detail

```cpp
template <typename coor_t>
void Coor<coor_t>::set(coor_t a, coor_t b ) { x = a, y = b; }

template <typename coor_t>
void Coor<coor_t>::setX(coor_t new_x) { x = new_x; }

template <typename coor_t>
void Coor<coor_t>::setY(coor_t new_y) { y = new_y; }

template <typename coor_t>
coor_t Coor<coor_t>::getX() const { return x; } //! const 置于函数后侧是什么意思

template <typename coor_t>
coor_t Coor<coor_t>::getY() const { return y; }

template <typename coor_t>
void Coor<coor_t>::addToX(coor_t value) { x += value; }

template <typename coor_t>
void Coor<coor_t>::addToY(coor_t value) { y += value; }

template <typename coor_t>
Coor<coor_t>& Coor<coor_t>::operator-= (const Coor<coor_t>& right)
{
	this->x -= right.x;
	this->y -= right.y;
	return *this;
}

template <typename coor_t>
Coor<coor_t>& Coor<coor_t>::operator+= (const Coor<coor_t>& right)
{
	this->x += right.x;
	this->y += right.y;
	return *this;
}

template <typename coor_t>
Coor<coor_t>& Coor<coor_t>::operator+= (const coor_t& value)
{
	this->x += value;
	this->y += value;
	return *this;
}

template <typename coor_t>
Coor<coor_t>& Coor<coor_t>::operator-= (const coor_t& value)
{
	this->x -= value;
	this->y -= value;
	return *this;
}
```

# Operator overloading

Reference  —— [[运算符重载]]

## Stream operator `<<`

```cpp
/** overload stream operator for Coor **/
template <typename coor_t>
std::ostream& operator<< (std::ostream &out, const Coor<coor_t> &coor)
{
#if log
	std::cout << "You are using the operator<< overload" << std::endl;
#endif
	out << '(';
	if(coor.getX() == Coor<coor_t>::INF) out << "inf";
	else if(coor.getX() == Coor<coor_t>::NINF) out << "-inf";
	else out << coor.getX();
	out << ", ";
	if(coor.getY() == Coor<coor_t>::INF) out << "inf";
	else if(coor.getY() == Coor<coor_t>::NINF) out << "-inf";
	else out << coor.getY();
	out << ')';
	return out;
}
```

## `+`/ `-`

注意到参与 `+`/ `-`  运算符的两个 item 存在如下可能情况：
- 运算符内部实现则依赖于 [[Coor#运算符 `+=`/ `-=`]]
- 两个 item 均为 `Coor` 模板类的对象引用，对应 [[Coor#Part I of `+`/ `-`]]
- 一个 item 为`Coor` 模板类的对象引用，一个 item 为`Coor` 模板类的对象右值引用，对应 [[Coor#Part II of `+`/ `-`]]
- 一个 item 为`Coor` 模板类的对象引用，一个 item 是常规的标量值，对应 [[Coor#Part III of `+`/ `-`]]
- 一个 item 为`Coor` 模板类的对象右值引用，一个 item 是常规的标量值，对应 [[Coor#Part IV of `+`/ `-`]]

### Part I of  `+`/ `-`

```cpp
Coor<int> a(1, 2);
Coor<int> b(3, 4);

Coor<int> c = a + b;
Coor<int> d = a - b;
```

其中 `a` 称为运算符的 `lhs`，`b` 称为运算符的 `rhs`

```cpp
template <typename coor_t>
inline Coor<coor_t> operator- (const Coor<coor_t>& lhs, const Coor<coor_t>& rhs)
{
#if log
	std::cout << "You are using the operator- overload" << std::endl;
#endif
	Coor<coor_t> temp(lhs);
	temp -= rhs;
	return temp;
}


template <typename coor_t>
inline Coor<coor_t> operator+ (const Coor<coor_t>& lhs, const Coor<coor_t>& rhs)
{
#if log
	std::cout << "You are using the operator+ overload" << std::endl;
#endif
	Coor<coor_t> temp(lhs);
	temp += rhs;
	return temp;
}
```

### Part II of `+`/ `-`

```cpp
template <typename coor_t>
inline Coor<coor_t> operator- (Coor<coor_t>&& lhs, const Coor<coor_t>& rhs)
{
#if log
	std::cout << "You area using the operator- overload with rvalue reference" << std::endl;
#endif
	lhs -= rhs;
	return lhs;
}


template <typename coor_t>
inline Coor<coor_t> operator+ (Coor<coor_t>&& lhs, const Coor<coor_t>& rhs)
{
#if log
	std::cout << "You area using the operator+ overload with rvalue reference" << std::endl;
#endif
	lhs += rhs;
	return lhs;
}
```

### Part III of `+`/ `-`

```cpp
template <typename coor_t>
inline Coor<coor_t> operator- (const Coor<coor_t>& lhs, const coor_t& val)
{	
#if log
	std::cout << "You are using the operator- overload with scalar value" << std::endl;
#endif
	Coor<coor_t> temp(lhs);
	temp -= val;
	return temp;
}

template <typename coor_t>
inline Coor<coor_t> operator+ (const Coor<coor_t>& lhs, const coor_t& val)
{	
#if log
	std::cout << "You are using the operator+ overload with scalar value" << std::endl;
#endif
	Coor<coor_t> temp(lhs);
	temp += val;
	return temp;
}
```

### Part IV of `+`/ `-`

```cpp
template <typename coor_t>
inline Coor<coor_t> operator- (Coor<coor_t>&& lhs, const coor_t& rhs)
{	
#if log
	std::cout << "You are using the operator- overload with scalar value and rvalue reference" << std::endl;
#endif
	lhs -= rhs;
	return lhs;
}

template <typename coor_t>
inline Coor<coor_t> operator+ (Coor<coor_t>&& lhs, const coor_t& rhs)
{	
#if log
	std::cout << "You are using the operator+ overload with scalar value and rvalue reference" << std::endl;
#endif
	lhs += rhs;
	return lhs;
}
```

## `<`

```cpp
template <typename coor_t>
inline bool operator< (const Coor<coor_t>& lhs, const Coor<coor_t>& rhs)
{
#if log
	std::cout << "You are using the operator< overload" << std::endl;
#endif
    return ((lhs.getX() < rhs.getX()) && (lhs.getY() < rhs.getY()));
}
```

## `>`

```cpp
template <typename coor_t>
inline bool operator> (const Coor<coor_t>& lhs, const Coor<coor_t>& rhs)
{
#if log
	std::cout << "You are using the operator> overload" << std::endl;
#endif 

    return ((lhs.getX() > rhs.getX()) && (lhs.getY() > rhs.getY()));
}
```

## `==`

```cpp
template <typename coor_t>
inline bool operator== (const Coor<coor_t>& lhs, const Coor<coor_t>& rhs)
{
#if log
	std::cout << "You are using the operator== overload" << std::endl;
#endif

	if(lhs.getX() != rhs.getX()) { return false; }
	if(lhs.getY() != rhs.getY()) { return false; }
	return true;
}
```

## `!=`

```cpp
template <typename coor_t>
inline bool operator!= (const Coor<coor_t>& lhs, const Coor<coor_t>& rhs)
{
#if log
	std::cout << "You are using the operator!= overload" << std::endl;
#endif
	if(lhs == rhs) return false;
	return true;
}
```

# 其他

## isLeft

```cpp
/************************************************
 * isLef() operation
*/
template <typename T>
double isLeft(Coor<T> a, Coor<T> b, Coor<T> c){
	return (b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (b.getY() - a.getY());
}
```