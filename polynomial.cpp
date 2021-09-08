#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Polynomial {
    public:
int* A = new int[1]; 
int size = 1;
Polynomial() {
(this -> A)[0]  = 0;
}
Polynomial(Polynomial const &a) {
this -> size = a.size;
this -> A = new int[size];

for(int i = 0; i < size; i++) {
(this -> A)[i] = a.A[i];
}
}
void setCoefficient(int degree, int coeff) {
if(degree >= size) {
    int* temp = new int[size* 2];
    for(int i = 0; i < size * 2 ; i++) {
        temp[i] = 0;
    }
    for(int i = 0; i < size; i++) {
      temp[i] = A[i];
    }
    this -> A = temp;
    size *= 2;
    this -> setCoefficient(degree, coeff);
}
else{
    A[degree] = coeff;
}
}

Polynomial operator+(Polynomial const &a ) { 
    Polynomial tmpPoly; 
    tmpPoly.size = max(a.size, this -> size);
    tmpPoly.A = new int[tmpPoly.size];
    if(a.size >= this -> size) {
        for(int i = 0; i < a.size; i++) {
            tmpPoly.A[i] = a.A[i];
        }
        for(int i = 0; i < this -> size ; i++) {
            tmpPoly.A[i] += (this -> A)[i];
        } 
    }
    else {
        for(int i = 0; i < this -> size; i++) {
            tmpPoly.A[i] = (this -> A)[i];
        }
        for(int i = 0 ; i < a.size; i++) {
            tmpPoly.A[i] += a.A[i];
        }
    }
    return tmpPoly;
}

Polynomial operator-(Polynomial const a) {
    for(int i = 0; i < a.size; i++) {
        a.A[i] *= -1;
    }
    return (*this) + a;
}

Polynomial operator*(Polynomial const &a) {
    Polynomial tempPoly;
    for(int i = 0; i < this -> size; i++) {
        for(int j = 0; j < a.size; j++) {
            int deg = i + j;
            int coeff = a.A[j] * (this -> A)[i];
            if(tempPoly.size <= deg) {
                tempPoly.setCoefficient(deg, coeff);
            }
            else {
                tempPoly.A[deg] += coeff;
            }
        }
    }
    return tempPoly;
}

void operator=(Polynomial const &a) {
 this -> size = a.size;
this -> A = new int[size];

for(int i = 0; i < size; i++) {
(this -> A)[i] = a.A[i];
}  
}

void print() {
    for(int i = 0 ; i < this -> size; i++) {
        if((this -> A)[i] != 0) {
           cout << (this -> A)[i] << "x" << i << " ";
        }
    }
    cout << endl;
}



};

int main() {
Polynomial p1;
 p1.setCoefficient(1,1);
 p1.setCoefficient(3,2);
 p1.setCoefficient(5,-4);
 p1.print();
 Polynomial p2;
 p2.setCoefficient(0,4);
 p2.setCoefficient(1,2);
 p2.setCoefficient(2,-3);
 p2.setCoefficient(3,1);
 p2.print();
 (p1 + p2).print();
 (p1 - p2).print();
 (p1 * p2).print();
 return 0;
}