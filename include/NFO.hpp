#include <memory>
#include <eigen3/Eigen/Dense>
#include "ProblemDescriptionCore.hpp"

#pragma once

struct Parameters {
    /// @brief Maximum number of outer iteration before termination.
    unsigned long OPT_MAX_ITER{10000};

    /// @brief Minimum allowed step length change before termination.
    double OPT_STEP_TOL{1e-4};

    /// @brief Initial step length for cost functions.
    double OPT_STEP_LENGTH_INIT{1e-6};

    /// @brief Initial step lengths for constraint functions.
    double OPT_STEP_LENGTH_INIT_CONST{1e-6};

    /// @brief Step length multiplier for per line search iteration for cost function.
    double OPT_LENGTH_MULTIPLIER{2.0};

    /// @brief Step length multiplier for per line search iteration for constraint function.
    double OPT_LENGTH_MULTIPLIER_CONST{2.0};

    /// @brief If the gradient norm is less than this value, do not iterate.
    double OPT_GRAD_NORM_TOL{1e-10};

    /// @brief If the change in the cost function is smaller than this value, stop optimization.
    double OPT_FINAL_COST_TOL{1e-4};

    /// @brief If the equality constraint cost is smaller than this value, accept solution.
    double OPT_CONSTRAINT_TOL{1e-4};

    /// @brief If the inequality cost less than this value, activate the constraint.
    double OPT_INEQUALITY_NORM{1e-4};

    /// @brief Print each outer iteration. (Slower solution)
    bool OPT_VERBOSE{false};

    /// @brief Print each inner iteration. (Slower+ solution)
    bool OPT_VERBOSE_STEP_DETAIL{false};

    /// @brief A flag that is set true if the optimization terminates due to max iteration is reached.
    bool maxIterFlag{false};

    /// @brief A flag that is set true if the optimization terminates at step tolerance check.
    bool stepTolFlag{false};

    /// @brief A flag that is set true if the optimization terminates at cost tolerance check.
    bool finalCostFlag{false};

    /// @brief Set it true if you want to activate the interim function.
    bool interimFunctionEnable{false};

    /// @brief Set it false if your problem does not include cost function but only constraint.
    bool costFunctionEnable{true};
};

class NFO {

public:
    /// @brief A public object that collects all optimization parameters.
    Parameters parameters;

    /// @brief Constructor.
    /// @param problemObject Problem object instance.
    /// @param n_param Number of optimization parameters.
    /// @param n_eqConstraint Number of equality constraints.
    /// @param n_ineqConstraint Number of inequality constraints.
    NFO(ProblemDescriptionCore* problemObject, size_t n_param, size_t n_eqConstraint, size_t n_ineqConstraint);

    /// @brief Solve the optimization problem.
    void solve();

    /// @brief Get a copy of the optimization parameters.
    /// @return Parameter vector.
    Eigen::VectorXd getXCopy();

    /// @brief Get a constant pointer to the parameter vector.
    /// @return Constant pointer to the parameter vector.
    Eigen::VectorXd const * const getXConstantPtr();

    /// @brief Set initial condition of the optimization problem. The default value is zero.
    /// @param initCond A vector of optimization parameters
    void setInitialCondition (const Eigen::VectorXd&);

    /// @brief Prints a summary after the completion.
    void printResult();

    /// @brief Object destructor.
    ~NFO();

private:
    class NFOImpl;
    std::unique_ptr<NFOImpl> Impl;
};