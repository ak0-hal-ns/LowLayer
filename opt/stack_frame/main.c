void unwind();

void
f(int count)
{
    if (count)
        f(count - 1);
    else
        unwind();
}

int
main(int argc, char* argv[])
{
    f(10);

    return 0;
}
