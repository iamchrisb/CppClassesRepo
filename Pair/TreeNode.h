#ifndef TREENODE_H
#define TREENODE_H

namespace mystl {

    template <typename T, template<typename> class Order> class Tree;

    template<typename T , template<typename> class Order = Less >
    class TreeNode
    {
       friend class Tree<T , Order>;

    protected:
        TreeNode<T, Order>* m_left;
        TreeNode<T , Order>* m_right;
        TreeNode<T , Order>* m_up;

    private:
        T* m_value;

        TreeNode<T , Order>& findFirstRek(TreeNode<T , Order>& t){
            if(t->m_up == 0){
                return t;
            }else{
                return findFirstRek(t->m_up);
            }
        }

        TreeNode<T , Order>& findByValue(TreeNode<T , Order> tn, T value){
            if(tn.m_value < value){
                return findByValue(m_left , value);
            }else if(tn.m_value > value ){
                return findByValue(m_right , value);
            }else{
                return tn;
            }
        }

    public:
        T* value(){ return m_value; }
        void value(const T& value){ m_value = value;}
        TreeNode<T , Order>& find(const T&value){
            //TreeNode<int> ...
            return findByValue(this , value);
        }

        TreeNode<T , Order>& findFirst(){
            findFirstRek(this);
        }

        TreeNode<T , Order>& findLast(){

        }

        TreeNode(const T &value = 0):m_left(0), m_right(0),m_up(0), m_value(value)
        {
            printf("TreeNode Konstruktor");
        }

    };
}

#endif // TREENODE_H
