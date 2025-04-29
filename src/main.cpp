#include <iostream>
#include <algorithm>
#include <ctime>

#include "IMatrix.h"
#include "Matrix.h"


int main() {
    srand(time(NULL));
    int n,m;
    std::cout<<"Write size matrix (n and m) >> ";
    std::cin>>n>>m;

    Matrix<int> matr1(n, m);
    
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)matr1(i,j)=rand()%100;

    std::cout << "---MATR1 BEFORE SORTING---\n" << matr1 << std::endl << std::endl;

    std::cout << "---Iteration order---"<<std::endl;
    for(auto v: matr1) std::cout << v << ' ';
    std::cout<<std::endl<< std::endl;

    std::sort(matr1.begin(),matr1.end());
    std::cout << "---MATR1 AFTER SORTING---\n" << matr1 << std::endl<<std::endl;
    return 0;
}
