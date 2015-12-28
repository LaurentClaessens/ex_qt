#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <QtGui>


#include "ex_qt.h"

LoopWidget::LoopWidget(ButtonWindow* bw): QWidget() 
{
    button_widget=bw;
    connect( this,SIGNAL(need_button()),bw,SLOT(create_button())  );
}

void LoopWidget::make_loop()
{
    for (int i=0;i<10;i++)
    {
        std::chrono::milliseconds timespan(500);
        std::this_thread::sleep_for(timespan);  // simulating some hard work.
        emit need_button();
    }
}

void ButtonWindow::create_button()
{
    std::cout<<"Creating a new button"<<std::endl;
    QPushButton* button= new QPushButton("auto");
    connect( button,SIGNAL( clicked()  ),this, SLOT(create_i_button()) );
    v_layout->addWidget(button);
    qApp->processEvents();
}

void ButtonWindow::create_i_button()
{
    std::cout<<"Creating a new i button"<<std::endl;
    QPushButton* button= new QPushButton("inter");
    button->setVisible(true);
    v_layout->addWidget(button);
    button->show();
}

void ButtonWindow::addButton()
{
    std::cout<<"Creating a button with no slot/signal"<<std::endl;
    QPushButton* button= new QPushButton("no slot");
    connect( button,SIGNAL( clicked()  ),this, SLOT(create_i_button()) );
    button->setVisible(true);
    v_layout->addWidget(button);
    button->show();
    qApp->processEvents();
}

void ButtonWindow::do_bing() { std::cout<<"BING"<<std::endl; }

ButtonWindow::ButtonWindow():
    QMainWindow()
{
    QWidget* button_widget = new QWidget(this);
    v_layout=new QVBoxLayout();

    QPushButton* button= new QPushButton("Useless button");
    QPushButton* button2= new QPushButton("make bing");
    v_layout->addWidget(button);
    v_layout->addWidget(button2);

    button_widget->setLayout(v_layout);

    connect( button2,SIGNAL( clicked()  ),this, SLOT(do_bing()) );
    connect( this,SIGNAL( need_button()  ),this, SLOT(create_button()) );
    setCentralWidget(button_widget);
}

void populate_buttons(ButtonWindow* bw)
{
    for (int i=0;i<10;i++)
    {
        std::chrono::milliseconds timespan(500);
        std::this_thread::sleep_for(timespan);  // simulating some hard work.
        bw->addButton();
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ButtonWindow* bw=new ButtonWindow();
    LoopWidget* loop_widget=new LoopWidget(bw);
    bw->show();

    //loop_widget->make_loop();
    populate_buttons(bw);

    app.exec();

    return 42;
}
