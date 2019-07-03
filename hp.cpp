#include "hp.h"
void hpdraintime(int* HP)
{
    *HP= *HP-1;
}
void hpdrainmiss(int* HP)
{
    *HP=*HP-10000;
}
void hplife(int* HP)
{
    *HP=*HP+20000;
}
