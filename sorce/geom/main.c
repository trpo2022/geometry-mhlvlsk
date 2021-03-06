#include "lib/point.h"
#include "lib/triangle.h"
#include "lib/circle.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inputread.h"

int main()
{
  char* input = malloc(sizeof(char) * 32);
    initInput(input);
    char delims[] = "( ,)";
    char* token = strtok(input, delims);
    if (strcmp(token, "circle") == 0) {
        printf("\n%s:\n", token);
        struct Point p;
        p.x = atof(strtok(NULL, delims));
        p.y = atof(strtok(NULL, delims));
        float radius = atof(strtok(NULL, delims));
        CircleInfo(p.x, p.y,radius);
    } else if (strcmp(token, "triangle") == 0) {
        printf("\n%s:\n", token);
        struct Point points[4];
        for (int i = 0; i < 4; i++) {
            points[i].x = atof(strtok(NULL, delims));
            points[i].y = atof(strtok(NULL, delims));
        }
        if (points[3].x != points[0].x || points[3].y != points[0].y) {
            printf("Ошибка обработки крайних точек в треугольнике.\nПроверьте введенные данные.\n");
        }
        TriangleInfo(points);
    } else if (strcmp(token, "q") == 0) {
        return 0;
    } else {
        printf("Введены неверные данные.\n");
    }
    free(input);
  return 0;
}

