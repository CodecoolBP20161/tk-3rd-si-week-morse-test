#include <CUnit/Basic.h>
#include "test_envdata.h"
#include "../src/selfprot.h"

int init_envdata_suite(void) {
	return 0;
}

int tc_CreateEnvironmentData__upround_pos(void) {
	/* Call the testable function */
	EnvironmentData data = CreateEnvironmentData(0.15, 0.26, 0.37, 0);

	/* Check the result */
	CU_ASSERT_EQUAL(data.acc_x, 2);
	CU_ASSERT_EQUAL(data.acc_y, 3);
	CU_ASSERT_EQUAL(data.acc_z, 4);
	CU_ASSERT_EQUAL(data.temp, 0);

	return 0;
}

int tc_CreateEnvironmentData__downround_pos(void) {
	/* Call the testable function */
	EnvironmentData data = CreateEnvironmentData(0.249, 0.3499, 0.44999, 100);

	/* Check the result */
	CU_ASSERT_EQUAL(data.acc_x, 2);
	CU_ASSERT_EQUAL(data.acc_y, 3);
	CU_ASSERT_EQUAL(data.acc_z, 4);
	CU_ASSERT_EQUAL(data.temp, 100);

	return 0;
}

/**
 * This test case will fails because rounding not works for negative numbers in this implementation
 */
int tc_CreateEnvironmentData__downround_neg(void) {
	/* Call the testable function */
	EnvironmentData data = CreateEnvironmentData(-0.15, -0.26, -0.37, -10);

	/* Check the result */
	CU_ASSERT_EQUAL(data.acc_x, -2);
	CU_ASSERT_EQUAL(data.acc_y, -3);
	CU_ASSERT_EQUAL(data.acc_z, -4);
	CU_ASSERT_EQUAL(data.temp, -10);

	return 0;
}

/**
 * This test case will fails because rounding not works for negative numbers in this implementation
 */
int tc_CreateEnvironmentData__upround_neg(void) {
	/* Call the testable function */
	EnvironmentData data = CreateEnvironmentData(-0.249, -0.3499, -0.44999, -50);

	/* Check the result */
	CU_ASSERT_EQUAL(data.acc_x, -2);
	CU_ASSERT_EQUAL(data.acc_y, -3);
	CU_ASSERT_EQUAL(data.acc_z, -4);
	CU_ASSERT_EQUAL(data.temp, -50);

	return 0;
}
