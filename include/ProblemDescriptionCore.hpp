#include <eigen3/Eigen/Dense>

#pragma once

class ProblemDescriptionCore {

public:
    /// @brief The cost function should return only non-negative real numbers.
    /// @param x Optimization parameters.
    /// @return Total absolute cost.
    virtual double costFunction (const Eigen::VectorXd& x) {return 0;}

    /// @brief Equality constraint functions. The constraints should be implemented in a switch-case environment starting from zero.
    /// @param x Optimization parameters.
    /// @param selection A mandatory parameter for multiple constraints to iterate through a switch statement.
    /// @return Result of the selected function.
    virtual double equalityConstraintFunction (const Eigen::VectorXd& x, unsigned int selection = 0) {return 0;}

    /// @brief Inequality constraint functions. The constraints should be implemented in a switch-case environment starting from zero.
    /// @param x Optimization parameters.
    /// @param selection A mandatory parameter for multiple constraints to iterate through a switch statement.
    /// @return Result of the selected function.
    virtual double inequalityConstraintFunction (const Eigen::VectorXd& x, unsigned int selection = 0) {return 0;}

    /// @brief An interim function that is called once per outer iteration. Can be used for occasional parameter updates. This function does not go into gradient estimation.
    /// @param x Optimization parameters.
    virtual void interimFunction (const Eigen::VectorXd& x) {}

};