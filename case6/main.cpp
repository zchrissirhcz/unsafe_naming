#include <windows.h>
#include <limits>

int main()
{
    unsigned int max_size = std::numeric_limits<unsigned int>::max();
    printf("max_size = %u\n", max_size);

    return 0;
}