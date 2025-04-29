#ifndef MATRIX_H
#define MATRIX_H

#include "IMatrix.h"
#include "logic_iteration.h"
#include <iostream>
#include <stdio.h>

template <typename ItemType>
class Matrix : public IMatrix<ItemType> {
    private:
        ItemType** data=nullptr;
    public:
        Matrix() : IMatrix<ItemType>() {}
        Matrix(int,int);
        Matrix(const Matrix<ItemType>&);
        Matrix<ItemType>& operator=(const Matrix<ItemType>&);
        ~Matrix();

        ItemType& operator()(int,int);
        const ItemType& operator()(int,int) const;
        ItemType* operator[](int);
        const ItemType* operator[](int) const;

        class Iterator {
            private:
                Matrix<ItemType>* matrix;
                unsigned num_item;
                unsigned __GetIndRow(){
                    return GetIndRowCol(num_item,matrix->_row,matrix->_col)[0];
                }
                unsigned __GetIndCol(){
                    return GetIndRowCol(num_item,matrix->_row,matrix->_col)[1];
                }
            public:
                using value_type = ItemType;
                using difference_type = std::ptrdiff_t;
                using pointer = ItemType*;
                using reference = ItemType&;
                using iterator_category = std::random_access_iterator_tag;
                
                Iterator(Matrix<ItemType>* matr) : matrix(matr), num_item(0) {}
                Iterator(Matrix<ItemType>* matr, unsigned n) : matrix(matr), num_item(n) {}
                
                reference operator*(){
                    return (*matrix)(__GetIndRow(),__GetIndCol());
                }

                Iterator& operator++(){
                    ++num_item;
                    return *this;
                }

                Iterator operator++(int){
                    Iterator temp=*this;
                    ++num_item;
                    return temp;
                }

                Iterator& operator--(){
                    --num_item;
                    return *this;
                }

                Iterator operator--(int){
                    Iterator temp=*this;
                    --num_item;
                    return temp;
                }

                difference_type operator-(const Iterator& other){
                    return num_item-other.num_item;
                }

                Iterator operator+(int n) const {
                    return Iterator(matrix, num_item+n);
                }

                Iterator& operator+=(int n) {
                    num_item+=n;
                    return *this;
                }

                Iterator operator-(int n) const {
                    return Iterator(matrix, num_item-n);
                }

                Iterator& operator-=(int n) {
                    num_item-=n;
                    return *this;
                }

                reference operator[](int n){
                    num_item=n;
                    return (*matrix)(__GetIndRow(),__GetIndCol());
                }

                bool operator!=(const Iterator& other) const {
                    return matrix!=other.matrix || num_item!=other.num_item;
                }

                bool operator==(const Iterator& other) const {
                    return matrix==other.matrix && num_item==other.num_item;
                }

                bool operator<(const Iterator& other) const {
                    if (matrix!=other.matrix){
                        throw std::logic_error("can't compare different matrices");
                    }
                    return num_item<other.num_item;
                }

                bool operator>(const Iterator& other) const {
                    if (matrix!=other.matrix){
                        throw std::logic_error("can't compare different matrices");
                    }
                    return num_item>other.num_item;
                }
                
                bool operator<=(const Iterator& other) const {
                    if (matrix!=other.matrix){
                        throw std::logic_error("can't compare different matrices");
                    }
                    return num_item<=other.num_item;
                }
                
                bool operator>=(const Iterator& other) const {
                    if (matrix!=other.matrix){
                        throw std::logic_error("can't compare different matrices");
                    }
                    return num_item>=other.num_item;
                }

                friend std::ostream& operator<<(std::ostream& output, Iterator& iter){
                    output<<&(*iter.matrix)(iter.__GetIndRow(),iter.__GetIndCol());
                    return output;
                }
            };

        Iterator begin() {
            return Iterator(this, 0);
        }

        Iterator end() {
            return Iterator(this, this->_col*this->_row);
        }

        friend std::ostream& operator<<(std::ostream& output, const Matrix<ItemType>& matrix) {
            if((matrix._row==0)||(matrix._col==0)) output<<(const char*)"<void>";
            for (int i = 0; i < matrix._row; ++i) {
                for (int j = 0; j < matrix._col; ++j) {
                    output.width(2);
                    output << matrix.data[i][j];
                    if((j+1)!=matrix._col) output<<' ';
                }
                if((i+1)!=matrix._row)output << '\n';
            }
            return output;
        }
};

template <typename ItemType>
Matrix<ItemType>::Matrix(int row, int col) : IMatrix<ItemType>(row, col) {
    if((row!=0)&&(col!=0)){
        data=new ItemType*[row];
        for(int i=0;i<row;i++) data[i]=new ItemType[col];
    }
    else { this->_row=0; this->_col=0; }
}

template <typename ItemType>
Matrix<ItemType>::~Matrix(){
    if(this->data!=nullptr){
        for(int i=0; i<this->_row; i++) delete [] data[i];
        delete [] data;
        this->_row=this->_col=0;
    }
}

template <typename ItemType>
Matrix<ItemType>& Matrix<ItemType>::operator=(const Matrix<ItemType>& other){
    if(this!=&other){
        if(this->data!=nullptr){
            for(int i=0; (i<this->_row)*(this->data[i]!=nullptr); i++) delete [] data[i];
            delete [] data;
        }
        
        this->_row=other._row;
        this->_col=other._col;
        if((this->_row!=0)&&(this->_col!=0)){
            this->data = new ItemType*[this->_row];
            for(int i=0; i<this->_row; i++) this->data[i]=new ItemType[this->_col];
            for(int i=0; i<this->_row; i++) for(int j=0; j<this->_col; j++) data[i][j]=other.data[i][j];
        }
        else data=nullptr;
    }
    return *this;
}

template <typename ItemType>
Matrix<ItemType>::Matrix(const Matrix<ItemType> &other){
    this->_row=other._row;
    this->_col=other._col;
    if((this->_row!=0)&&(this->_col!=0)){
        this->data=new ItemType*[this->_row];
        for(int i=0;i<this->_row;i++) data[i]=new ItemType[this->_col];
        for(int i=0;i<this->_row;i++) for(int j=0;j<this->_col;j++) data[i][j]=other.data[i][j];
    }
    else data=nullptr;
}

template <typename ItemType>
ItemType& Matrix<ItemType>::operator()(int i, int j){
    if((i<0)||(j<0)||(i>=this->_row)||(j>=this->_col))
        throw std::range_error("index matrix out of range");
    return data[i][j];
}

template <typename ItemType>
const ItemType& Matrix<ItemType>::operator()(int i, int j) const{
    if((i<0)||(j<0)||(i>=this->_row)||(j>=this->_col))
        throw std::range_error("index matrix out of range");
    return data[i][j];
}

template <typename ItemType>
ItemType* Matrix<ItemType>::operator[](int index){
    return data[index];
}

template <typename ItemType>
const ItemType* Matrix<ItemType>::operator[](int index) const {
    return data[index];
}

#endif