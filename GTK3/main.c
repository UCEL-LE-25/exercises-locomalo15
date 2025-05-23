#include <gtk/gtk.h>
#include "ventanas.h"

static void on_button_clicked(GtkWidget *widget, gpointer data) {
    const gchar *label = gtk_button_get_label(GTK_BUTTON(widget));
    g_print("Botón presionado: %s\n", label);
    // Aquí se pueden agregar más funciones para los demás botones
}

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;
    const gchar *labels[] = {
        "Inicializar Depósito",
        "Agregar Producto",
        "Retirar Stock",
        "Mover Producto",
        "Buscar Producto",
        "Reportes",
        "Salir"
    };

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Sistema de Gestión de Depósito");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_container_set_border_width(GTK_CONTAINER(grid), 20);
    gtk_container_add(GTK_CONTAINER(window), grid);

    for (int i = 0; i < 7; i++) {
        button = gtk_button_new_with_label(labels[i]);

        if (i == 1) { // Agregar Producto
            g_signal_connect(button, "clicked", G_CALLBACK(ventana_agregar_producto), NULL);
        } else {
            g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
        }

        gtk_grid_attach(GTK_GRID(grid), button, 0, i, 1, 1);
    }

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.ejemplo.gestiondeposito", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
