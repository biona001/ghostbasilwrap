#include "jlcxx/jlcxx.hpp"
#include <vector>
#include <iostream>
using namespace std;

double cpp_mat_sum(jlcxx::ArrayRef<double, 2> x) {
    cout << &x[0] << endl; // print memory address of x
    double total = 0;
    for(auto xij : x) {
        total += xij;
    }
    return total;
}

JLCXX_MODULE define_julia_module(jlcxx::Module& mod)
{
    mod.method("cpp_mat_sum", &cpp_mat_sum);
}

