#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

// W -- 边对应权值的类型
template <typename W>
struct EdgeNode
{
    W weight;  // 边所对应权值
    size_t startIndex;  // 边起点的索引
    size_t   endIndex;  // 边终点的索引
    EdgeNode<W>*   nextNode;  // 指向下个结点
    EdgeNode(size_t start, size_t end, const W& _weight)
        : startIndex(start)
        , endIndex(end)
        , weight(_weight)
    {}
};

// V -- 图顶点的数据类型
// W -- 图边权值的类型
template <typename V, typename W>
class GraphLink
{
public:
    typedef EdgeNode<W> node;

    GraphLink(const V* _vertex, size_t _size, bool _isDirected = false);
    // 打印图中的边
    void printEdge();
    // 向图中添加一条边
    void addEdge(const V& v1, const V& v2, const W& weight);

private:
    // 获取顶点所在索引
    size_t getIndexOfVertex(const V& v);
    // 添加一条边
    void __addEdge(size_t startIndex, size_t endIndex, const W& weight);

private:
    bool         isDirected; 
    vector<V>        vertex; // 存储所有顶点
    vector<node*> linkTable; // 存储顶点的边
};


#endif //GRAPH_H