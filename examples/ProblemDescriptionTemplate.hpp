#include <eigen3/Eigen/Dense>
#include "ProblemDescriptionCore.hpp"

#pragma once

/*
This file constitues a template for problem description object. Please note the following: 
    - The declaration of "costFunction", "equalityConstraintFunction", "inequalityConstraintFunction", and "interimFunction" cannot be modified.
    - The content (body) of these four functions should be modified accordingly with the problem.
    - The equality and inequality constraint functions should be written through either switch or if-else if statements that counts for the
    "selection" parameter. The count starts from 0.
    - As long as the prefined four functions declarations are not modified, any desired member functions and variables can be defined
    inside the class. For an example, refer to "RoboticArmProblemDescription.hpp"
*/

class /*<Name Of Your Problem Object>*/ : public ProblemDescriptionCore {

public:
    /// @brief The cost function should return only non-negative real numbers.
    /// @param x Optimization parameters.
    /// @return Total absolute cost.
    double costFunction (const Eigen::VectorXd& x) override {
        /* code */
        return /* result */;
    }

    /// @brief Equality constraint functions. The constraints should be implemented in a switch-case environment starting from zero.
    /// @param x Optimization parameters.
    /// @param selection A mandatory parameter for multiple constraints to iterate through a switch statement.
    /// @return Result of the selected function.
    double equalityConstraintFunction (const Eigen::VectorXd& x, unsigned int selection = 0) override {
        switch (selection) {
            case 0:                 // The first equality constraint function.
            {
                /* code */
                return /* result */;
            }
            case 1:                 // The second equality constraint function.
            {
                /* code */
                return /* result */;
            }
                                    // Goes up to the n^th equality constraint function.
        }
        return 0;
    }

    /// @brief Inequality constraint functions. The constraints should be implemented in a switch-case environment starting from zero.
    /// @param x Optimization parameters.
    /// @param selection A mandatory parameter for multiple constraints to iterate through a switch statement.
    /// @return Result of the selected function.
    double inequalityConstraintFunction (const Eigen::VectorXd& x, unsigned int selection = 0) override {
        switch (selection) {
            case 0:                 // The first inequality constraint function.
            {
                /* code */
                return /* result */;
            }
            case 1:                 // The second inequality constraint function.
            {
                /* code */
                return /* result */;
            }
                                    // Goes up to the n^th inequality constraint function.
        }
        return 0;
    }

    /// @brief An interim function that is called once per outer iteration. This function an be used for occasional parameter updates. This function does not go into gradient estimation.
    /// @param x Optimization parameters.
    void interimFunction (const Eigen::VectorXd& x) override {
        /* code */
    }

};