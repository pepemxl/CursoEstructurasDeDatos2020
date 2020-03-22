#ifndef _CStack_h_
#define _CStack_h_


template <typename T>
struct Node{
    T data;
    Node<T> *next;
    Node();
    Node(const T &val);
    ~Node();
};

template<typename T>
class CStack{
private:
    Node<T> *ptrHead;
    int top;
public:
    CStack();
    ~CStack();
    bool Push(const T &val);
    T Pop();
    bool Pop(T &val);
    bool Peek(T &val);
    bool Print();
    bool Clear();
};


#endif