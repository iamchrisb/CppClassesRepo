#ifndef TREEITERATOR_H
#define TREEITERATOR_H

//#include "TreeNode.h"

namespace mystl {

    template<typename T , template<typename> class Order = Less >
    class TreeIterator
    {
        typedef TreeNode<T,Order> node;
        typedef Tree<T,Order> tree;
        Order<T> m_order;
        tree* m_tree;
        node* m_node;
    private:
        node* getLeftSize(node* n){
            if(n.m_left == 0){
                return n;
            }else{
                return getLeftSize(n.m_left);
            }
        }
        node* getRightSize(node* n){
            if(n.m_right == 0){
                return n;
            }else{
                return getRightSize(n.m_right);
            }
        }
        node* getUpSize(node* n){
            if(m_order(n.m_up.m_value, n.m_value)){
                return n.m_up;
            }else{
                getUpSize(n.m_up);
            }
        }

    public:
        TreeIterator(node* treeNode):m_node(treeNode){}
        TreeIterator(node* treeNode=0, tree* t=0):m_node(treeNode),m_tree(t){}
        TreeIterator(){}

        T& operator*(){
            return m_node->m_value;
        }

        T* operator->(){
            return *(m_node->m_value);
        }

        TreeIterator<T,Order>& operator++(){
                //if(wenn order greater order einsetzen){
                // this.--;
                //}else{
                if(m_node->m_right != 0){
                    m_node = getNextBigger(m_node->m_right);
                    return *this;
                }else{
                    if(m_node == m_tree->m_root){
                        m_node = m_tree->m_root;
                        return 0;
                    }
                    m_node = getUpSize(m_node);
                    return *this;
                }
            //}
        }

        TreeIterator<T,Order>& operator--(){

            //if(wenn order greater order einsetzen){
            // this.++;
            //}else{
                if(m_node->m_left != 0){
                    m_node = getNextSmaller(m_node->m_left);
                    return *this;
                }else{
                    if(m_node == m_tree->m_root){
                        m_node = m_tree->m_root;
                        return 0;
                    }
                    m_node = getUpSize(m_node);
                    return *this;
                }
            //}
        }

        bool operator==(const TreeIterator<T,Order> &rhs){
            return (m_tree == rhs.m_tree && m_node == rhs.m_node);
        }
        bool operator!=(const TreeIterator<T,Order> &rhs){
            return (m_tree != rhs.m_tree && m_node != rhs.m_node);
        }
    };
}

#endif // TREEITERATOR_H
