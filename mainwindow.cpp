#include "mainwindow.h"
#include "ui_mainwindow.h"

double first_number;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Button_0, SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->Button_1, SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->Button_2, SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->Button_3, SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->Button_4, SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->Button_5, SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->Button_6, SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->Button_7, SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->Button_8, SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->Button_9, SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->Button_plus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->Button_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->Button_multi, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->Button_split, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->Button_sqrt, SIGNAL(clicked()), this, SLOT(on_Button_sqrt_clicked()));
    connect(ui->Button_sqr, SIGNAL(clicked()), this, SLOT(on_Button_sqr_clicked()));
    connect(ui->Button_clear, SIGNAL(clicked()), this, SLOT(on_Button_clear_clicked()));
    connect(ui->Button_equal, SIGNAL(clicked()), this, SLOT(on_Button_equal_clicked()));

    ui->Button_minus->setCheckable(true);
    ui->Button_plus->setCheckable(true);
    ui->Button_split->setCheckable(true);
    ui->Button_multi->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::input_numbers()
{
    QPushButton *click = (QPushButton *) sender();
    QString new_number;
    double numbers;
    numbers = (ui->Result->text()+click->text()).toDouble();
    new_number=QString::number(numbers, 'g', 15);
    ui->Result->setText(new_number);
}

void MainWindow::operations()
{
    QPushButton *click = (QPushButton *) sender();
    first_number=ui->Result->text().toDouble();
    ui->Result->setText(" ");
    click->setChecked(true);
}

void MainWindow::on_Button_equal_clicked()
{
    double result, second_number;
    QString new_number;
    second_number=ui->Result->text().toDouble();
    if(ui->Button_plus->isChecked())
    {
        result=first_number+second_number;
        new_number=QString::number(result, 'g', 15);
        ui->Result->setText(new_number);
        ui->Button_plus->setChecked(false);
    }
    else if(ui->Button_minus->isChecked())
    {
        result=first_number-second_number;
        new_number=QString::number(result, 'g', 15);
        ui->Result->setText(new_number);
        ui->Button_minus->setChecked(false);
    }
    else if(ui->Button_split->isChecked())
    {
        if(second_number==0)
        {
            ui->Result->setText("error");
        }
        else
        {
        result=first_number/second_number;
        new_number=QString::number(result, 'g', 15);
        ui->Result->setText(new_number);
        }
        ui->Button_split->setChecked(false);
    }
    else if(ui->Button_multi->isChecked())
    {
        result=first_number*second_number;
        new_number=QString::number(result, 'g', 15);
        ui->Result->setText(new_number);
        ui->Button_multi->setChecked(false);
    }

}

void MainWindow::on_Button_sqrt_clicked()
{
    QString new_number;
    double numbers;
    numbers = (ui->Result->text()).toDouble();
    numbers = sqrt(numbers);
    new_number=QString::number(numbers, 'g', 15);
    ui->Result->setText(new_number);
}


void MainWindow::on_Button_sqr_clicked()
{
    QString new_number;
    double numbers;
    numbers = (ui->Result->text()).toDouble();
    numbers = numbers * numbers;
    new_number=QString::number(numbers, 'g', 15);
    ui->Result->setText(new_number);
}


void MainWindow::on_Button_clear_clicked()
{
    ui->Result->setText("0");
    ui->Button_plus->setChecked(false);
    ui->Button_minus->setChecked(false);
    ui->Button_split->setChecked(false);
    ui->Button_multi->setChecked(false);
}

