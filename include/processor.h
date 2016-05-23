#ifndef _PROCESSOR_H_
#define _PROCESSOR_H_

#include "types.h"
#include "network.h"
#include "location.h"
#include "certification.h"

typedef struct processor Processor;

typedef byte * Processor_work_obtain(Network *network);
typedef void Certification_info_saving(Certification_info *C, 
		Certifi_struct *cs);
typedef void Location_info_saving(Location *L, Location_struct *ls);
typedef void Control_message_gene(Network *network, int flag);
typedef void Processing(byte *packet);

byte * processor_work_obtain(Network *network);
void certification_info_saving(Certification_info *C, 
	 Certifi_struct *cs);
void location_info_saving(Location *L, Location_struct *ls);
void control_message_gene(Network *network, int flag);
void processing(Network *network, Database_manager *dbmanager,
		Certification_info *certifi, Location *loc);

typedef struct processor {
	byte *packet;
	Processor_work_obtain *processor_work_obtain(Network *network);
	Certification_info_saving *certification_info_saving;
	Location_info_saving *location_info_saving;
	Control_message_gene *control_message_gene;
	Processing *processing;
} Processor;

#endif /* _PROCESSOR_H_ */
