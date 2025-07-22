#include "calculator.h"
#include "gtest/gtest.h"

namespace {
class CalculatorTest : public ::testing::Test {
public:
	Calculator gCalculator;

protected:
	CalculatorTest() {
		// You can do set-up work for each test here.
	}

	virtual ~CalculatorTest() {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	virtual void SetUp() {
		std::cout << "Setup" << std::endl;
	}

	virtual void TearDown() {
		std::cout << "TearDown" << std::endl;
	}
	
};

TEST_F(CalculatorTest, Add) {
	EXPECT_EQ(gCalculator.add(1, 2), 3);
	EXPECT_EQ(gCalculator.add(-1, -2), -3);
	EXPECT_EQ(gCalculator.add(0, 0), 0);
	EXPECT_EQ(gCalculator.add(100, 200), 300);
}

TEST_F(CalculatorTest, Subtract) {
	EXPECT_EQ(gCalculator.subtract(5, 3), 2);
	EXPECT_EQ(gCalculator.subtract(-1, -1), 0);
	EXPECT_EQ(gCalculator.subtract(0, 0), 0);
	EXPECT_EQ(gCalculator.subtract(100, 50), 50);
}

TEST_F(CalculatorTest, Multiply) {
	EXPECT_EQ(gCalculator.multiply(2, 3), 6);
	EXPECT_EQ(gCalculator.multiply(-1, -1), 1);
	EXPECT_EQ(gCalculator.multiply(0, 100), 0);
	EXPECT_EQ(gCalculator.multiply(10, 10), 100);
}

TEST_F(CalculatorTest, Divide) {
	EXPECT_EQ(gCalculator.divide(6, 3), 2);
	EXPECT_EQ(gCalculator.divide(-6, -3), 2);
	EXPECT_EQ(gCalculator.divide(0, 1), 0);
	EXPECT_THROW(gCalculator.divide(1, 0), std::invalid_argument);
}

} // namespace

int main(int argc, char **argv) {
	std::cout << "Jenkins and Github CLI" << std::endl;
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
