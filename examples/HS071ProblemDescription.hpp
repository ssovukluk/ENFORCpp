#include <eigen3/Eigen/Dense>
#include "ProblemDescriptionCore.hpp"

#pragma once

class HS071ProblemDescription : public ProblemDescriptionCore {

public:
    /// @brief The cost function should return only non-negative real numbers.
    /// @param x Optimization parameters.
    /// @return Total absolute cost.
    double costFunction (const Eigen::VectorXd& x) override {
        return x[0]*x[3]*(x[0]+x[1]+x[2])+x[2];
    }

    /// @brief Equality constraint functions. The constraints should be implemented in a switch-case environment starting from zero.
    /// @param x Optimization parameters.
    /// @param selection A mandatory parameter for multiple constraints to iterate through a switch statement.
    /// @return Result of the selected function.
    double equalityConstraintFunction (const Eigen::VectorXd& x, unsigned int selection = 0) override {
        switch (selection) {
            case 0:
            {
                return x[0]*x[0] + x[1]*x[1] + x[2]*x[2] + x[3]*x[3] - 40.0;
            }
        }
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
                return 1.0-x[0];
            }
            case 1:
            {
                return 1.0-x[1];
            }
            case 2:
            {
                return 1.0-x[2];
            }
            case 3:
            {
                return 1.0-x[3];
            }
            case 4:
            {
                return x[0]-5.0;
            }
            case 5:
            {
                return x[1]-5.0;
            }
            case 6:
            {
                return x[2]-5.0;
            }
            case 7:
            {
                return x[3]-5.0;
            }
            case 8:
            {
                return 25-x[0]*x[1]*x[2]*x[3];
            }
        }
        return 0;
    }

    /// @brief An interim function that is called once per outer iteration. Can be used for occasional parameter updates. This function does not go into gradient estimation.
    /// @param x Optimization parameters.
    void interimFunction (const Eigen::VectorXd& x) override {}

};