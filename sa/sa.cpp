#include <iostream>
template<class T>
struct node {
    T _data;
    struct node<T>* _prev;
    node<T>(T data, node<T>* ptr = nullptr) {
        _data = data;
        _prev = ptr;
    }
    
};

template<class T>
class Stack {
private:
    node<T>* Head;
    int _numOfElements;
public:
    Stack() {
        Head = nullptr;
        _numOfElements = 0;
    }
    Stack(T data) {
        Head = new node<T>(data);
        _numOfElements = 1;
    }
    void push(T data) {
        Head = new node<T>(data, Head);
        _numOfElements++;
    }
    void output() {
        auto iterator = Head;
        if (iterator != nullptr) {
            std::cout << iterator->_data << " ";
            while (iterator->_prev != nullptr) {
                iterator = iterator->_prev;
                std::cout << iterator->_data << " ";
            }
        }
        std::cout << "\n\n";
    }
    void pop() {
        if (Head != nullptr) {
            auto temp = Head;
            Head = Head->_prev;
            _numOfElements--;
            delete temp;
        }
        else {
            throw std::out_of_range("Sorry, the stack is empty, nothing to pop.");
        }
    }
    ~Stack() {
        while (Head != nullptr) this->pop();
    }
    Stack(const Stack& st) {
        int tmp = st._numOfElements;
        if (st._numOfElements != 0) {
            while (tmp != 0) {
                auto iterator = st.Head;
                for (int i = 0; i < tmp-1; ++i) {
                    iterator = iterator->_prev;
                }
                this->push(iterator->_data);
                tmp--;
            }
        }
        else {
            throw std::invalid_argument("The copied stack is empty...");
        }
    }
    int size() {
        return _numOfElements;
    }
    bool empty() {
        return Head == nullptr && _numOfElements == 0;
    }
    T& top() {
        if (Head != nullptr) {
            return Head->_data;
        }
        else throw std::invalid_argument("The stack is empty...");
    }
    Stack& operator=(const Stack& st) {
        while (Head != nullptr) this->pop();
        int tmp = st._numOfElements;
        if (st._numOfElements != 0) {
            while (tmp != 0) {
                auto iterator = st.Head;
                for (int i = 0; i < tmp - 1; ++i) {
                    iterator = iterator->_prev;
                }
                this->push(iterator->_data);
                tmp--;
            }
        }
        else {
            throw std::invalid_argument("The copied stack is empty...");
        }
    }
};

int main()
{
    try {
        // Your code...
    }
    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
