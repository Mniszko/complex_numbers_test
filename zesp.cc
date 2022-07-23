#include "zesp.h"


complex_named::complex_named(const char* s,double r,double im){
    this->name = (char*)malloc(sizeof(s));
    this->name = const_cast<char*>(s);
    
    this->real = r;
    this->imag = im;   
}
complex_named::~complex_named(){
    delete this->name;//delete this->name?
}



complex_named complex_named::operator+(const complex_named& imag){
    int temp = sizeof(imag.name)/sizeof(const char*);
    char w[temp + 1 + sizeof(this->name)/sizeof(const char*)];
    for (int i=0 ; i<temp ; ++i){
        w[i] = this->name[i];
    }
    w[temp+1]='+';
    for (int i=0 ; i<sizeof(this->name)/sizeof(const char*) ; ++i){
        w[temp+1+i] = imag.name[i];
    }
    return complex_named(
        (const char*){w},
        (this->real) + (imag.real),
        (imag.imag) + (this->imag)
    );
}
complex_named complex_named::operator-(const complex_named& imag){
    int temp = sizeof(imag.name)/sizeof(const char*);
    char w[temp + 1 + sizeof(this->name)/sizeof(const char*)];
    for (int i=0 ; i<temp ; ++i){
        w[i] = this->name[i];
    }
    w[temp+1]='-';
    for (int i=0 ; i<sizeof(this->name)/sizeof(const char*) ; ++i){
        w[temp+1+i] = imag.name[i];
    }
    return complex_named(
        (const char*){w},
        (this->real) - (imag.real),
        (this->imag) - (imag.imag)
    );
}
complex_named complex_named::operator*(const complex_named& imag){
    int temp = sizeof(imag.name)/sizeof(const char*);
    char w[temp + 1 + sizeof(this->name)/sizeof(const char*)];
    for (int i=0 ; i<temp ; ++i){
        w[i] = this->name[i];
    }
    w[temp+1]='*';
    for (int i=0 ; i<sizeof(this->name)/sizeof(const char*) ; ++i){
        w[temp+1+i] = imag.name[i];
    }
    return complex_named(
        (const char*){w},
        (this->real)*(imag.real) - (this->imag)*(imag.imag),
        (this->real)*(imag.imag) + (this->imag)*(imag.real)
    );
}
complex_named complex_named::operator/(const complex_named& imag){
    int temp = sizeof(imag.name)/sizeof(const char*);
    char w[temp + 1 + sizeof(this->name)/sizeof(const char*)];
    for (int i=0 ; i<temp ; ++i){
        w[i] = this->name[i];
    }
    w[temp+1]='/';
    for (int i=0 ; i<sizeof(this->name)/sizeof(const char*) ; ++i){
        w[temp+1+i] = imag.name[i];
    }

    double size = (imag.real)*(imag.real) + (imag.imag)*(imag.imag);

    return complex_named(
        (const char*){w},
        ((this->real)*(imag.real) + (this->imag)*(imag.imag))/size,
        ((this->imag)*(imag.real) - (this->real)*(imag.imag))/size
    );
}


complex_named& complex_named::operator++(){
    this->real++;
    return *this;
}
complex_named complex_named::operator++(int add){
    this->imag++;
    return *this;
    //return complex_named (this->name,this->real,this->imag++);
}

bool complex_named::operator!(){
    if(abs(this->real)<std::numeric_limits<double>::epsilon() &&
    abs(this->imag)<std::numeric_limits<double>::epsilon()
    ){
        return true;
    }
    return false;
}

void* complex_named::operator[](int i){
    if(i==0){
        return &(this->name);
    }
    else if (i==1){
        return &(this->real);
    }
    else if (i==2){
        return &(this->imag);
    }
    return &(this->imag);
}

complex_named& complex_named::operator=(const complex_named& complex){
        if ( this != &complex ) {
            delete this->name;
            this->real = complex.real;
            this->name = (char*)memcpy(new char*,
                        complex.name,
                        sizeof(complex.name)
                        );
            this->real = complex.real;
        }
        return *this;
}