#ifndef DATA_H
#define DATA_H
#include "city.h"

typedef struct data{
	struct city *city;
} Data;

Data * initData(struct city * );
void * deleteData(Data *);

#endif