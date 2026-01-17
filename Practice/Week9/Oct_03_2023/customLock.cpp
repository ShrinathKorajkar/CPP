template <typename Mutex>
class my_lock_guard
{
    Mutex &mtx;

public:
    explicit my_lock_guard(Mutex &m) : mtx(m)
    {
        mtx.lock();
    }

    ~my_lock_guard()
    {
        mtx.unlock();
    }

    my_lock_guard(const my_lock_guard &) = delete;
    my_lock_guard &operator=(const my_lock_guard &) = delete;
};

template <typename Mutex>
class my_unique_lock
{
    Mutex *mtx;
    bool owns;

public:
    // Constructor that locks immediately
    explicit my_unique_lock(Mutex &m) : mtx(&m), owns(true)
    {
        mtx->lock();
    }

    // Deferred locking constructor
    my_unique_lock(Mutex &m, std::defer_lock_t) : mtx(&m), owns(false) {}

    ~my_unique_lock()
    {
        if (owns)
            mtx->unlock();
    }

    void lock()
    {
        if (!owns)
        {
            mtx->lock();
            owns = true;
        }
    }

    void unlock()
    {
        if (owns)
        {
            mtx->unlock();
            owns = false;
        }
    }

    bool owns_lock() const { return owns; }

    my_unique_lock(const my_unique_lock &) = delete;
    my_unique_lock &operator=(const my_unique_lock &) = delete;

    // Movable
    my_unique_lock(my_unique_lock &&other) noexcept
        : mtx(other.mtx), owns(other.owns)
    {
        other.mtx = nullptr;
        other.owns = false;
    }
};
