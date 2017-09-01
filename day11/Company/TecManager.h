/*
 * TecManager.h
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#ifndef TECMANAGER_H_
#define TECMANAGER_H_

#include "TecPartTime.h"

class TecManager: public TecPartTime {
public:
	TecManager(string strName = "NewTecMa", float fSalary = 10000);
	virtual ~TecManager();

	//显示信息
	void info();
	//对员工的增删改查
	void addTecPartTime();

private:
	float m_fSalary;
};

#endif /* TECMANAGER_H_ */
