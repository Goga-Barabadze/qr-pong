#include <stdio.h>

/*struct Position {
    short x;
    short y;
};

struct Dimensions {
    short height;
    short width;
};

struct Panel {
    struct Position position;
    struct Dimensions dimensions;
};

struct Ball {
    struct Position position;

};*/

static void on_activate (GtkApplication *app) {

    // Create a new window
    GtkWidget *window = gtk_application_window_new (app);

    // Create a new button
    GtkWidget *button = gtk_button_new_with_label ("Hello, World!");

    // When the button is clicked, close the window passed as an argument
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_close), window);
    gtk_container_add (GTK_CONTAINER (window), button);
    gtk_widget_show_all (window);
}

int main(int argc, char **argv) {

    // https://en.wikipedia.org/wiki/List_of_platform-independent_GUI_libraries

    // Create a new application
    GtkApplication *app = gtk_application_new ("com.example.GtkApplication", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (on_activate), NULL);
    return g_application_run (G_APPLICATION (app), argc, argv);

    return 0;
}

