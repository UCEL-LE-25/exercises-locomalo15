#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[20];
    long int cuit;
    char tipoDocumento[10];
    int nroDocumento;
    char fechaNacimiento[20];
    int idDomicilio;
} Titular;

void guardar_titular(GtkWidget *widget, gpointer data[]) {
    const gchar *nombre = gtk_entry_get_text(GTK_ENTRY(data[0]));
    const gchar *cuit_str = gtk_entry_get_text(GTK_ENTRY(data[1]));
    const gchar *tipoDoc = gtk_entry_get_text(GTK_ENTRY(data[2]));
    const gchar *nroDoc_str = gtk_entry_get_text(GTK_ENTRY(data[3]));
    const gchar *fechaNac = gtk_entry_get_text(GTK_ENTRY(data[4]));

    Titular t;
    strncpy(t.nombre, nombre, sizeof(t.nombre));
    t.cuit = atol(cuit_str);
    strncpy(t.tipoDocumento, tipoDoc, sizeof(t.tipoDocumento));
    t.nroDocumento = atoi(nroDoc_str);
    strncpy(t.fechaNacimiento, fechaNac, sizeof(t.fechaNacimiento));
    t.idDomicilio = 1; // ¡Esto lo vamos a mejorar luego integrando el crearDomicilio!

    FILE *archivo = fopen("titulares.txt", "a");
    if (archivo) {
        fprintf(archivo, "%s;%ld;%s;%d;%s;%d\n",
                t.nombre, t.cuit, t.tipoDocumento,
                t.nroDocumento, t.fechaNacimiento, t.idDomicilio);
        fclose(archivo);
        GtkWidget *dialog = gtk_message_dialog_new(NULL,
            GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
            "Titular guardado correctamente.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ventana), "Alta de Titular");
    gtk_window_set_default_size(GTK_WINDOW(ventana), 400, 300);
    gtk_container_set_border_width(GTK_CONTAINER(ventana), 10);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_container_add(GTK_CONTAINER(ventana), grid);

    GtkWidget *labels[5];
    GtkWidget *entries[5];
    const char *texts[] = {"Nombre", "CUIT", "Tipo de Documento", "Nro Documento", "Fecha Nacimiento"};

    for (int i = 0; i < 5; i++) {
        labels[i] = gtk_label_new(texts[i]);
        entries[i] = gtk_entry_new();
        gtk_grid_attach(GTK_GRID(grid), labels[i], 0, i, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), entries[i], 1, i, 1, 1);
    }

    GtkWidget *botonGuardar = gtk_button_new_with_label("Guardar");
    gtk_grid_attach(GTK_GRID(grid), botonGuardar, 0, 5, 2, 1);

    g_signal_connect(botonGuardar, "clicked", G_CALLBACK(guardar_titular), entries);
    g_signal_connect(ventana, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(ventana);
    gtk_main();

    return 0;
}
