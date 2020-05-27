#include "mainwindow.h"
#include <SFML/Graphics.hpp>
#include <QApplication>
#include "cmenu.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

 cmenu m(600,600);
 m.loop();
}
