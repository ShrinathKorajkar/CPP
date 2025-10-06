long long msbPos(long long n)
{
    if (n == 0)
        return 0; // edge case
    long long msbPos = 0;
    while (n > 1)
    {
        n >>= 1;
        msbPos++;
    }
    return 1LL << msbPos; // return MSB value
}

long long flipBits(long long n)
{
    if (n == 0)
        return 1; // edge case

    long long msb = msbPos(n);
    n &= ~msb; // clear the MSB

    if ((n & 1) == 1)
    {
        n &= ~1; // clear LSB if it was 1
    }
    else
    {
        n |= 1; // set LSB if it was 0
    }

    return n;
}
