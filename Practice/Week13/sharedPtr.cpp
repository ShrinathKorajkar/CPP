template <typename T>
class SharedPtr
{
    T *ptr;
    int *refCount;

public:
    // constructor
    explicit SharedPtr(T *p = nullptr) : ptr(p)
    {
        if (p)
            refCount = new int(1);
        else
            refCount = nullptr;
    }

    // copy constructor
    SharedPtr(const SharedPtr &other) : ptr(other.ptr), refCount(other.refCount)
    {
        if (refCount)
            (*refCount)++;
    }

    // copy assignment
    SharedPtr &operator=(const SharedPtr &other)
    {
        if (this != &other)
        {
            releaseCurrent();

            ptr = other.ptr;
            refCount = other.refCount;
            if (refCount)
                (*refCount)++;
        }
        return *this;
    }

    // move constructor
    SharedPtr(SharedPtr &&other) noexcept : ptr(other.ptr), refCount(other.refCount)
    {
        other.ptr = nullptr;
        other.refCount = nullptr;
    }

    // move assignment
    SharedPtr &operator=(SharedPtr &&other) noexcept
    {
        if (this != &other)
        {
            releaseCurrent();

            ptr = other.ptr;
            refCount = other.refCount;
            other.ptr = nullptr;
            other.refCount = nullptr;
        }
        return *this;
    }

    // destructor
    ~SharedPtr()
    {
        releaseCurrent();
    }

private:
    void releaseCurrent()
    {
        if (refCount)
        {
            (*refCount)--;
            if (*refCount == 0)
            {
                delete ptr;
                delete refCount;
            }
        }
    }

public:
    // operators
    T &operator*() const { return *ptr; }
    T *operator->() const { return ptr; }

    int use_count() const { return refCount ? *refCount : 0; }
    T *get() const { return ptr; }
    explicit operator bool() const { return ptr != nullptr; }
};
