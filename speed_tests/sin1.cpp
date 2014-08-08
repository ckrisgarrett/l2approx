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
    return ((((((((((2.47852306233493974115e-20*x2 - 8.53932287916564238231e-18)*x2 + 2.81875350346861226633e-15)*x2 - 7.64807134493815932275e-13)*x2 + 1.60591122567208977895e-10)*x2 - 2.50521116230089813913e-08)*x2 + 2.75573193196855760359e-06)*x2 - 1.98412698429672570320e-04)*x2 + 8.33333333334987771150e-03)*x2 - 1.66666666666674074058e-01)*x2 + 1.00000000000000098216e+00)*x;
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


