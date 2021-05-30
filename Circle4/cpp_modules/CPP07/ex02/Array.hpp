#ifndef ARRAY
#define ARRAY

template <typename T>
class Array
{
public:
    Array() : mElem(nullptr), mSize(0){};
    Array(unsigned int n) : mElem(new T[n]), mSize(n){};
    ~Array()
    {
        delete[] mElem;
    };

    Array(const Array &array) : mElem(new T[0]), mSize(0)
    {
        *this = array;
    };

    Array &operator=(const Array &array)
    {
        if (this == &array)
            return (*this);

        mSize = array.size();
        mElem = new T[mSize];

        for (int i = 0; i < mSize; ++i)
            mElem[i] = array.mElem[i];

        return (*this);
    };

    T &operator[](unsigned int idx)
    {
        if (idx < 0 || idx >= mSize)
            throw OutOfBoundsException();
        else
            return mElem[idx];
    };

    const T &operator[](unsigned int idx) const
    {
        if (idx < 0 || idx >= mSize)
            throw OutOfBoundsException();
        else
            return mElem[idx];
    };

    unsigned int size(void) const
    {
        return mSize;
    };

    class OutOfBoundsException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return ("ArrayException: Out of bound");
        };
    };

private:
    T *mElem;
    unsigned int mSize;
};

#endif