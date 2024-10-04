#ifndef __LIBPDNOTIFIER__
#define __LIBPDNOTIFIER__
#include <stdint.h>
#include <service_registry_notifier_v01.h>

#define MAX_CLIENT_NAME_LEN 32

typedef enum pd_event {
	EVENT_PD_DOWN = 0x0FFFFFFF,
	EVENT_PD_UP = 0x1FFFFFFF,
	EVENT_PD_UNKNOWN = 0xFFFFFFFF,
} pd_event;

typedef enum pd_rcode {
	PD_NOTIFIER_SUCCESS = 0,
	PD_NOTIFIER_FAIL,
	PD_NOTIFIER_ERR_ARG_INVALID,
	PD_NOTIFIER_ERR_OVERFLOW,
	PD_NOTIFIER_ERR_QMI,
	PD_NOTIFIER_ERR_NO_SERVER,
} pd_rcode;

typedef qmi_servreg_notif_service_state_enum_type_v01 pd_state;
typedef void (*pd_notifier_cb) (void *, enum pd_event);
typedef struct PD_Notifier_Handle PD_Notifier_Handle;

int pd_notifier_enabled();
PD_Notifier_Handle *pd_notifier_alloc(char *serviceName, char *clientName, uint32_t instance, pd_notifier_cb cb, void *user_data);

pd_rcode pd_notifier_register(PD_Notifier_Handle *hndl, pd_state *state);
pd_rcode pd_notifier_deregister(PD_Notifier_Handle *hndl);
pd_rcode pd_notifier_free(PD_Notifier_Handle *hndl);
pd_rcode pd_notifier_restart_pd(PD_Notifier_Handle *hndl);

#endif /* __LIBPDNOTIFIER__ */
