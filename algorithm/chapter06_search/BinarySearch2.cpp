#include "stdlib.h"
#include "stdio.h"

typedef struct {
    int number;
    double score;
} Score;

Score DataSet[] =
        {
                1, 877.18,
                2, 176.23,
                3, 3422.23,
                4, 123.23,
                5, 173.23,
                6, 476.23,
                7, 156.23,
                8, 671.78
        };


int compareScore(const void *_elem1, const void *_elem2) {
    Score *elem1 = (Score *) _elem1;
    Score *elem2 = (Score *) _elem2;

    if (elem1->score > elem2->score) {
        return 1;
    } else if (elem1->score < elem2->score) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int len = sizeof(DataSet) / sizeof(DataSet[0]);
    Score target;
    Score *found = NULL;

    qsort((void *) DataSet, len, sizeof(Score), compareScore);

    target.number = 0;
    target.score = 671.78;

    found = static_cast<Score *>(bsearch(
            (void *) &target,
            (void *) DataSet,
            len,
            sizeof(Score),
            compareScore));

    printf("found : %d %f \n", found->number, found->score);
    return 0;
}