#ifndef TREEITERATOR_H
#define TREEITERATOR_H

//#include "TreeNode.h"

namespace mystl {

    template<typename T , template<typename> class Order = Less >
    class TreeIterator
    {
        typedef TreeNode<T,Order> node;
        typedef Tree<T,Order> tree;

        tree* m_tree;
        node* m_node;

    public:
        TreeIterator(node* treeNode):m_node(treeNode){}
        TreeIterator(){}
    };
}

#endif // TREEITERATOR_H
