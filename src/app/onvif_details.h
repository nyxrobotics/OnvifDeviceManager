#ifndef ONVIF_DETAILS_H_ 
#define ONVIF_DETAILS_H_

#include "omgr_device_row.h"
#include "onvif_app.h"

typedef struct _OnvifDetails OnvifDetails;

OnvifDetails * OnvifDetails__create(OnvifApp * app);
void OnvifDetails__destroy(OnvifDetails* self);
void OnvifDetails__set_details_loading_handle(OnvifDetails * self, GtkWidget * widget);
void OnvifDetails__update_details(OnvifDetails * self, OnvifMgrDeviceRow * device);
void OnvifDetails__clear_details(OnvifDetails * self);
GtkWidget * OnvifDetails__get_widget(OnvifDetails * self);

#endif