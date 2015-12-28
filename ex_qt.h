#include<QHBoxLayout>
#include<QMainWindow>

// compilation with
// make chose

class ButtonWindow : public QMainWindow
{
    Q_OBJECT;

    private slots:
        void do_bing();
        void create_button();
        void create_i_button();
    private:
        QVBoxLayout* v_layout;
    public:
        ButtonWindow();
        void addButton();
};

class LoopWidget : public QWidget
{
    Q_OBJECT;

    signals:
        void need_button();
    private:
        ButtonWindow* button_widget;
    public:
        void make_loop();
        LoopWidget(ButtonWindow*);
};

void populate_buttons(ButtonWindow*);   // add buttons to the button window 
                                        // with no use of slots/signal.
