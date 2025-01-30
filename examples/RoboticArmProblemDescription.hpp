#include <eigen3/Eigen/Dense>
#include "ProblemDescriptionCore.hpp"

#pragma once

class RoboticArmProblemDescription : public ProblemDescriptionCore {

public:

    // Some additional system parameters can also be defined inside the problem description
    Eigen::VectorXd gravityVec{Eigen::VectorXd::Zero(3)};
    Eigen::VectorXd endEffectorPositionVec{Eigen::VectorXd::Zero(2)};

    // Some additional utility functions can also be defined inside the problem description.
    // Here the users may also call rigid body dynamics algorithms such as Pinocchio, RBDL, or any other.
    inline void updateGravityVector (const Eigen::VectorXd& x) {
        gravityVec[0] = 2.5*cos(x[0]) +         1.5*cos(x[0] + x[1]) +          0.5*cos(x[0] + x[1] + x[2]);
        gravityVec[1] =                         1.5*cos(x[0] + x[1]) +          0.5*cos(x[0] + x[1] + x[2]);
        gravityVec[2] =                                                         0.5*cos(x[0] + x[1] + x[2]);
    }
    inline void updateEndEffectorPosition (const Eigen::VectorXd& x) {
        endEffectorPositionVec[0] = cos(x[0]) + cos(x[0] + x[1]) + cos(x[0] + x[1] + x[2]);
        endEffectorPositionVec[1] = sin(x[0]) + sin(x[0] + x[1]) + sin(x[0] + x[1] + x[2]);
    }

    /* THE FOLLOWING PART IS THE SAME */

    /// @brief The cost function should return only non-negative real numbers.
    /// @param x Optimization parameters.
    /// @return Total absolute cost.
    double costFunction (const Eigen::VectorXd& x) override {
        updateGravityVector(x);
        return gravityVec.transpose()*gravityVec;
    }

    /// @brief Equality constraint functions. The constraints should be implemented in a switch-case environment starting from zero.
    /// @param x Optimization parameters.
    /// @param selection A mandatory parameter for multiple constraints to iterate through a switch statement.
    /// @return Result of the selected function.
    double equalityConstraintFunction (const Eigen::VectorXd& x, unsigned int selection = 0) override {
        switch (selection) {
            case 0:
            {
                updateEndEffectorPosition(x);
                return endEffectorPositionVec[0]+1.0;
            }
            case 1:
            {
                updateEndEffectorPosition(x);
                return endEffectorPositionVec[1]-0.0;
            }
        }
        return 0;
    }

    /// @brief Inequality constraint functions. The constraints should be implemented in a switch-case environment starting from zero.
    /// @param x Optimization parameters.
    /// @param selection A mandatory parameter for multiple constraints to iterate through a switch statement.
    /// @return Result of the selected function.
    double inequalityConstraintFunction (const Eigen::VectorXd& x, unsigned int selection = 0) override {
        return 0;
    }

    /// @brief An interim function that is called once per outer iteration. Can be used for occasional parameter updates. This function does not go into gradient estimation.
    /// @param x Optimization parameters.
    void interimFunction (const Eigen::VectorXd& x) override {}

};