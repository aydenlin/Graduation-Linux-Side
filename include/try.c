#include <stdio.h>
#include "tools.h"

void work();
struct try {
	void (*work)();
};

int main() {
	struct try tt;
	tt.work = work;
	if (container_of(&tt.work, struct try, work) == &tt)
		printf("true\n");
	else 
		printf("false\n");
	return 0;
}

void work() {
	printf("work...\n");
}
