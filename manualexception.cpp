#include <iostream>
using namespace std;

int main()
{
    // membuat isi dari try untuk pengujuian error
    try
    {
        /* code */
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}