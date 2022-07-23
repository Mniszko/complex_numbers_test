
#ifndef complex_named_
#define complex_named_

#include <iostream>
#include <fstream>
#include <limits>
#include <cmath>
#include <string.h>

class complex_named{
    private:
        static const double eps;
    public:
        char* name;
        double real;
        double imag;

        complex_named(const char*,double,double);
        ~complex_named();
        complex_named operator + (const complex_named&);
        complex_named operator * (const complex_named&);
        complex_named operator - (const complex_named&);
        complex_named operator / (const complex_named&);
        
        complex_named& operator++();       // Prefix 
        complex_named operator++ (int);     // Postfix 

        friend std::ostream& operator<<(std::ostream& os, const complex_named& value){
            os << "\"name\"=" << value.real << '+' << 'i' << value.imag;
            return os;
        };
        bool operator!();
        void* operator[](int);
        complex_named& operator=(const complex_named&);
};


#endif