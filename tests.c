//
// Created by spinakker on 10/15/2019.
//

#include "tests.h"
#include "cannon.h"
#include "miniunit.h"
#include <stdio.h>
#include "math.h"

int tests_run = 0;

static char *test_initialState() {
    initialSpeed = (Vector) {.x = 0, .y = 0};
    State actualState = GetStateAt(0);
    int isZero = 1;
    isZero &= actualState.speed.x == 0;
    isZero &= actualState.speed.y == 0;
    isZero &= actualState.position.x == 0;
    isZero &= actualState.position.y == 0;

    mu_assert("error, initial state not 0", isZero == 1);
    return 0;
}

static char *test_ifBallFalls() {
    State actualState = GetStateAt(100);
    mu_assert("error, ball didn't fall down 0", actualState.position.y < 0);
    return 0;
}

static char *test_ifBallFlies() {
    initialSpeed = (Vector) {.x = 15, .y = 15};
    State actualState = GetStateAt(1);
    mu_assert("error, ball didn't fly", actualState.position.y > 0);
    return 0;
}

static char *test_deg2rad() {
    double degrees = 30;
    double rad = 0.523599;
    double actualRad = deg2rad(degrees);
    double diff = fabs(actualRad - rad);
    mu_assert("error, deg2rad not correct", diff < EPSILON);
    return 0;
}

static char *test_lengthOfVector() {
    Vector testVector = {.x = 4, .y = 3};
    double expectedLength = 5;
    double diff = fabs(GetLengthOfVector(testVector) - expectedLength);
    mu_assert("error, lengthOfVector not correect", diff < EPSILON);
    return 0;
}

static char *all_tests() {
    mu_run_test(test_initialState);
    mu_run_test(test_ifBallFalls);
    mu_run_test(test_ifBallFlies);
    mu_run_test(test_deg2rad);
    mu_run_test(test_lengthOfVector);
    return 0;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}