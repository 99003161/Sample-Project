#include "unity.h"
#include "kirana.h"

//Required by the test unity framework
void setUp() {}

//Required by the unity framework
void tearDown() {}

void test_functions(void)
{
    TEST_ASSERT_EQUAL(1400.0, transact(1,500.0,900.0));
    TEST_ASSERT_EQUAL(400.5, transact(2,500.5,901.0));

}

int test_main(void)
{
    //Initiating the unity framework
    UNITY_BEGIN();
    RUN_TEST(test_functions);
    return UNITY_END();
}
