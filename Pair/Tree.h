#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include "TreeIterator.h"
#include "stdio.h"

namespace mystl {
    template<typename T , template<typename> class Order = Less >
    class Tree
    {
        typedef TreeNode<T,Order> node;
        typedef TreeIterator<T, Order> iterator;

    private:
        Order<T> m_order;
        node* m_root;

    public:

        iterator getIt(){
//            iterator it = new iterator(this->m_root);
            return TreeIterator<T , Order>();
        }

        Tree():
            m_root(0)
            {}

        iterator insert(const T& value);
    };

    template<typename T , template<typename> class Order >
    TreeIterator<T,Order> Tree<T,Order>::insert(const T& value){
        iterator it;
        if(m_root == 0){
            printf("m_root null\n");
            node* tmp = new node(value);
            m_root = tmp;
            node* n = tmp;
            iterator it (n);
            return new iterator(n);
        }else{
            printf("m_root not null\n");
            node* tmp = m_root->find(value);
            return new iterator(tmp);
        }
    }

}

#endif // TREE_H
