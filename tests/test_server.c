#include <stdarg.h>
#include <stddef.h>
// #include <sdtint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../server.h"

static void null_test_success(void **state);

static void null_test_success(void **state) {
(void) state; /* unused */
}

int main()
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);

    return 0;
}
