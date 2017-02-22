#include <CUnit/Basic.h>
#include "test_envdata.h"


int main() {
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	  return CU_get_error();

	/* Example test suite */
		CU_pSuite p_envdata_suite = NULL;

		/* add a suite to the registry */
		p_envdata_suite = CU_add_suite("Environment data test suite", NULL, NULL);
		if (NULL == p_envdata_suite) {
		  CU_cleanup_registry();
		  return CU_get_error();
		}

		/* add the tests to the suite */
		if ((NULL == CU_ADD_TEST(p_envdata_suite, tc_CreateEnvironmentData__upround_pos)))
		{
		  CU_cleanup_registry();
		  return CU_get_error();
		}
		/* add the tests to the suite */
		if ((NULL == CU_ADD_TEST(p_envdata_suite, tc_CreateEnvironmentData__downround_pos)))
		{
		  CU_cleanup_registry();
		  return CU_get_error();
		}
		/* add the tests to the suite */
		if ((NULL == CU_ADD_TEST(p_envdata_suite, tc_CreateEnvironmentData__upround_neg)))
		{
		  CU_cleanup_registry();
		  return CU_get_error();
		}
		/* add the tests to the suite */
		if ((NULL == CU_ADD_TEST(p_envdata_suite, tc_CreateEnvironmentData__downround_neg)))
		{
		  CU_cleanup_registry();
		  return CU_get_error();
		}


	/* Your test suite */


	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
