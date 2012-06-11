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

        void deleteNode(node* tn){
            if(tn == m_root && m_root->m_left == 0 && m_root->m_right == 0){
                m_root=0;
            }else{
                node tmp = tn->findFirst();
                if(tmp.m_right != 0){
                    deleteNode(tmp.m_right);
                }else{
                    node* tmpup = tmp.m_up;
                    printf("deleting: %d", tmp.m_value);
                    tmp = 0;

                    deleteNode(tmpup);
                }
            }

        }

    public:

        Tree():
            m_root(0)
            {}

        iterator insert(const T& value){
            iterator it;
            if(m_root == 0){
                printf("m_root null\n");
                node* tmp = new node(value);
                m_root = tmp;
                node* n = tmp;
                iterator it(tmp);
                return it;
            }else{
                printf("m_root not null\n");
                node* tmp = m_root->find(value);
                iterator it(tmp);
                return it;
            }
        }

        void clear(){
            if(m_root!=0){
                deleteNode(&(m_root->findFirst()));
            }

        }
    };
}

#endif // TREE_H
