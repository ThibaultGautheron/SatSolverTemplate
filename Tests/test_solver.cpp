/**
* @author Tim Luchterhand
* @date 27.11.24
* @brief
*/

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Solver.hpp"

TEST(solver, initial_assignment) {
    using namespace sat;
    Solver solver(10);
    for (unsigned varId = 0; varId < 10; ++varId) {
        EXPECT_EQ(solver.val(varId), TruthValue::Undefined);
    }
}

TEST(solver, assign) {
    using namespace sat;
    Solver solver(10);
    EXPECT_TRUE(solver.assign(pos(4))) << "Assignment should be possible.";
    EXPECT_TRUE(solver.assign(neg(7))) << "Assignment should be possible.";
    for (unsigned varId = 0; varId < 10; ++varId) {
        if (varId == 4) {
            EXPECT_EQ(solver.val(varId), TruthValue::True);
        } else if (varId == 7) {
            EXPECT_EQ(solver.val(varId), TruthValue::False);
        } else {
            EXPECT_EQ(solver.val(varId), TruthValue::Undefined);
        }
    }
}

TEST(solver, double_assign) {
    using namespace sat;
    Solver solver(10);
    EXPECT_TRUE(solver.assign(pos(4))) << "Assignment should be possible.";
    EXPECT_TRUE(solver.assign(pos(4))) << " Double assignment of same literal should be possible.";
    EXPECT_FALSE(solver.assign(neg(4))) << "Assignment of negated literal should not be possible anymore.";
    for (unsigned varId = 0; varId < 10; ++varId) {
        if (varId == 4) {
            EXPECT_EQ(solver.val(varId), TruthValue::True);
        } else {
            EXPECT_EQ(solver.val(varId), TruthValue::Undefined);
        }
    }
}

TEST(solver, satisfied_falsified) {
    using namespace sat;
    Solver solver(10);
    for (unsigned varId = 0; varId < 10; ++varId) {
        EXPECT_FALSE(solver.satisfied(pos(varId))) << "Initial assignment must be undefined";
        EXPECT_FALSE(solver.falsified(pos(varId))) << "Initial assignment must be undefined";
        EXPECT_FALSE(solver.satisfied(neg(varId))) << "Initial assignment must be undefined";
        EXPECT_FALSE(solver.falsified(neg(varId))) << "Initial assignment must be undefined";
    }

    EXPECT_TRUE(solver.assign(pos(3)));
    EXPECT_TRUE(solver.satisfied(pos(3)));
    EXPECT_TRUE(solver.falsified(neg(3)));
    EXPECT_FALSE(solver.satisfied(neg(3)));
    EXPECT_FALSE(solver.falsified(pos(3)));
}

#ifndef __RUN_ALL_TESTS__

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif