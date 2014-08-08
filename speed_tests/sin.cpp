#include <cmath>
#include <iostream>
using namespace std;

static const double values[] = 
{
    -3.0,
    -2.5,
    -2.0,
    -1.5,
    -1.0,
    -0.5,
     0.0,
     0.5,
     1.0,
     1.5,
     2.0,
     2.5,
     3.0,
};

int main()
{
    clock_t start, end;
    double x = 0;
    int iterations = 100000000;
    
    start = clock();
    
    for(int k = 0; k < iterations; k++)
    {
        x += sin(values[k % 13]);
    }
    end = clock();
    
    cout << "x = " << x << endl;
    cout << "sin(1) = " << sin(1.0) << endl;
    cout << "time: " << (end - start) / (CLOCKS_PER_SEC/1000) << endl << endl;

    return 0;
}


