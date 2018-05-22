#include "graph.h"


/*
*   public 函数
*/

template<typename V, typename W>
GraphLink<V, W>::GraphLink(const V* _vertex, size_t _size, bool _isDirected)
{
    // 开辟空间并初始化数据
    this->vertex.resize(_size);
    this->linkTable.resize(_size);
    this->isDirected = _isDirected;

    for (size_t i = 0; i < _size; i++)
    {
        this->vertex[i] = _vertex[i];
    }
}

template<typename V, typename W>
void GraphLink<V, W>::printEdge()
{
    for (size_t idx = 0; idx < vertex.size(); ++idx)
    {
        cout << vertex[idx] << ": ";

        node* pEdge = linkTable[idx];
        while (pEdge)
        {
            cout << pEdge->weight << "[" << vertex[pEdge->endIndex] << "]-->";
            pEdge = pEdge->nextNode;
        }
        cout << "NULL" << endl;
    }
    cout << endl;
}

template<typename V, typename W>
void GraphLink<V, W>::addEdge(const V& v1, const V& v2, const W& weight)
{
    size_t startIndex = getIndexOfVertex(v1);
    size_t endIndex   = getIndexOfVertex(v2);

    // 防止填加自己指向自己的边
    assert( startIndex!=endIndex);

    __addEdge(startIndex, endIndex, weight);

    // 无向图需要添加对称的一条边
    if (!isDirected)
        __addEdge(endIndex, startIndex, weight);

}



/*
*   private 函数
*/



template <typename V, typename W>
void GraphLink<V, W>::__addEdge(size_t startIndex, size_t endIndex, const W& weight)
{
    // 头插的方式添加边到链表中
    node* pNewEdge = new node(startIndex, endIndex, weight);
    pNewEdge->nextNode = linkTable[startIndex];
    linkTable[startIndex] = pNewEdge;
}

template<typename V, typename W>
size_t GraphLink<V, W>::getIndexOfVertex(const V& v)
{
    for (int idx = 0; idx < vertex.size(); idx++)
    {
        if (vertex[idx] == v)
            return idx;
    }

    // 如果没有找到就说明发生了错误
    assert(false);
    return -1;
}