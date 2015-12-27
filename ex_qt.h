#include<QHBoxLayout>
#include<QMainWindow>

class ButtonWindow : public QMainWindow
{
    Q_OBJECT;

    signals:
        void need_button();
    private slots:
        void start_loop();
        void do_bing();
        void create_button();
    private:
        QVBoxLayout* v_layout;
    public:
        ButtonWindow();
};
