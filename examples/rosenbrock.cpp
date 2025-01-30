#include "NFO.hpp"
#include "RosenbrockProblemDescription.hpp"
#include <eigen3/Eigen/Dense>
#include <iostream>

int main() {
    RosenbrockProblemDescription problem;
    NFO functionOptim(&problem, 2, 0, 1);
    functionOptim.parameters.OPT_MAX_ITER = 1000;
    functionOptim.parameters.OPT_VERBOSE = false;
    functionOptim.parameters.OPT_VERBOSE_STEP_DETAIL = false;
    functionOptim.parameters.OPT_STEP_LENGTH_INIT = 1e-6;
    functionOptim.parameters.OPT_STEP_LENGTH_INIT_CONST = 1e-6;
    functionOptim.parameters.OPT_STEP_TOL = 1e-4;
    functionOptim.parameters.OPT_FINAL_COST_TOL = 1e-4;
    functionOptim.parameters.OPT_LENGTH_MULTIPLIER = 2.0;
    functionOptim.parameters.OPT_LENGTH_MULTIPLIER_CONST = 2.0;
    Eigen::Vector<double,2> initialCond{0,0};
    functionOptim.setInitialCondition(initialCond);

    functionOptim.solve();
    functionOptim.printResult();
    return 0;
}