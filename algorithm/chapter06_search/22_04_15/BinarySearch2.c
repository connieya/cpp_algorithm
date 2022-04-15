#include "stdlib.h"
#include "stdio.h"

typedef struct {
    int number;
    double score;
} Score;

Score DataSet[] =
        {
                1, 877.88,
                2, 377.88,
                3, 477.88,
                4, 177.78,
                5, 573.88,
                6, 231.82,
                7, 862.81,
                8, 177.79,
                9, 632.38,
                10, 175.88,
        };

int CompareScore(const void *_elem1, const void *_elem2) {
    Score *elem1 = (Score *) _elem1;
    Score *elem2 = (Score *) _elem2;

    if (elem1->score > elem2->score)
        return 1;
    else if (elem1->score < elem2->score)
        return -1;
    else
        return 0;
}

int main(void) {
    int Length = sizeof(DataSet) / sizeof(DataSet[0]);
    int i = 0;
    Score target;
    Score *found = NULL;
    qsort((void *) DataSet, Length, sizeof(Score), CompareScore);
    target.number = 3;
    target.score = 477.88;
    found = bsearch((void *) &target, (void *) DataSet, Length, sizeof(Score), CompareScore);
    printf("found : %d %f \n", found->number , found->score);
    return 0;
}