#ifndef TREENODE_H
#define TREENODE_H

namespace mystl {

    template <typename T, typename Order> class Tree;
    template <typename T, typename Order> class TreeIterator;

    template<typename T , typename Order = Less<T> >
    class TreeNode
    {
       typedef TreeNode<T,Order> node;

       friend class Tree<T , Order>;
       friend class TreeIterator<T, Order>;

    protected:
        TreeNode<T, Order>* m_left;
        TreeNode<T , Order>* m_right;
        TreeNode<T , Order>* m_up;

    private:
        Order m_order;
        T m_value;

        node* findRoot(node* t){
            if(t->m_up == 0){
                return t;
            }else{
                return findRoot(t->m_up);
            }
        }

        node* findLeft(node* t){
            if(t->m_left == 0){
                return t;
            }else{
                return findLeft(t->m_left);
            }
        }

        node* findRight(node* t){
            if(t->m_right == 0){
                return t;
            }else{
                return findRight(t->m_right);
            }
        }

        node* findByValue(node* tn,const T value){
            if(m_order(value , tn->m_value )){
                if(tn->m_left != 0){
                    return findByValue(tn->m_left , value);
                }else{
                    return 0;
                }
            }else if(m_order(tn->m_value , value )){
                if(tn->m_right != 0){
                    return findByValue(tn->m_right , value);
                }else{
                    return 0;
                }
            }else{
                return tn;
            }
        }

    public:
        T value(){ return m_value; }
        void value(const T& value){ m_value = value;}

        /**
          @param specific value for the tree
          @return a node pointer if found, else 0
        **/
        TreeNode<T , Order>* find(const T&value){
            return findByValue(this , value);
        }

        /**
          @return the last node on the left side
        **/
        TreeNode<T , Order>* findFirst(){
            node* tmp = findRoot(this);
            return findLeft(tmp);
        }

        /**
          @return the last node on the right side
        **/
        TreeNode<T , Order>* findLast(){
            node* tmp = findRoot(this);
            return findRight(tmp);
        }

        TreeNode(const T &value = 0):m_left(0), m_right(0),m_up(0), m_value(value)
        {}
    };
}

#endif // TREENODE_H
