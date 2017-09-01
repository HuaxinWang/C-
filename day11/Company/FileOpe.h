/*
 * FileOpe.h
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#ifndef FILEOPE_H_
#define FILEOPE_H_

#include <iostream>
#include <fstream>

using namespace std;

class FileOpe {
public:
	FileOpe();
	virtual ~FileOpe();

	void writeDataToFile();
	void getDataFromFile();
};

#endif /* FILEOPE_H_ */
