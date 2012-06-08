#ifndef TREEITERATOR_H
#define TREEITERATOR_H

namespace mystl {

    template<typename T , template<typename> class Order = Less >
    class TreeIterator
    {
        T* m_tree;
        T* m_node;
    };
}

#endif // TREEITERATOR_H
