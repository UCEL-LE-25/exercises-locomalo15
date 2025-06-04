#include <gtk/gtk.h>

void mostrar_stack_page(GtkWidget *widget, gpointer user_data) {
    GtkStack *stack = GTK_STACK(user_data);
    const gchar *page = gtk_widget_get_name(widget);
    gtk_stack_set_visible_child_name(stack, page);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Ventana principal
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Sistema de Registro Automotor");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Caja general vertical
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Stack: área donde cambia el contenido
    GtkWidget *stack = gtk_stack_new();
    gtk_stack_set_transition_type(GTK_STACK(stack), GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
    gtk_stack_set_transition_duration(GTK_STACK(stack), 300);

    // =======================
    // Página: Menú principal
    // =======================
    GtkWidget *menu_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    GtkWidget *btn_gestionar_titular = gtk_button_new_with_label("Gestionar Titular");
    gtk_widget_set_name(btn_gestionar_titular, "titular_page");
    g_signal_connect(btn_gestionar_titular, "clicked", G_CALLBACK(mostrar_stack_page), stack);
    gtk_box_pack_start(GTK_BOX(menu_box), btn_gestionar_titular, FALSE, FALSE, 0);

    GtkWidget *btn_salir = gtk_button_new_with_label("Salir");
    g_signal_connect(btn_salir, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_box_pack_start(GTK_BOX(menu_box), btn_salir, FALSE, FALSE, 0);

    gtk_stack_add_titled(GTK_STACK(stack), menu_box, "menu_page", "Menú Principal");

    // ============================
    // Página: Gestión de Titulares
    // ============================
    GtkWidget *titular_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    GtkWidget *btn_alta = gtk_button_new_with_label("Alta Titular");
    gtk_box_pack_start(GTK_BOX(titular_box), btn_alta, FALSE, FALSE, 0);

    GtkWidget *btn_baja = gtk_button_new_with_label("Baja Titular");
    gtk_box_pack_start(GTK_BOX(titular_box), btn_baja, FALSE, FALSE, 0);

    GtkWidget *btn_modificar = gtk_button_new_with_label("Modificar Titular");
    gtk_box_pack_start(GTK_BOX(titular_box), btn_modificar, FALSE, FALSE, 0);

    GtkWidget *btn_volver = gtk_button_new_with_label("Volver al Menú Principal");
    gtk_widget_set_name(btn_volver, "menu_page");
    g_signal_connect(btn_volver, "clicked", G_CALLBACK(mostrar_stack_page), stack);
    gtk_box_pack_start(GTK_BOX(titular_box), btn_volver, FALSE, FALSE, 0);

    gtk_stack_add_titled(GTK_STACK(stack), titular_box, "titular_page", "Gestión Titular");

    // Agregamos el stack a la caja principal
    gtk_box_pack_start(GTK_BOX(vbox), stack, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
