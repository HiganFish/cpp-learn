class Foo
{
public:
    int Bar()
    {
        return 1;
    }
};

int main()
{
    Foo foo1, foo2;
    foo1.Bar();
    foo2.Bar();

    return 0;
}
