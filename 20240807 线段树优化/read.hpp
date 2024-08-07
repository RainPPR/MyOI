struct io_t {
    #define MAXSIZE (1 << 20)
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;

    io_t() : p1(buf), p2(buf), pp(pbuf) {}
    ~io_t() { fwrite(pbuf, 1, pp - pbuf, stdout); }

    char gc() {
        if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }

    template <typename T>
    T read() {
        T n = 0;
        bool f = 0;
        int c = gc();
        for ( ; !isdigit(c); c = gc())
            f |= c == '-';
        for ( ; isdigit(c); c = gc())
            n = n * 10 + c - '0';
        return f ? -n : n;
    }
} io;

#define rd() io.read<int>()