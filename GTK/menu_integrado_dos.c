// menu_principal.c
#include <gtk/gtk.h>

void mostrar_alta_titular(GtkWidget *widget, gpointer data);
void mostrar_baja_titular(GtkWidget *widget, gpointer data);
void mostrar_modificacion_titular(GtkWidget *widget, gpointer data);
void mostrar_listado_titular(GtkWidget *widget, gpointer data);

void mostrar_gestion_titulares(GtkWidget *widget, gpointer data) {
    GtkWidget *ventana, *caja, *boton;

    ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ventana), "Gestión de Titulares");
    gtk_window_set_default_size(GTK_WINDOW(ventana), 400, 300);

    caja = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(ventana), caja);

    boton = gtk_button_new_with_label("Alta Titular");
    g_signal_connect(boton, "clicked", G_CALLBACK(mostrar_alta_titular), NULL);
    gtk_box_pack_start(GTK_BOX(caja), boton, TRUE, TRUE, 0);

    boton = gtk_button_new_with_label("Baja Titular");
    g_signal_connect(boton, "clicked", G_CALLBACK(mostrar_baja_titular), NULL);
    gtk_box_pack_start(GTK_BOX(caja), boton, TRUE, TRUE, 0);

    boton = gtk_button_new_with_label("Modificar Titular");
    g_signal_connect(boton, "clicked", G_CALLBACK(mostrar_modificacion_titular), NULL);
    gtk_box_pack_start(GTK_BOX(caja), boton, TRUE, TRUE, 0);

    boton = gtk_button_new_with_label("Listar Titulares");
    g_signal_connect(boton, "clicked", G_CALLBACK(mostrar_listado_titular), NULL);
    gtk_box_pack_start(GTK_BOX(caja), boton, TRUE, TRUE, 0);

    gtk_widget_show_all(ventana);
}

void cerrar_aplicacion(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    GtkWidget *ventana, *caja, *boton;

    gtk_init(&argc, &argv);

    ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ventana), "Registro Automotor - Menú Principal");
    gtk_window_set_default_size(GTK_WINDOW(ventana), 400, 400);
    g_signal_connect(ventana, "destroy", G_CALLBACK(cerrar_aplicacion), NULL);

    caja = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(ventana), caja);

    boton = gtk_button_new_with_label("Gestion Titulares");
    g_signal_connect(boton, "clicked", G_CALLBACK(mostrar_gestion_titulares), NULL);
    gtk_box_pack_start(GTK_BOX(caja), boton, TRUE, TRUE, 0);

    boton = gtk_button_new_with_label("Gestion Automotores");
    gtk_box_pack_start(GTK_BOX(caja), boton, TRUE, TRUE, 0);

    boton = gtk_button_new_with_label("Gestion Cédulas");
    gtk_box_pack_start(GTK_BOX(caja), boton, TRUE, TRUE, 0);

    boton = gtk_button_new_with_label("Gestion Registros");
    gtk_box_pack_start(GTK_BOX(caja), boton, TRUE, TRUE, 0);

    boton = gtk_button_new_with_label("Reportes");
    gtk_box_pack_start(GTK_BOX(caja), boton, TRUE, TRUE, 0);

    boton = gtk_button_new_with_label("Salir");
    g_signal_connect(boton, "clicked", G_CALLBACK(cerrar_aplicacion), NULL);
    gtk_box_pack_start(GTK_BOX(caja), boton, TRUE, TRUE, 0);

    gtk_widget_show_all(ventana);
    gtk_main();

    return 0;
}

void mostrar_alta_titular(GtkWidget *widget, gpointer data) {
    g_print("Alta titular aún no implementado.\n");
}

void mostrar_baja_titular(GtkWidget *widget, gpointer data) {
    g_print("Baja titular aún no implementado.\n");
}

void mostrar_modificacion_titular(GtkWidget *widget, gpointer data) {
    g_print("Modificar titular aún no implementado.\n");
}

void mostrar_listado_titular(GtkWidget *widget, gpointer data) {
    g_print("Listado de titulares aún no implementado.\n");
}
