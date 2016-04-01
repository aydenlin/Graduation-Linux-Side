#ifndef _EXECUTOR_H_
#define _EXECUTOR_H_

#include "types.h"
#include "network.h"
#include "certification.h"
#include "location.h"
#include "packet.h"
#include "databse_manager.h"

typedef void Start(Network *network);

typedef struct executor {
	Start start;
} Executor;

typedef struct task {
	_TYPE_ data;
} Task;

void start(Network *network);

#endif /* _EXECUTOR_H_ */
