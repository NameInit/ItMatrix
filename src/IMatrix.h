#ifndef IMATRIX_H
#define IMATRIX_H

#include <iostream>
#include <stdexcept>

template <typename ItemType>
class IMatrix {
    protected:
        unsigned _row;
        unsigned _col;
    public:
        IMatrix() : _row(0), _col(0) {}
        IMatrix(int,int);
        virtual ~IMatrix() {}

        virtual ItemType& operator()(int,int)=0;
        virtual const ItemType& operator()(int,int) const=0;
        virtual ItemType* operator[](int)=0;
        virtual const ItemType* operator[](int) const =0;
};

template <typename ItemType>
IMatrix<ItemType>::IMatrix(int row, int col) {
    if (row < 0 || col < 0)
        throw std::invalid_argument("negative len matrix");
    this->_row = row;
    this->_col = col;
}

#endif