#ifndef ENUMS
#define ENUMS

typedef enum
{
    LEFT_ROOT_RIGHT,
    RIGHT_ROOT_LEFT,
    ROOT_LEFT_RIGHT,
    ROOT_RIGHT_LEFT,
    LEFT_RIGHT_ROOT,
    RIGHT_LEFT_ROOT

} Traversal;

typedef enum
{
    EMPTY = -1,
    ID = 0,
    AVG_GRADE = 1,
    NAME = 2,
    SURNAME = 3,
    UNIVERSITY = 4,
    NUMBERS = 5
} Key;

#endif