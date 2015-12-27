#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <QtGui>


#include "ex_qt.h"

void ButtonWindow::start_loop()
{
    for (int i=0;i<10;i++)
    {
        std::chrono::milliseconds timespan(500);
        std::this_thread::sleep_for(timespan);  // simulating some hard work.
        emit need_button();
        qApp->processEvents();
    }
}

void ButtonWindow::create_button()
{
    std::cout<<"Creating a new button"<<std::endl;
    QPushButton* button= new QPushButton("auto");
    connect( button,SIGNAL( clicked()  ),this, SLOT(create_i_button()) );
    v_layout->addWidget(button);
}

void ButtonWindow::create_i_button()
{
    std::cout<<"Creating a new i button"<<std::endl;
    QPushButton* button= new QPushButton("inter");
    button->setVisible(true);
    v_layout->addWidget(button);
    button->show();
}


void ButtonWindow::do_bing() { std::cout<<"BING"<<std::endl; }

ButtonWindow::ButtonWindow():
    QMainWindow()
{
    QWidget* button_widget = new QWidget(this);
    v_layout=new QVBoxLayout();

    QPushButton* button= new QPushButton("click here to begin");
    QPushButton* button2= new QPushButton("make bing");
    v_layout->addWidget(button);
    v_layout->addWidget(button2);

    button_widget->setLayout(v_layout);

    connect( button,SIGNAL( clicked()  ),this, SLOT(start_loop()) );
    connect( button2,SIGNAL( clicked()  ),this, SLOT(do_bing()) );
    connect( this,SIGNAL( need_button()  ),this, SLOT(create_button()) );
    setCentralWidget(button_widget);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ButtonWindow* bw=new ButtonWindow();
    bw->show();
    app.exec();

    return 42;
}
