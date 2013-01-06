#include <iostream>
#include <vector>
//This class is used to store a row vector for fem calculations
//it wraps around the standard container class vector with
//some added functionality
//written by N.P.
//29.12.2012
class mVector
{
    public:
        //constructor 1
        mVector();
        //constructor 2
        mVector(int iSize);
        //constructor 3
        mVector(unsigned int , double[] );
        //constructor 4
        mVector (const mVector& );
        //dtor
        ~mVector();
        //utility functions
        int resizedata(double* ,unsigned int);
        int resizedata(const mVector&);
        void pushdata(double);
        double norm() const;
        int getsize()const;
        void zero();
        //this function normalizes the current object such that norm=1
        void normalize();

        // Operations
        // this function to be implemented after matrix implementation
        // overloaded operators

        // for adding to another vector
        mVector operator+(const mVector& );

        //subtraction
        mVector operator-(const mVector& );

        //for doing v + fact in single step
        void operator+=(double fact);

        //equality
        void operator=(const mVector& );

        //index access
        double& operator[](unsigned int index );

        //index access
        double& operator()(unsigned int index );

        //multiplication of a vector by a scalar
        double operator*(double fact);

        //this will give you a scalar product after checking both vectors of same size
        double operator*(const mVector&);

        //for checking equality of mVectors
        bool operator==(const mVector&);

        //for checking inequality of Vectors
        bool operator!=(const mVector&);

        //debug function
        void ShowVector();

    protected:

    private:
       std::vector <double> *vContent;
};


