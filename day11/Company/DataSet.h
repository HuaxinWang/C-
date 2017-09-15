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
#include "FileOpe.h"
#include "Boss.h"

using namespace std;

typedef map<uint, TecPartTime *> MAP_TECPART;
typedef pair<uint, TecPartTime *> PAIR_TECPART;

typedef map<uint, TecManager *> MAP_TECMA;
typedef pair<uint, TecManager *> PAIR_TECMA;

typedef map<uint, SalePartTime *> MAP_SALEPART;
typedef pair<uint, SalePartTime *> PAIR_SALEPART;

typedef map<uint, SaleManager *> MAP_SALEMA;
typedef pair<uint, SaleManager *> PAIR_SALEMA;

typedef map<uint, Boss *> MAP_BOSS;
typedef pair<uint, Boss *> PAIR_BOSS;

class DataSet
{
public:
	DataSet();
	virtual ~DataSet();

	static DataSet &getInstance();

	MAP_TECPART &getTecPartMap();
	MAP_TECMA &getTecManagerMap();

	MAP_SALEPART &getSalePartMap();
	MAP_SALEMA &getSaleManagerMap();

	MAP_BOSS &getBossMap();

private:
	MAP_TECPART m_tecPartTimeMap;
	MAP_TECMA m_tecManagerMap;

	MAP_SALEPART m_salePartTimeMap;
	MAP_SALEMA m_saleManagerMap;

	MAP_BOSS m_bossMap;
};

#endif /* DATASET_H_ */
