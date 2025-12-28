#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

//les Attributs


//les fonction de l'interface graphique
    void interface_LoginClient();
    void interface_LoginPersonnel();

//les signaux


//les slots

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;
    QPushButton *Button_Client;
    QLabel *Label_text;
    QPushButton *Button_Personnel;
};

#endif // LOGIN_H
