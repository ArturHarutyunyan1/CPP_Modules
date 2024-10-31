#include "Base.hpp"

Base::~Base()
{

}

Base *generate(void)
{
    int r = rand() % 3;

    if (r == 1)
        return (new A);
    else if (r == 2)
        return (new B);
    else
        return (new C);
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown object" << std::endl;
}

void identify(Base &p)
{
    try
    {
        Base &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(const std::bad_cast)
    {
        try
        {
            Base &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch(const std::bad_cast)
        {
            try
            {
                Base &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;                
            }
            catch(const std::exception& e)
            {
                std::cerr << "Unknown object" << std::endl;
            }
        }
    }
}