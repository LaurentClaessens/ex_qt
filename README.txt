This small example file shows two ways of dynamically add 10 buttons in a QMainWidow.

- using the event systems of QT (loop_widget->make_loop();)
- using an external function    (populate_buttons(bw);)

The secret is the line
    qApp->processEvents();

In both cases, the buttons are shown and fully functional even before that the next buttons are created.



COMPILATION AND EXECUTION : 
$ make example
$ ./ex_qt
