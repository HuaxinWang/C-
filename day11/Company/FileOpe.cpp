/*
 * FileOpe.cpp
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#include "FileOpe.h"

#include "DataSet.h"

FileOpe::FileOpe() {
	// TODO Auto-generated constructor stub

}

FileOpe::~FileOpe() {
	// TODO Auto-generated destructor stub
}

void FileOpe::writeDataToFile() {
	MAP_TECPART &tecPart = DataSet::getInstance().getTecPartMap();
	//循环写入文件
}
void FileOpe::getDataFromFile() {
	MAP_TECPART &tecPart = DataSet::getInstance().getTecPartMap();
	//将文件中数据读取出来放入容器
}

