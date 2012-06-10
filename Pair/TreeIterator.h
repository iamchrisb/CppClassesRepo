#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "TreeNode.h"
#include "TreeIterator.h"

namespace mystl {

    template<typename T , template<typename> class Order = Less >
    class TreeIterator
    {
        typedef TreeNode<T,Order> node;
        T* m_tree;
        node* m_node;

    public:
        TreeIterator(node* treeNode);
    };
}

#endif // TREEITERATOR_H
