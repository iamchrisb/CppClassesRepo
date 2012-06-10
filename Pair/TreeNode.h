#ifndef TREENODE_H
#define TREENODE_H

namespace mystl {

    template <typename T, template<typename> class Order> class Tree;
    template <typename T, template<typename> class Order> class TreeIterator;

    template<typename T , template<typename> class Order = Less >
    class TreeNode
    {
       typedef TreeNode<T,Order> node;

       friend class Tree<T , Order>;

    protected:
        TreeNode<T, Order>* m_left;
        TreeNode<T , Order>* m_right;
        TreeNode<T , Order>* m_up;

    private:
        Order<T> m_order;
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
            if(value < tn->m_value ){
                if(tn->m_left != 0){
                    printf("REK LEFT | value: %d | tn->m_value: %d \n" , value , tn->m_value);
                    return findByValue(tn->m_left , value);
                }else{
                    printf("NOT REK LEFT | value: %d | tn->m_value %d \n" , value , tn->m_value);
                    node* tmp = new node(value);
                    tn->m_left = tmp;
                    return tmp;
                }
            }else if(tn->m_value < value ){
                if(tn->m_right != 0){
                    printf("rek right \n");
                    return findByValue(tn->m_right , value);
                }else{
                    printf("not rek right \n");
                    node * tmp = new node(value);
                    tn->m_right = tmp;
                    return tmp;
                }
            }else{
                printf("the same\n");
                return tn;
            }
        }

    public:
        T* value(){ return m_value; }
        void value(const T& value){ m_value = value;}
        TreeNode<T , Order>* find(const T&value){
            return findByValue(this , value);
        }

        TreeNode<T , Order>& findFirst(){
            node* tmp = findRoot(this);
            return findLeft(tmp);
        }

        TreeNode<T , Order>& findLast(){
            node* tmp = findRoot(this);
            return findRight(tmp);
        }

        TreeNode(const T &value = 0):m_left(0), m_right(0),m_up(0), m_value(value)
        {}
    };
}

#endif // TREENODE_H
