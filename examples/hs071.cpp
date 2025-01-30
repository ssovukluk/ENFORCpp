#include "NFO.hpp"
#include "HS071ProblemDescription.hpp"
#include <eigen3/Eigen/Dense>
#include <iostream>

int main() {
    HS071ProblemDescription problem;
    NFO functionOptim(&problem, 4, 1, 9);
    functionOptim.parameters.OPT_MAX_ITER = 1000;
    functionOptim.parameters.OPT_VERBOSE = false;
    functionOptim.parameters.OPT_VERBOSE_STEP_DETAIL = false;
    functionOptim.parameters.OPT_STEP_LENGTH_INIT = 1e-6;
    functionOptim.parameters.OPT_STEP_LENGTH_INIT_CONST = 1e-6;
    functionOptim.parameters.OPT_STEP_TOL = 1e-4;
    functionOptim.parameters.OPT_FINAL_COST_TOL = 1e-4;
    functionOptim.parameters.OPT_LENGTH_MULTIPLIER = 2.0;
    functionOptim.parameters.OPT_LENGTH_MULTIPLIER_CONST = 2.0;
    Eigen::Vector<double,4> initialCond{1,5,5,1};
    functionOptim.setInitialCondition(initialCond);

    functionOptim.solve();
    functionOptim.printResult();
    return 0;
}