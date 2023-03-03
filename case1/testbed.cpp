// opencl_helper.hpp -> cl_d3d11.h -> d3d11.h -> rpcndr.h -> #define small char
#include <CL/cl_d3d11.h>

int main()
{
    int small = 2; // this cause compile error, since "#define small char"

    return 0;
}
