#ifndef __LIBPDMAPPER__
#define __LIBPDMAPPER__
#include <stdint.h>

typedef struct SR_DL_Handle SR_DL_Handle;

typedef enum SR_Result_Enum {
	SR_RESULT_SUCCESS = 0,
	SR_RESULT_FAIL,
	SR_RESULT_ERR_QMI,
	SR_RESULT_ERR_ARG_INVALID,
	SR_RESULT_ERR_OVERFLOW,
} SR_Result_Enum;

int servreg_is_enabled();
SR_DL_Handle *servreg_alloc_DLHandle();
void servreg_free_DLHandle(SR_DL_Handle *handle);
SR_Result_Enum servreg_get_domainlist(char *service, SR_DL_Handle *handle);
int servreg_get_numentries(SR_DL_Handle *handle);
SR_Result_Enum servreg_get_data_for_notifier(SR_DL_Handle *handle, char **notifier_string, int *instance, uint32_t entry_number);
SR_Result_Enum servreg_get_entry(SR_DL_Handle *handle, char **buffer, int *instance, int *service_data_valid, int *service_data, uint32_t entry_number);
#endif /* __LIBPDMAPPER__ */
