#include "lib/circle.h"
#include "lib/point.h"
#include "lib/triangle.h"
#pragma once

typedef enum object_type { CIRCLE, TRIANGLE } object_type;
typedef struct object {
    struct Circle circle;
    struct Triangle triangle;
    object_type type;
} object;
int check_object(char* input, char** token);

