/*
 * DataSet.cpp
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#include "DataSet.h"

DataSet::DataSet() {
	// TODO Auto-generated constructor stub

}

DataSet::~DataSet() {
	// TODO Auto-generated destructor stub
}

DataSet &DataSet::getInstance() {
	static DataSet data;
	return data;
}

MAP_TECPART &DataSet::getTecPartMap() {
	return m_tecPartTimeMap;
}







