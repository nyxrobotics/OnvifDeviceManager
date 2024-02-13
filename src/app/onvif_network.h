#ifndef ONVIF_NETWORK_H_ 
#define ONVIF_NETWORK_H_

#include <gtk/gtk.h>
#include "onvif_app.h"
#include "omgr_device_row.h"

typedef struct _OnvifNetwork OnvifNetwork;

OnvifNetwork * OnvifNetwork__create();
void OnvifNetwork__destroy(OnvifNetwork* self);
void OnvifNetwork_update_details(OnvifNetwork * self, OnvifMgrDeviceRow * device);
void OnvifNetwork_clear_details(OnvifNetwork * self);
GtkWidget * OnvifNetwork__get_widget (OnvifNetwork * self);
void OnvifNetwork__set_done_callback(OnvifNetwork* self, void (*done_callback)(OnvifNetwork *, void *), void * user_data);

#endif