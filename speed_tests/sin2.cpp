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

double sin(double x)
{
    double x2 = x * x;
    return (((((-2.05342856289746600727e-08*x2 + 2.70405218307799040084e-06)*x2 - 1.98125763417806681909e-04)*x2 + 8.33255814755188010464e-03)*x2 - 1.66665772196961623983e-01)*x2 + 9.99999707044156546685e-01)*x;
}

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


