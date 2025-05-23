#include <gtk/gtk.h>
#include "ventanas.h"

void ventana_agregar_producto(GtkWidget *widget, gpointer data) {
    GtkWidget *ventana;
    GtkWidget *grid;
    GtkWidget *label_codigo, *entry_codigo;
    GtkWidget *label_stock, *entry_stock;
    GtkWidget *btn_guardar;

    ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ventana), "Agregar Producto");
    gtk_window_set_default_size(GTK_WINDOW(ventana), 300, 200);
    gtk_container_set_border_width(GTK_CONTAINER(ventana), 10);

    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_container_add(GTK_CONTAINER(ventana), grid);

    label_codigo = gtk_label_new("Código del producto:");
    entry_codigo = gtk_entry_new();

    label_stock = gtk_label_new("Stock inicial:");
    entry_stock = gtk_entry_new();

    btn_guardar = gtk_button_new_with_label("Guardar");

    gtk_grid_attach(GTK_GRID(grid), label_codigo, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_codigo, 1, 0, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), label_stock, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_stock, 1, 1, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), btn_guardar, 0, 2, 2, 1);

    gtk_widget_show_all(ventana);
}
