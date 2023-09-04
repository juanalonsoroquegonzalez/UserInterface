#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <QMessageBox>

#include "menu.h"
#include "./ui_menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

class Neurona
{
private:
    int id;
    float voltaje;
    int posicion_x;
    int posicion_y;
    int red;
    int green;
    int blue;

public:
    Neurona(int _id, float _voltaje, int _posicion_x, int _posicion_y, int _red, int _green, int _blue)
        : id(_id), voltaje(_voltaje), posicion_x(_posicion_x), posicion_y(_posicion_y), red(_red), green(_green), blue(_blue){
    }
    int getID() const{
        return id;
    }
    float getVoltaje() const{
        return voltaje;
    }
    int getPosicion_x() const{
        return posicion_x;
    }
    int getPosicion_y() const{
        return posicion_y;
    }
    int getRed() const{
        return red;
    }
    int getGreen() const{
        return green;
    }
    int getBlue() const{
        return blue;
    }
    void print() const {
        std::cout << "ID: " << id << std::endl;
        std::cout << "Voltaje: " << voltaje << std::endl;
        std::cout << "Posici�n X: " << posicion_x << std::endl;
                std::cout << "Posici�n Y: " << posicion_y << std::endl;
                         std::cout << "Red: " << red << std::endl;
        std::cout << "Green: " << green << std::endl;
        std::cout << "Blue: " << blue << std::endl;
    }
};

class AdministradorNeuronas {
private:
    std::list<Neurona> listaNeuronas;

public:
    void agregarInicio(const Neurona& neurona) {
        listaNeuronas.push_front(neurona);
    }

    void agregarFinal(const Neurona& neurona) {
        listaNeuronas.push_back(neurona);
    }

    void mostrar() {
        for (const Neurona& neurona : listaNeuronas) {
            neurona.print();
            std::cout << "-------------------" << std::endl;
        }
    }
};

void Menu::on_buttonAgregar_clicked()
{
    if(ui->lineID->text().isEmpty() || ui->lineVoltaje->text().isEmpty() || ui->lineX->text().isEmpty() || ui->lineY->text().isEmpty() || ui->lineRed->text().isEmpty() || ui->lineGreen->text().isEmpty() || ui->lineBlue->text().isEmpty()){
        ui->labelVerificar->setText("Datos incompletos");
    }
    else {
        ui->labelVerificar->setText("");
        AdministradorNeuronas administrador;

        Neurona neuronas(ui->lineID->text().toInt(), ui->lineVoltaje->text().toInt(), ui->lineX->text().toInt(), ui->lineY->text().toInt(), ui->lineRed->text().toInt(), ui->lineGreen->text().toInt(), ui->lineBlue->text().toInt());

        administrador.agregarInicio(neuronas);

        QMessageBox::warning(nullptr, "Valido!", "Neurona agregada");

        ui->lineID->setText("");
        ui->lineVoltaje->setText("");
        ui->lineX->setText("");
        ui->lineY->setText("");
        ui->lineRed->setText("");
        ui->lineGreen->setText("");
        ui->lineBlue->setText("");

        std::cout << "Neuronas: \n";
        administrador.mostrar();
    }
}


