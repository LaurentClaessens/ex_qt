#include<QHBoxLayout>
#include<QMainWindow>

// compilation with
// make chose

class ButtonWindow : public QMainWindow
{
    Q_OBJECT;

    signals:
        void need_button();
    private slots:
        void do_bing();
        void create_button();
        void create_i_button();
    public slots:
        void start_loop();
    private:
        QVBoxLayout* v_layout;
    public:
        ButtonWindow();
};
