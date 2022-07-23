#include "zesp.h"


int main(){

    complex_named z1("An",1.,1.);
    complex_named z2("Bn",1.,-1.);
    std::cout << z1 << std::endl
    << z2 << std::endl;
    complex_named za=z1+z2, zs=z1-z2, zm=z1*z2, zd=z1/z2;
    std::cout << za << std::endl
    << zs << std::endl
    << zm << std::endl
    << zd << std::endl;
    std::cout << z1++ << std::endl;
    std::cout << z1 << std::endl;
    std::cout << ++z1 << std::endl;
    std::cout << z1 << std::endl;
    std::cout << z1[0] << " " << &(z1.name) << std::endl;
    std::cout << z1[1] << " " << &(z1.real) << std::endl;
    std::cout << z1[2] << " " << &(z1.imag) << std::endl;
    complex_named z3=z1;
    std::cout << z1[0] << " " << z3[0] << std::endl;
    int i=0;
    while(!(!z1)){
        std::cout<< i << " " << z1 << std::endl;
        complex_named two("2",2.,0.);
        z1=z1/two;
    }
    return 0;
}
