/*
** EPITECH PROJECT, 2023
** password to be genarated.c
** File description:
** by cynthia zinsou
*/

#include "../include/password_generator.h"

char *my_strcat(char *dest, char const *src)
{
    int o = 0;
    int h = 0;
    int k = 0;
    int b = 0;
    char *both = NULL;

    h = strlen(dest);
    k = strlen(src);
    b = h + k;
    both = malloc(sizeof(char) * b + 1);
    strcpy(both, dest);
    for (o = 0; src[o] != '\0'; o++) {
        both[h] = src[o];
        h++;
    }
    both[h] = '\0';
    return (both);
}

char *password_generator(int pass_len)
{
  int counter = 0;
  int random = 0;
  char *characters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ:;~!@#$%^&*()_+=-[]{}\\',./<>?|";
  char *password = malloc(sizeof(char) * (pass_len + 1));

  srand(time(NULL));
  for (int count = 0; count < pass_len; count++){
    random = rand() % 92;
    password[count] = characters[random];
  }
  password[pass_len] = '\0';
  return password;
}

void disp_dialogue(gchar *message)
{
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, message);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void get_length_and_disp(GtkWidget *widget, gpointer pass)
{
  GtkEntry *entry = GTK_ENTRY(pass);
  const gchar *pass_len = gtk_entry_get_text(entry);
  int len = atoi(pass_len);
  char *password = password_generator(len);
  if (len < 8 || len > 20){
    disp_dialogue(WARNING);
    return;
  }
  char *message = "Here comes your password:\n";
  char *full_msg = my_strcat(message, password);
  disp_dialogue(full_msg);
}

void main(int ac, char **av)
{
  gtk_init(&ac, &av);
  GtkCssProvider *provider = gtk_css_provider_new();
  gtk_css_provider_load_from_data(provider, "window{background-color: lightskyblue;}", -1, NULL);
  gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "PasswordGenerator GUI");
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_container_add(GTK_CONTAINER(window), vbox);
  GtkWidget *image = gtk_image_new_from_file("pictures/password.png");
  gtk_box_pack_start(GTK_BOX(vbox), image, FALSE, FALSE, 10);
  GtkWidget *label = gtk_label_new("\n***Enter your PassWord Lenght***");
  gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
  GtkWidget *entry = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 0);
  GtkWidget *button = gtk_button_new_with_label("Generate Your Password right here");
  gtk_box_pack_start(GTK_BOX(vbox), entry ,FALSE,FALSE, 0);
  g_signal_connect(button, "clicked", G_CALLBACK(get_length_and_disp), entry);
  gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
  GtkWidget *img = gtk_image_new_from_file("pictures/pad.png");
  gtk_box_pack_start(GTK_BOX(vbox), img, FALSE, FALSE, 0);
  GtkWidget *pic = gtk_image_new_from_file("pictures/bac.png");
  gtk_box_pack_start(GTK_BOX(vbox), pic, FALSE, FALSE, 0);
  gtk_widget_show_all(window);
  gtk_main();
}
