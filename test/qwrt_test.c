#include <ctest.h>
#include <qwrt.h>

CTEST(qwrt_suite, zero)
{
    const double a = 0, b = 0, c = 0;
    double d, x1, x2;

    const int result = qwrt(a, b, c, &d, &x1, &x2), exp_result = -1;

    ASSERT_EQUAL(exp_result, result);
}

CTEST(qwrt_suite, neg_disc)
{
    const double a = 4, b = 0, c = 3;
    double d, x1, x2;

    const int result = qwrt(a, b, c, &d, &x1, &x2), exp_result = 0;
    const double exp_disc = -48;

    ASSERT_EQUAL(exp_result, result);
    ASSERT_DBL_NEAR(exp_disc, d);
}

CTEST(qwrt_suite, one_root)
{
    const double a = 1, b = -2, c = 1;
	double d, x1, x2;

    const int result = qwrt(a, b, c, &d, &x1, &x2), exp_result = 1;
    const double exp_disc = 0, exp_x1 = 1;

    ASSERT_EQUAL(exp_result, result);
    ASSERT_DBL_NEAR(exp_disc, d);
    ASSERT_DBL_NEAR(exp_x1, x1);
}

CTEST(qwrt_suite, two_roots)
{
    const double a = 2, b = -3, c = 1;
    double d, x1, x2;
    
    const int result = qwrt(a, b, c, &d, &x1, &x2), exp_result = 2;
    const double exp_disc = 1, exp_x1 = 1, exp_x2 = 0.5;

    ASSERT_EQUAL(exp_result, result);
    ASSERT_DBL_NEAR(exp_disc, d);
    ASSERT_DBL_NEAR(exp_x1, x1);
    ASSERT_DBL_NEAR(exp_x2, x2);
}
