#include "onvif_nvt.h"
#include "gtkstyledimage.h"

extern char _binary_microphone_png_size[];
extern char _binary_microphone_png_start[];
extern char _binary_microphone_png_end[];

gboolean toggle_mic_cb (GtkWidget *widget, gpointer * p, RtspPlayer * player){
    if(RtspPlayer__is_mic_mute(player)){
        RtspPlayer__mic_mute(player,FALSE);
    } else {
        RtspPlayer__mic_mute(player,TRUE);
    }
    return FALSE;
}

GtkWidget * create_controls_overlay(RtspPlayer *player){ 
    GtkWidget * image = GtkStyledImage__new((unsigned char *)_binary_microphone_png_start, _binary_microphone_png_end - _binary_microphone_png_start, 20, 20, NULL);

    GtkWidget * widget = gtk_button_new ();
    g_signal_connect (widget, "button-press-event", G_CALLBACK (toggle_mic_cb), player);
    g_signal_connect (widget, "button-release-event", G_CALLBACK (toggle_mic_cb), player);
    gtk_button_set_image (GTK_BUTTON (widget), image);

    GtkWidget * fixed = gtk_fixed_new();
    gtk_fixed_put(GTK_FIXED(fixed),widget,10,10); 

    return fixed;
}

GtkWidget * OnvifNVT__create_ui (RtspPlayer * player){
    GtkWidget *grid;
    GtkWidget *widget;

    grid = gtk_grid_new ();
    widget = RtspPlayer__createCanvas(player);
    gtk_widget_set_vexpand (widget, TRUE);
    gtk_widget_set_hexpand (widget, TRUE);

    gtk_grid_attach (GTK_GRID (grid), widget, 0, 1, 1, 1);

    GtkCssProvider * cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(cssProvider, "* { background-image:none; background-color:black;}",-1,NULL); 
    GtkStyleContext * context = gtk_widget_get_style_context(grid);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(cssProvider),GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref (cssProvider);  

    GtkWidget * overlay =gtk_overlay_new();
    gtk_container_add (GTK_CONTAINER (overlay), grid);

    widget = create_controls_overlay(player);

    gtk_overlay_add_overlay(GTK_OVERLAY(overlay),widget);
    return overlay;
}

