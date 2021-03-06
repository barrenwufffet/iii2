/* Gavin Smith & Liam Durant
 * COMP 40
 * 2/12/18
 * bit2.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "bit.h"
#include "bit2.h"
#include "assert.h"

#define T Bit2_T

struct T {
        int height; 
        int width;
        Bit_T vex;
};

T Bit2_new (int width, int height) 
{
if (height * width == 0) {
assert(0);
}
  T uStruct = (T)malloc(16);
  assert(uStruct);
  uStruct->vex = Bit_new(height * width);
  uStruct->height = height;
  uStruct->width = width;
return uStruct;
} 

int Bit2_put(T bit2, int col, int row, int bitnum)
{
  return Bit_put(bit2->vex, row*(bit2->width) + col, bitnum);
}

int Bit2_get(T bit2, int col, int row)
{
  return Bit_get(bit2->vex, row*(bit2->width) + col);
}

int Bit2_width(T Bit2) {
         assert(Bit2);
         return Bit2->width; 
}
 
int Bit2_height(T Bit2) {
        assert(Bit2);
        return Bit2->height;
}

void Bit2_free(T * Bit2) {
Bit_free(&(*Bit2)->vex);
free(*Bit2);
}

void Bit2_map_row_major(T Bit2, void apply(int col, int row, T Bit2, 
int  bitval, void *cl), void *cl) 
{
assert(Bit2);
assert(apply);

for (int r = 0; r < Bit2->height; r++) {
        for (int c = 0; c < Bit2->width; c++) {
apply(c, r, Bit2, Bit2_get(Bit2, c, r), cl);
}
}

}

void Bit2_map_col_major(T Bit2, void apply(int col, int row,
T Bit2, int bitval, void *cl), void *cl) 
{
assert(Bit2);
assert(apply);

for (int c = 0; c < Bit2->width; c++) {
        for (int r = 0; r < Bit2->height; r++) {
printf("r: %d c: %d\n", c, r);
apply(c, r, Bit2, Bit2_get(Bit2, c, r), cl);
}
}

}


