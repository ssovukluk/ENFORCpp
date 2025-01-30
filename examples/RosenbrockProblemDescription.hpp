#include <eigen3/Eigen/Dense>
#include "ProblemDescriptionCore.hpp"

#pragma once

class RosenbrockProblemDescription : public ProblemDescriptionCore {

public:
    /// @brief The cost function should return only non-negative real numbers.
    /// @param x Optimization parameters.
    /// @return Total absolute cost.
    double costFunction (const Eigen::VectorXd& x) override {
        return 100.0*pow(x[1]-x[0]*x[0],2) + pow(1-x[0],2);
    }

    /// @brief Equality constraint functions. The constraints should be implemented in a switch-case environment starting from zero.
    /// @param x Optimization parameters.
    /// @param selection A mandatory parameter for multiple constraints to iterate through a switch statement.
    /// @return Result of the selected function.
    double equalityConstraintFunction (const Eigen::VectorXd& x, unsigned int selection = 0) override {
        return 0;
    }

    /// @brief Inequality constraint functions. The constraints should be implemented in a switch-case environment starting from zero.
    /// @param x Optimization parameters.
    /// @param selection A mandatory parameter for multiple constraints to iterate through a switch statement.
    /// @return Result of the selected function.
    double inequalityConstraintFunction (const Eigen::VectorXd& x, unsigned int selection = 0) override {
        switch (selection) {
            case 0:
            {
                return x[0]*x[0] + x[1]*x[1] - 1.0;
            }
        }
        return 0;
    }

    /// @brief An interim function that is called once per outer iteration. Can be used for occasional parameter updates. This function does not go into gradient estimation.
    /// @param x Optimization parameters.
    void interimFunction (const Eigen::VectorXd& x) override {}

};