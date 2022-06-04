#include "inputread.h"
#include "lib/circle.h"
#include "lib/object.h"
#include "lib/point.h"
#include "lib/triangle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#123

void getObj(int i, object* obj)
{
    char* input = malloc(sizeof(char) * 32);
    char* token = NULL;
    initInput(input);
    char* delims = "( ,)";
    switch (check_object(input, &token)) {
    case 0:
        printf("\n%d. %s:\n", i, token);
        struct Circle circle;
        circle.center.x = atof(strtok(NULL, delims));
        circle.center.y = atof(strtok(NULL, delims));
        circle.radius = atof(strtok(NULL, delims));

        obj->circle = circle;
        obj->type = CIRCLE;
        printCircleInfo(circle);
        break;

    case 1:
        printf("\n%d. %s:\n", i, token);
        struct Triangle triangle;

        for (int i = 0; i < 4; i++) {
            triangle.points[i].x = atof(strtok(NULL, delims));
            triangle.points[i].y = atof(strtok(NULL, delims));
        }

        if (triangle.points[3].x != triangle.points[0].x
            || triangle.points[3].y != triangle.points[0].y) {
            printf("Ошибка обработки крайних точек в треугольнике.\nПроверьте "
                   "введенные данные.\n");
        }

        obj->triangle = triangle;
        obj->type = TRIANGLE;
        printTriangleInfo(triangle);
        break;

    default:
        printf("Введены неверные данные.\n");
    }
    free(input);
}

int main()
{
    object objects[3];
    for (int i = 0; i < 3; i++) {
        getObj(i + 1, &objects[i]);
    }
    return 0;
}
