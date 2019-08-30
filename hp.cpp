#include "hp.h"
void hpdraintime(int* HP)
{
    *HP= *HP-10;//уменьшает хп со временем
}
void hpdrainmiss(int* HP)
{
    *HP=*HP-10000;//уменьшает хп при промахе
}
void hplife(int* HP)
{
    if((*HP+15000)>100100)*HP=100001;
    else
    *HP=*HP+15000;//прибавляет хп за попадание

}
