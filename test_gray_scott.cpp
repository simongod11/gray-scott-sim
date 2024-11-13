#include <gtest/gtest.h>
#include "../gray_scott.h"  // 假设主代码在 src 文件夹中

// 1
TEST(GrayScottTest, ParameterTypeMatch) {
    GrayScottModel model;
    ASSERT_TRUE((std::is_same<decltype(model.F), decltype(model.u[0])>::value));
    ASSERT_TRUE((std::is_same<decltype(model.k), decltype(model.v[0])>::value));
}

// 2
TEST(GrayScottTest, VectorSizeMatch) {
    GrayScottModel model;
    ASSERT_EQ(model.u.size(), model.v.size());
}

// 3
TEST(GrayScottTest, EvolutionEquation) {
    GrayScottModel model;
    model.u.assign(model.u.size(), 0);
    model.v.assign(model.v.size(), 0);
    model.evolve(); 
    for (const auto& value : model.u) {
        ASSERT_EQ(value, 0);  
    }
    for (const auto& value : model.v) {
        ASSERT_EQ(value, 0);
    }
}

// 4
TEST(GrayScottTest, DeterministicSimulation) {
    GrayScottModel model;
    model.setParameters(0.04, 0.06);  
    model.evolve();  
    auto u_snapshot = model.u;
    model.evolve();  
    ASSERT_EQ(u_snapshot, model.u);
}
