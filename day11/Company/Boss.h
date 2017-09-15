/*
 * Boss.h
 *
 *  Created on: 2017-9-1
 *      Author: sq
 */

#ifndef BOSS_H_
#define BOSS_H_

#include "SaleManager.h"
#include "TecManager.h"

class Boss: public SaleManager, public TecManager
{
public:
	Boss(string strName = "Boss");
	virtual ~Boss();

	static short bossFace();

	void info();

	//对技术经理增删改查
	void addTecManager();
	void delTecManager(uint uiId = 0);
	void modifyTecManager(uint uiId = 0);
	TecManager* findTecManager(uint uiId = 0);
	void displayTecManager();

	//对销售经理增删改查
	void addSaleManager();
	void delSaleManager(uint uiId = 0);
	void modifySaleManager(uint uiId = 0);
	TecManager* findSaleManager(uint uiId = 0);
	void displaySaleManager();

	void work();
};

#endif /* BOSS_H_ */
