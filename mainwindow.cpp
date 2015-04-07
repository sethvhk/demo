#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "iostream"
#include "cstdlib"
#include "ctime"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_button_hw_clicked()
{
    //Always update description when any button is clicked
    ui->task_desc->setText("Prints a string to the console");
    //Output string to console form element
    ui->console_out->setText("Hello World!");


}

void MainWindow::on_button_fb_clicked()
{
    ui->task_desc->setText("Prints the numbers from 1 to 100. But for multiples of three prints “Fizz” instead of the number and for the multiples of five prints “Buzz”. For numbers which are multiples of both three and five prints “FizzBuzz”.");
    ui->console_out->setText("Fizzbuzz!");
    for(int count = 1; count <= 100; count++) {
      //test if count is divisible by 3, 5, or both
      bool fizz = count % 3 == 0;
      bool buzz = count % 5 == 0;
      if(fizz && buzz) ui->console_out->append("FizzBuzz");
      else if(fizz) ui->console_out->append("Fizz");
      else if(buzz) ui->console_out->append("Buzz");
      else ui->console_out->append(QString::number(count));
    }
    //keep console scrolled to top after output
    QTextCursor cursor = ui->console_out->textCursor();
    cursor.setPosition(0);
    ui->console_out->setTextCursor(cursor);
}

void MainWindow::on_tempcon_clicked()
{
    ui->task_desc->setText("Converts values of celsius to farenheit");
    int temperc = 0;
    int temperf = 0;
    temperc = ui->temp_c->value(); //set celsius value from user
    temperf = ((9.0 / 5.0) * temperc + 32.0); //conversion to farenheit
    ui->console_out->setText(QString::number(temperc) + " degrees celsius is " + QString::number(temperf) + " degrees farenheit");
}

void MainWindow::on_button_isprime_clicked()
{
    ui->task_desc->setText("Tests if a given input between 2 and 99999 is a prime number");
    int num;
    num = ui->preprime->value();//set number to be tested from user
    int count = 2;

    //test division
    while (count < num && num % count != 0) {
      count = count + 1;
    }
    if(count == num){
            ui->console_out->setText(QString::number(count) + " is a prime number");
    } else {
        ui->console_out->setText(QString::number(num) + " is not a prime number");
    }
}

void MainWindow::on_button_shuffle_clicked()
{
    ui->console_out->setText("Shuffling...");
    ui->task_desc->setText("Simulates shuffling a deck of cards by randomizing a 52 element array");
    srand(time(0));
    int cards[52];

    //set up deck
    for (int count = 0; count < 52; count++ ) {
       cards[count] = count + 1;
    }

    //shuffle deck
    for ( int count = 0; count < 52; count++ ) {
       int index = rand() % 52;
       int tmp = cards[count];
       cards[count] = cards[index];
       cards[index] = tmp;
    }

    //output shuffled deck
    for ( int count = 0; count < 52; count++ ) {
        ui->console_out->moveCursor(QTextCursor::End);
        ui->console_out->insertPlainText(QString::number(cards[count])+ ",");
        ui->console_out->moveCursor (QTextCursor::End);
    }
    //remove trailing comma
    ui->console_out->textCursor().deletePreviousChar();

}
