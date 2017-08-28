#include "girl.h"
#include "boy.h"

int main(void)
{
	Girl g("西施", "888888888");
	Boy b("小明");
	b.getGirlName(g);
	b.getGirlPhone(g);

	return 0;
}
