#include <stdio.h>
#include <stdlib.h>
#include "cannon.h"

#define EXPECTED_NUMBER_OF_ARGUMENTS 3

typedef struct Arguments {
    double initialVelocity;
    double initialDegree;
    double timePeriod;
} Arguments;

Arguments ProcessArguments(int numberOfArguments, char *argumentArray[]) {
    if (numberOfArguments != EXPECTED_NUMBER_OF_ARGUMENTS) {
        fprintf(stderr, "Unexpected number of arguments. Expected %d, got %d", EXPECTED_NUMBER_OF_ARGUMENTS,
                numberOfArguments);
    }
    Arguments arguments = {
            .initialVelocity = strtod(argumentArray[1], NULL),
            .initialDegree = strtod(argumentArray[2], NULL),
            .timePeriod = strtod(argumentArray[3], NULL)
    };
    return arguments;
}

int main(int argc, char *argv[]) {
    Arguments arguments = ProcessArguments(argc - 1, argv);
    initialSpeed = ConvertToVector(arguments.initialVelocity, arguments.initialDegree);
    double ballHeight = 0, time = 0;
    while (ballHeight >= 0) {
        State state = GetStateAt(time);
        time += arguments.timePeriod;
        ballHeight = state.position.y;
        double distanceFromCannon = GetLengthOfVector(state.position);
        printf("x: %.2f y: %.2f distance: %.2f\n", state.position.x, state.position.y, distanceFromCannon);
    }

    return 0;
}