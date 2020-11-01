#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <limits.h>
#include <gtk/gtk.h>


#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define GUI_UPDATE_PERIOD   50


GtkWindow * window;
GtkWidget * label;
GtkWidget * label2;
GtkWidget * button;
GtkWidget * button2;
GtkWidget * mainbox;
GtkWidget * box1;
GtkWidget * box2;
GtkWidget * lab_atk;
GtkWidget * lab_atk_val;
GtkWidget * lab_sus;
GtkWidget * lab_sus_val;
GtkWidget * lab_dec;
GtkWidget * lab_dec_val;
GtkWidget * lab_rel;
GtkWidget * lab_rel_val;
GtkWidget * lab_adsr_state;

uint8_t voices = 0;
uint32_t atk = 0;
uint32_t sus = 0;
uint32_t dec = 0;
uint32_t rel = 0;

static void callback( GtkWidget *widget,
                      gpointer   data )
{

}

static void callback2( GtkWidget *widget,
                      gpointer   data )
{
    //app crash due to g_print
    //g_print ("Hello again - %s was pressed\n", (gchar *) data);
}

gboolean periodic_handler(GtkWidget * win)
{
    //if (win->window == NULL) return FALSE;

    //   GDateTime *now = g_date_time_new_now_local(); 
    //   gchar *my_time = g_date_time_format(now, "%H:%M:%S");
  
    //   g_sprintf(buf, "%s", my_time);
  
    //   g_free(my_time);
    //   g_date_time_unref(now);

    //voices = sampler->active_voice;
    char test_text[4] = {0};
    sprintf(&test_text, "%d", voices);

    gtk_label_set_text(label2, &test_text);
    gtk_widget_show(label2);

    //atk = sampler->adsr_filters[0].atk_len;
    //sus = sampler->adsr_filters[0].sus_len;
    //dec = sampler->adsr_filters[0].dec_len;
    //rel = sampler->adsr_filters[0].rel_len;
    
    sprintf(&test_text, "0000");
    sprintf(&test_text, "%d", atk);

    gtk_label_set_text(lab_atk_val, &test_text);
    gtk_widget_show(lab_atk_val);

    sprintf(&test_text, "0000");
    sprintf(&test_text, "%d", sus);

    gtk_label_set_text(lab_sus_val, &test_text);
    gtk_widget_show(lab_sus_val);

    sprintf(&test_text, "0000");
    sprintf(&test_text, "%d", dec);

    gtk_label_set_text(lab_dec_val, &test_text);
    gtk_widget_show(lab_dec_val);

    sprintf(&test_text, "0000");
    sprintf(&test_text, "%d", rel);

    gtk_label_set_text(lab_rel_val, &test_text);
    gtk_widget_show(lab_rel_val);

    //if(sampler->envelope_type == ENVELOPE_TYPE_ADSR) gtk_label_set_text(lab_adsr_state, "ADSR");
    //else if(sampler->envelope_type == ENVELOPE_TYPE_ONE_SHOT) gtk_label_set_text(lab_adsr_state, "One-Shot");

    gtk_widget_queue_draw(win);
  
    return TRUE;
}

