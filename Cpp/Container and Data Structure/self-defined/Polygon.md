#Snippet 

> 在 [[Coor#坐标类模板]] 的基础上，可以自然地设计出多边形类模板 —— 我们还引入了 `edge` 类模板

# edge 结构模板

```cpp
template <typename T>
struct edge
{
    std::pair< Coor<T>, Coor<T> > Coor_pair;
    edge(const Coor<T>& a, const Coor<T>& b) : Coor_pair(a, b) {}
};
```

# 多边形结构模板

多边形结构模板主要由两个内容构成：
- 由 [[Coor]] 类模板表征的顶点（vertex）构成的 vector `vertexes`
- 由 edge 结构模板表征的边（edge）构成的 vector `edges`

```cpp
template <typename T>
struct Polygon
{   
    // vertexes set of the polygon
    std::vector<Coor<T>> vertexes;
    // edges set of the polygon
    std::vector<edge<T>> edges;

    void edges_init(); // according to vertexes, initialize edges
    void vertexes_init(); // according to edges, initialize vertexes
    bool isInside(Coor<T> point); // check if the point is inside the polygon based on the Winding Number Algorithm
};
```

## 实际重用如何构造

参考如下 demo：
```cpp,nums,{2,7}
Polygon<int> poly;
poly.vertexes.push_back(Coor<int>(0, 0));
poly.vertexes.push_back(Coor<int>(1, 0));
poly.vertexes.push_back(Coor<int>(2, 0));
poly.vertexes.push_back(Coor<int>(2, 2));
poly.vertexes.push_back(Coor<int>(0, 2));
poly.vertexes.push_back(Coor<int>(0, 0));
```

> 要求输入的顶点序列是要闭合的，对应 line 2，7

## 初始化

> 由于 vertex 与 edge 并非独立，可以基于其中一方得到另一方面，故有设计了 `edges_init（）` 与 `vertexes_init()` 函数

```cpp
template <typename T>
void Polygon<T>::edges_init()
{
    edges.clear();
    auto vertex = vertexes.begin();
    for(; vertex != (vertexes.end()-1); vertex++){
        edges.push_back(edge<T>(*vertex, *(vertex+1)));
    } 
}
```

```cpp
template <typename T>
void Polygon<T>::vertexes_init()
{
    vertexes.clear();
    auto edge = edges.begin();
    for(; edge != edges.end(); edge++){
        vertexes.push_back(edge->Coor_pair.first);
    }
    vertexes.push_back(edges.back().Coor_pair.second);
}
```

## isInside

> 考虑一个常见的问题：给定一个多边形与平面上某点的坐标，试问该点是否位于多形形的内部 ？ —— `isInside` 函数的主要任务便是进行上述判定，`isInside`函数是一个用于判断一个点是否在多边形内部的函数。它使用了所谓的“绕数”（winding number）算法 / [[绕数算法]]

- 这个函数首先初始化一个名为`windingNumber`的变量，这个变量将用于记录点相对于多边形的“绕数”。
- 然后，函数遍历多边形的每条边。对于每条边，它首先检查边的起点是否在点的下方。如果是，它再检查边的终点是否在点的上方。如果两者都是真的，那么它会检查点是否在边的左边。如果点在边的左边，`windingNumber`就会增加1。
- 如果边的起点在点的上方，函数会检查边的终点是否在点的下方。如果是，它会检查点是否在边的右边。如果点在边的右边，`windingNumber`就会减少1。
- 然后，函数计算点与边形成的三角形的面积。如果面积为0，说明点在边上，函数立即返回`true`。
- 最后，如果遍历完所有的边，`windingNumber`不为0，说明点在多边形内部，函数返回`true`。否则，返回`false`，表示点不在多边形内部

```cpp
template <typename T>
bool Polygon<T>::isInside(Coor<T> point)
{
    int windingNumber = 0;

    for(int i=0; i<vertexes.size()-1; i++){
        if(vertexes[i].getY() <= point.getY()){
            if(vertexes[(i+1) % vertexes.size()].getY() > point.getY()){
                if(isLeft(vertexes[i], vertexes[(i+1) % vertexes.size()], point) > 0)
                    windingNumber++;
            }
        }
        else{
            if(vertexes[(i+1) % vertexes.size()].getY() <= point.getY()){
                if(isLeft(vertexes[i], vertexes[(i+1) % vertexes.size()], point) < 0)
                    windingNumber--;
            }
        }

        double area = triangleArea(vertexes[i], vertexes[(i+1) % vertexes.size()], point);
        if(area == 0){
            return true;
        }
    }
    
    return windingNumber != 0;
}
```

```cpp
// Calculate the area of a triangle formed by three points
template <typename T>
double triangleArea(const Coor<T>& p1, const Coor<T>& p2, const Coor<T>& p3) {
    // calculate the area of a triangle
    return 0.5 * (p1.getX() * p2.getY() + p2.getX() * p3.getY() + p3.getX() * p1.getY() - p1.getX() * p3.getY() - p2.getX() * p1.getY() - p3.getX() * p2.getY());
}
```