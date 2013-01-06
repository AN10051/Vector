#include "mVector.h"

mVector::mVector()
{
    //ctor
}

mVector::mVector(int iSize)
{
    if(iSize>0)
    {
        this->vContent=new (std::nothrow) std::vector <double> (iSize);
        if( this == 0)
        {
            //call to error class invoking the memory error message
            exit(EXIT_FAILURE);
        }

        for(unsigned int i=0;i<this->vContent->size();i++)
        this->vContent->at(0);   //initialize a zero vector of size iSize
    }
}

mVector::mVector(unsigned int iSize, double Contents[])
{
    if(iSize>0)
    {
        this->vContent=new(std::nothrow) std::vector <double> (iSize);
        if (this==0)
        {
            //call to error class invoking the memory error message
            exit(EXIT_FAILURE);
        }
        else
        {
            for(unsigned int i=0;i<iSize;i++)
            {
                std::cout<<*Contents<<std::endl;
                this->vContent->at(i)=(*Contents);
                Contents++;
            }
        }
    }

}
//
//
mVector::mVector(const mVector& other)
{
    //copy ctor
    int othersize = other.vContent->size();
    this->vContent=new (std::nothrow) std::vector<double> (othersize);
    if (this==0)
    {
            //call to error class invoking the memory error message
            exit(EXIT_FAILURE);
    }
    else
    {
        for(unsigned int i=0;i<vContent->size();i++)
        {
            this->vContent->at(i)=other.vContent->at(i);
        }
    }

}

mVector::~mVector()
{
    this->vContent->clear();
    //dtor
}

int mVector::resizedata(double* Content,unsigned int Sz)
{
    if(Sz>0)
    {
        try
        {
            this->vContent->resize(Sz);
        }
        catch(std::bad_alloc)
        {
            //call to error class invoking the memory error message
            exit(EXIT_FAILURE);
        }
       for(unsigned int i=0;i<Sz;i++)
       {
           this->vContent->at(i)=*Content;
           Content++;
       }
       return 0;
    }
    else
    {
        //call to error class for invoking incorrect size error message
        return -1;
    }
}

int mVector::resizedata(const mVector& other)
{
    unsigned int Sz = other.vContent->size();
    if(Sz>0)
    {
       try
        {
        this->vContent->resize(Sz);
        }
        catch(std::bad_alloc)
        {
            //call to error class invoking the memory error message
            exit(EXIT_FAILURE);
        }
        for(unsigned int i=0;i<Sz;i++)
       {
           this->vContent->at(i)=other.vContent->at(i);
       }
       return 0;
    }
    else
    {
        //call to error class for invoking incorrect size error message
        return -1;
    }
}

void mVector::pushdata(double data)
{
    try
    {
        this->vContent->push_back(data);
    }
    catch(std::bad_alloc)
        {
            //call to error class invoking the memory error message
            exit(EXIT_FAILURE);
        }
}

void mVector::ShowVector()
{
float output;
unsigned int Sz=this->vContent->size();
     for(unsigned int i=0;i<Sz;i++)
    {
        output=this->vContent->at(i);
        std::cout<<output<<std::endl;
    }
}

double mVector::norm() const
{
    double result;
    for(unsigned int i=0;i<this->vContent->size();i++)
    {
        result = result + this->vContent->at(i)*this->vContent->at(i);
    }
    return result;
}

void mVector::zero()
{
    for(unsigned int i=0;i<this->vContent->size();i++)
    {
        this->vContent->at(i)=0;
    }
}

int mVector::getsize() const
{
    return this->vContent->size();
}

void mVector::normalize()
{
    double norm = this->norm();
    for(unsigned int i=0;i<this->vContent->size();i++)
    {
        this->vContent->at(i)=this->vContent->at(i)/norm;
    }
}


 mVector mVector::operator+(const mVector& other )
 {
    mVector temp(this->vContent->size());
     if(this->vContent->size()==other.vContent->size())
     {
         for(unsigned int i=0;i<this->vContent->size();i++)
           {
               temp.vContent->at(i)=this->vContent->at(i)+ other.vContent->at(i);
               std::cout<<"temp vector contents"<<temp.vContent->at(i)<<std::endl;
           }
        return temp;
     }
     else std::cout<<"Incorrect size"<<std::endl;

 }

  mVector mVector::operator-(const mVector& other )
 {
    mVector temp(this->vContent->size());
     if(this->vContent->size()==other.vContent->size())
     {
         for(unsigned int i=0;i<this->vContent->size();i++)
            {
               temp.vContent->at(i)=this->vContent->at(i)- other.vContent->at(i);
            }
        return temp;
     }
     else std::cout<<"Incorrect size"<<std::endl;

 }

 void mVector::operator=(const mVector& other)
 {
     if(this==&other)
     {
         std::cout<<"Identical objects on LHS andRHS"<<std::endl;
            return;
     }
         int sz1, sz2;
         sz1 = this->vContent->size();
         sz2=other.vContent->size();
     if(this->vContent->size()==other.vContent->size())
     {

         for(unsigned int i=0;i<this->vContent->size();i++)
            {
                this->vContent->at(i)=other.vContent->at(i);
            }
     }
 }
 void mVector::operator+=(double fact)
 {
     for(unsigned int i=0;i<this->vContent->size();i++)
        this->vContent->at(i)+=fact;
 }


 double& mVector::operator[](unsigned int index)
 {
     double b=0;
     double& dummy = b;
     if ((index>=0)&&(index<this->vContent->size()))
        return this->vContent->at(index);

    else
        {
            std::cout<<"Incorrect index requested"<<std::endl;
            return dummy;
        }
 }

  double& mVector::operator()(unsigned int index)
 {
     double b=0;
     double& dummy = b;
     if ((index>=0)&&(index<this->vContent->size()))
        return this->vContent->at(index);

    else
        {
            std::cout<<"Incorrect index requested"<<std::endl;
            return dummy;
        }
 }

 bool mVector::operator==(const mVector& other)
{
    unsigned int Sz_other = other.vContent->size();
    unsigned int Sz_this= other.vContent->size();
    bool is_same=true;

    if((Sz_other>0)&&(Sz_this)>0)
    {
        if(Sz_other!=Sz_this)
        {
            is_same=false;
            return is_same;
        }

       for(unsigned int i=0;i<Sz_this;i++)
       {
          if( this->vContent->at(i)!=other.vContent->at(i))
            is_same=false;
       }
       return is_same;
    }
    else return -1;
}

