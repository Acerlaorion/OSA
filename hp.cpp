#include "hp.h"
void hpdraintime(int* HP)
{
    *HP= *HP-10;//��������� �� �� ��������
}
void hpdrainmiss(int* HP)
{
    *HP=*HP-10000;//��������� �� ��� �������
}
void hplife(int* HP)
{
    if((*HP+15000)>100100)*HP=100001;
    else
    *HP=*HP+15000;//���������� �� �� ���������

}
