#ifndef INTVECTOR_H
#define INTVECTOR_H

using namespace std;

class IntVector{
    private:
        unsigned _size;
        unsigned _capacity;
        int *_data;
        void expand();
        void expand(unsigned amount);
    
    public:
        IntVector();
        IntVector(int size);
        IntVector(unsigned capacity, int value);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;
        void insert(unsigned index, int value);
        void erase(unsigned index);
        void push_back(int value);
        void pop_back();
        void clear();
        void resize(unsigned size, int value = 0);
        void reserve(unsigned n);
        void assign(unsigned n, int value);
        int & at(unsigned index);
        int & front();
        int & back();        

};
#endif