int main(int argc, char **argv)
{
    //static int once = 1;
    guint threadID = 0;

    //gtk_set_locale();
    //set_theme_env();
    gtk_init(NULL, NULL);
    if(!gtk_init_check(NULL, NULL))
    {
        printf("error gtk_init()\n");
    }
   	
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Sample Tool v0");
  
    g_signal_connect(window, "destroy",
                        G_CALLBACK(gtk_main_quit), NULL);  

    mainbox = gtk_vbox_new(FALSE, 10);

    gtk_container_add(GTK_CONTAINER(window), mainbox);
    gtk_widget_show(mainbox);
    box1 = gtk_hbox_new (FALSE, 20);
    //box2 = gtk_vbox_new(FALSE, 0);

    // Put the box into the main window. 
    gtk_container_add (GTK_CONTAINER (mainbox), box1);
    
    char test[4] = {0};
    //sprintf(&test, "%d", voices);

    label2 = gtk_label_new(&test);
    gtk_box_pack_end(GTK_BOX(box1), label2, TRUE, TRUE, 0);
    gtk_widget_show(label2);

    label = gtk_label_new("sampler playing voices: ");
    gtk_box_pack_end(GTK_BOX(box1), label, TRUE, TRUE, 0);
    gtk_widget_show(label);
    // Creates a new button with the label "Button 1". 
    button = gtk_button_new_with_label ("Button 1");
    
    // Now when the button is clicked, we call the "callback" function
    // * with a pointer to "button 1" as its argument 
    g_signal_connect (button, "clicked",
		      G_CALLBACK (callback), (gpointer) "button 1");

    //  Instead of gtk_container_add, we pack this button into the invisible
    //  * box, which has been packed into the window. 
    gtk_box_pack_start (GTK_BOX(box1), button, TRUE, TRUE, 0);

    //  Always remember this step, this tells GTK that our preparation for
    //  * this button is complete, and it can now be displayed. 
    gtk_widget_show (button);

    //  Do these same steps again to create a second button 
    button2 = gtk_button_new_with_label ("Button 2");

    //  Call the same callback function with a different argument,
    //   passing a pointer to "button 2" instead. 
    g_signal_connect (button2, "clicked",
		      G_CALLBACK (callback2), (gpointer) "button 2");

    gtk_box_pack_start(GTK_BOX (box1), button2, TRUE, TRUE, 0);

    gtk_widget_show (button2);
    gtk_widget_show (box1);

    box2 = gtk_hbox_new (FALSE, 45);
    
    gtk_container_add (GTK_CONTAINER (mainbox), box2);
    //if(sampler->selected_adsr == 1) 
        lab_adsr_state = gtk_label_new("ADSR ON");
    //else if(sampler->selected_adsr == 0) 
    //    lab_adsr_state = gtk_label_new("ADSR OFF");

    gtk_box_pack_start(GTK_BOX(box2), lab_adsr_state, TRUE, TRUE, 0);
    gtk_widget_show(lab_adsr_state);

    lab_atk = gtk_label_new("Attack: ");
    lab_atk_val = gtk_label_new("0");
    lab_sus = gtk_label_new("Sustain: ");
    lab_sus_val = gtk_label_new("0");
    lab_dec = gtk_label_new("Decay: ");
    lab_dec_val = gtk_label_new("0");
    lab_rel = gtk_label_new("Release: ");
    lab_rel_val = gtk_label_new("0");

    gtk_box_pack_start(GTK_BOX(box2), lab_atk, TRUE, TRUE, 0);
    gtk_widget_show(lab_atk);
    gtk_box_pack_start(GTK_BOX(box2), lab_atk_val, TRUE, TRUE, 0);
    gtk_widget_show(lab_atk_val);

    gtk_box_pack_start(GTK_BOX(box2), lab_sus, TRUE, TRUE, 0);
    gtk_widget_show(lab_sus);
    gtk_box_pack_start(GTK_BOX(box2), lab_sus_val, TRUE, TRUE, 0);
    gtk_widget_show(lab_sus_val);
    
    gtk_box_pack_start(GTK_BOX(box2), lab_dec, TRUE, TRUE, 0);
    gtk_widget_show(lab_dec);
    gtk_box_pack_start(GTK_BOX(box2), lab_dec_val, TRUE, TRUE, 0);
    gtk_widget_show(lab_dec_val);
    
    gtk_box_pack_start(GTK_BOX(box2), lab_rel, TRUE, TRUE, 0);
    gtk_widget_show(lab_rel);
    gtk_box_pack_start(GTK_BOX(box2), lab_rel_val, TRUE, TRUE, 0);
    gtk_widget_show(lab_rel_val);
    
    gtk_widget_show (box2);
    //  The order in which we show the buttons is not really important, but I
    //   recommend showing the window last, so it all pops up at once. 

    gtk_widget_show_all(window);

    threadID = g_timeout_add(GUI_UPDATE_PERIOD, (GSourceFunc) periodic_handler, (gpointer) window);

    //while(!backend_ready) { usleep(200); }

    gtk_main();

    g_source_remove(threadID);

    //stool_shutdown(NULL);

    return 0;
}