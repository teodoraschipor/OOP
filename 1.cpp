#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;

class BigIntegerNumber
{
private:
    int Size;
    int *Array;
public:

    ///CONSTRUCTOR
    BigIntegerNumber(int i = 1000000);
    ///DESTRUCTOR
    ~BigIntegerNumber();
    ///METHODS
    int Zero();
    ///OPERATORS
    BigIntegerNumber operator=(BigIntegerNumber X);
    BigIntegerNumber operator+(BigIntegerNumber X);
    BigIntegerNumber operator-(BigIntegerNumber X);
    BigIntegerNumber operator*(BigIntegerNumber X);
    BigIntegerNumber operator/(BigIntegerNumber X);
    bool operator>(BigIntegerNumber X);
    bool operator==(BigIntegerNumber X);
    ///FRIEND FUNCTIONS
    friend ostream &operator << (ostream &output, BigIntegerNumber X);
    friend istream &operator >> (istream &input, BigIntegerNumber &X);

};


///------------CONSTRUCTORS & DESTRUCTOR---------------
BigIntegerNumber::BigIntegerNumber(int i)
{
    Size = i;
    Array = new int[Size];
}
BigIntegerNumber::~BigIntegerNumber()
{
    delete[]Array;
}
///OPERATORS FOR READ AND WRITE
ostream &operator << (ostream &output, BigIntegerNumber X)
{

    BigIntegerNumber Z = X;
    for(int i = X.Size - 1; i >= 0; i--)
        output << Z.Array[i];
    return output;
}

istream &operator >> (istream &input, BigIntegerNumber &X)
{
    int i;

    input >> X.Size;
    for(i = X.Size - 1; i >= 0; i--)
        input >> X.Array[i];
    return input;
}

///------------------OPERATORS--------------------

bool BigIntegerNumber::operator>(BigIntegerNumber X)
{
    while (this->Size && !this->Array[this->Size - 1])
        this->Size--;
    while (X.Size && !X.Array[X.Size - 1])
        X.Size--;

    if (this->Size < X.Size)
    {
        return false;
    }
    else if (this->Size > X.Size)
    {
        return true;
    }

    for (int i = this->Size - 1; i >= 0; --i)
    {
        if (this->Array[i] < X.Array[i])
        {
            return false;
        }
        else if (this->Array[i] > X.Array[i])
        {
            return true;
        }
    }
    return false;
}

bool BigIntegerNumber::operator==(BigIntegerNumber X)
{
    while (this->Size && !this->Array[this->Size])
        this->Size--;
    while (X.Size && !X.Array[X.Size])
        X.Size--;

    if (this->Size < X.Size)
    {
        return 0;
    }
    else if (this->Size > X.Size)
    {
        return 0;
    }

    for (int i = this->Size - 1; i >= 0; --i)
    {
        if (this->Array[i] < X.Array[i])
        {
            return 0;
        }
        else if (this->Array[i] > X.Array[i])
        {
            return 0;
        }
    }
    return 1;
}

BigIntegerNumber BigIntegerNumber::operator=(BigIntegerNumber X)
{
    Size = X.Size;
    delete[]this->Array;
    this->Array = new int[X.Size];
    int i;
    for(i = 0; i < X.Size; i++)
        Array[i] = X.Array[i];
    return *this;
}

BigIntegerNumber BigIntegerNumber::operator+(BigIntegerNumber X)
{
    BigIntegerNumber Z;
    if(this->Size > X.Size)
        Z.Size = this->Size+1;
    else
        Z.Size = X.Size+1;

    int r = 0, result;
    for(int i = 0; i < Z.Size; i++)
    {
        result = this->Array[i] + X.Array[i] + r;
        Z.Array[i] = result % 10;
        r = result / 10;
    }


    while(Z.Size > 1 && !Z.Array[Z.Size - 1])
        Z.Size--;


    return Z;
}

BigIntegerNumber BigIntegerNumber::operator-(BigIntegerNumber X)
{
    BigIntegerNumber Z;
    if(this->Size > X.Size)
        Z.Size = this->Size;
    else
        Z.Size = X.Size;
    int r = 0, result;
    for(int i = 0; i < Z.Size; i++)
    {
        result = this->Array[i] - X.Array[i] - r;
        if(result < 0)
        {
            Z.Array[i] = result + 10;
            r = 1;
        }
        else
        {
            Z.Array[i] = result;
            r = 0;
        }
    }
    return Z;
}

BigIntegerNumber BigIntegerNumber::operator*(BigIntegerNumber X)
{
    BigIntegerNumber Y = *this;
    int i, j, t = 0;
    BigIntegerNumber z;
    z.Size = Y.Size + X.Size;
    for(i = 0; i < z.Size; i++)
        z.Array[i] = 0;
    for(i = 0; i < Y.Size; i++)
        for(j = 0; j < X.Size; j++)
        {
            z.Array[i + j] += Y.Array[i] * X.Array[j];
        }
    for(i = 0; i < z.Size; i++)
    {
        t += z.Array[i];
        z.Array[i] = t % 10;
        t /= 10;
    }
    if(t)
        z.Array[z.Size + 1] = t;

    while(z.Size > 1 && !z.Array[z.Size - 1])
        z.Size--;

    return z;
}

/*BigIntegerNumber BigIntegerNumber::operator/(BigIntegerNumber X) //Impartire prin scaderi repetate
{
    BigIntegerNumber Y;
    Y = *this;
    BigIntegerNumber Cat;
    while(Y > X)
    {
        Y = Y - X;
        Cat++;
    }
        return Y;

}
*/

///------------METHODS--------------
int BigIntegerNumber::Zero()
{
    int i, k = 0;
    if(Array[0] != 0)
        return -1;
    else
    {
        k++;
        for(i = 1; i < Size; i++)
        {
            if(Array[i] != 0)
                return k;
            else
                k++;
        }
    }
    for(i = 0; i < Size - k; i++)
    {
        Array[i] = Array[i + k];//elimin zerourile //remove the 0
    }
    Size = Size - k;//noua dimensiune //the new dimension
    return k;
}

int main()
{

    BigIntegerNumber a;

    cin>>a;
    cout<<a;
    return 0;
}
