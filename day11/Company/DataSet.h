/*
 * DataSet.h
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#ifndef DATASET_H_
#define DATASET_H_

#include <iostream>
#include <map>

#include "TecPartTime.h"
#include "TecManager.h"

using namespace std;

typedef map<uint, TecPartTime *> MAP_TECPART;
typedef pair<uint, TecPartTime *> PAIR_TECPART;

typedef map<uint, TecManager *> MAP_TECMA;
typedef pair<uint, TecManager *> PAIR_TECMA;

class DataSet {
public:
	DataSet();
	virtual ~DataSet();

	static DataSet &getInstance();
	MAP_TECPART &getTecPartMap();

private:
	MAP_TECPART m_tecPartTimeMap;
	MAP_TECMA m_tecManagerMap;
};

#endif /* DATASET_H_ */
