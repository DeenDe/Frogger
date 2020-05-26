#include "mainwindow.h"
#include <SFML/Graphics.hpp>
#include <QApplication>
#include "cmenu.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

 cmenu m(1,1);
 m.loop();
}
