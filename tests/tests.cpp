#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Circle.h"

class MockCircle : public Circle {
public:
    MOCK_METHOD(double, radius, (), (const, override));
    MOCK_METHOD(Point, center, (), (const, override));
};

TEST(CircleTest, GetRadius) {
    MockCircle circle;
    EXPECT_CALL(circle, radius()).WillOnce(testing::Return(5.0));
    EXPECT_EQ(circle.radius(), 5.0);
}

TEST(CircleTest, GetCenter) {
    MockCircle circle;
    Point center{3.0, 4.0};
    EXPECT_CALL(circle, center()).WillOnce(testing::Return(center));
    EXPECT_EQ(circle.center().x, 3.0);
    EXPECT_EQ(circle.center().y, 4.0);
}

TEST(CircleTest, Constructor) {
    const double radius = 10.0;
    MockCircle circle(radius);
    EXPECT_EQ(circle.radius(), radius);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
