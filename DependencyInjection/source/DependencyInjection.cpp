#include <iostream>
#include "DiscreteFunction.h"
#include <vector>

int main()
{
    std::vector<double> ys(21);
    double delta_x = 1.0 / 20;
    for(size_t i = 0; i < ys.size(); i++)
    {
        double x = delta_x * i;
        ys[i] = x*x;
    }

    
    std::unique_ptr<Integrator> integrator_trap = std::make_unique<TrapeziumIntegrator>();

    DiscreteFunction DF_trap(ys, 0, 1, integrator_trap);

    std::cout << DF_trap.integrate() << std::endl;


    std::unique_ptr<Integrator> integrator_simp = std::make_unique<SimpsonIntegrator>();

    DiscreteFunction DF_simp(ys, 0, 1, integrator_simp);

    std::cout << DF_simp.integrate() << std::endl;


    return 0;
}