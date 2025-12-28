#include "login.h"
#include "ui_login.h"
#include <QPalette>
#include <QPixmap>
#include <QFont>
#include <QLayout>
#include <QFormLayout>
#include <QStackedWidget>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
//-------------------------------------------------------------------------
//                          1.Fenetre Principale
//-------------------------------------------------------------------------
//personnaliser la fenetre
    ui->setupUi(this);
    this->setWindowTitle("s'enregistre");
    setFixedSize(590,520);
    QPixmap bg(":/images/catalogue/background/Messenger_creation_4382096952070907.jpeg");
    bg = bg.scaled(this->size(),
                   Qt::IgnoreAspectRatio,
                   Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, bg);
    this->setPalette(palette);
    //font
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(18);
    font.setBold(true);
    font.setItalic(false);

//-------------------------------------------------------------------------------
//page Login
    QWidget *PageLogin = new QWidget;
//-------------------------------------------------------------------------------
//Frame login

    QFrame *FrameLogin =  new QFrame(PageLogin);
    FrameLogin->setFixedSize(500,180);
    FrameLogin->setLineWidth(4);
    FrameLogin->setMidLineWidth(2);
    FrameLogin->setFrameShape(QFrame::Panel);


    Label_text = new QLabel("Veuillez Selectionner le compte", FrameLogin);
    Label_text->setFont(font);

    QFrame *FrameChoix = new QFrame(FrameLogin);
    FrameChoix->setFixedSize(350,100);
    FrameChoix->setLineWidth(4);
    FrameChoix->setMidLineWidth(2);
    FrameChoix->setFrameShape(QFrame::NoFrame);

    //bouton connexion(Client-Personnnel)
    //Bouton client

    QHBoxLayout *mainChoix = new QHBoxLayout(FrameChoix);
    Button_Client = new QPushButton("Client", FrameChoix);
    //Bouton personnel
    Button_Personnel = new QPushButton("Personnel", FrameChoix);


    mainChoix->addWidget(Button_Client, 0,Qt::AlignCenter);
    mainChoix->addWidget(Button_Personnel, 1,Qt::AlignCenter);

    QVBoxLayout *Layout2 = new QVBoxLayout(FrameLogin);
    Layout2->addWidget(Label_text, 0,Qt::AlignCenter);
    Layout2->addWidget(FrameChoix, 1,Qt::AlignCenter);

    QVBoxLayout *LayoutmainLogin = new QVBoxLayout(PageLogin);
    LayoutmainLogin->addWidget(FrameLogin, 0,Qt::AlignCenter);

//------------------------------------------------------------------------------


    QStackedWidget *stack = new QStackedWidget(this);
//------------------------------------------------------------------------------
//                  2.Fenetre enregistre client
//------------------------------------------------------------------------------
//fenetre choix == client
    QWidget *pageClient = new QWidget;
    QLineEdit *LineNom = new QLineEdit;
    QLineEdit *LinePrenom = new QLineEdit;
    QLineEdit *LineAge = new QLineEdit;

    QPushButton *BoutonEnregistre = new QPushButton("Enregistre");
    QPushButton *BoutonRetour = new QPushButton("Reture");

    QFormLayout *LayoutPageEnregistrerClient = new QFormLayout(pageClient);
    LayoutPageEnregistrerClient->addRow("votre Nom : ", LineNom);
    LayoutPageEnregistrerClient->addRow("votre Prenom: ", LinePrenom);
    LayoutPageEnregistrerClient->addRow("votre Age : ", LineAge);
    LayoutPageEnregistrerClient->addRow(BoutonEnregistre);
    LayoutPageEnregistrerClient->addRow(BoutonRetour);
    \
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//                   #.Fenetre enregistre Personnel
//--------------------------------------------------------------------------------
//fenetre choix == client
    QWidget *PagePersonel = new QWidget;
    QLineEdit *LineNomPersonnel = new QLineEdit;
    QLineEdit *LinePrenomPersonnel = new QLineEdit;
    QLineEdit *LinePassWord = new QLineEdit;
    QLineEdit *LineConfirmPassWord = new QLineEdit;

    QPushButton *BouttonConnexion = new QPushButton("Conexion");
    QPushButton *BoutonRetourPersonel = new QPushButton("Reture");

    QFormLayout *LayoutPageConnnexionPersonnnel = new QFormLayout(PagePersonel);
    LayoutPageConnnexionPersonnnel->addRow("votre Nom : ", LineNomPersonnel);
    LayoutPageConnnexionPersonnnel->addRow("votre Prenom: ", LinePrenomPersonnel);
    LayoutPageConnnexionPersonnnel->addRow("votre mot de passe: ", LinePassWord);
    LayoutPageConnnexionPersonnnel->addRow("votre mot de passe: ", LineConfirmPassWord);
    LayoutPageConnnexionPersonnnel->addRow(BouttonConnexion);
    LayoutPageConnnexionPersonnnel->addRow(BoutonRetourPersonel);
    \
//--------------------------------------------------------------------------------

    stack->addWidget(PageLogin);
    stack->addWidget(pageClient);
    stack->addWidget(PagePersonel);
    stack->setCurrentIndex(0);

    connect(BoutonRetour,&QPushButton::clicked, this, [=](){stack->setCurrentIndex(0);});
    connect(BoutonRetourPersonel,&QPushButton::clicked, this, [=](){stack->setCurrentIndex(0);});
    // connect(BoutonEnregistre,&QPushButton::clicked, this,)
    connect(Button_Client,&QPushButton::clicked, this, [=](){stack->setCurrentIndex(1);});
    connect(Button_Personnel,&QPushButton::clicked, this, [=](){stack->setCurrentIndex(2);});

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(stack,0,Qt::AlignCenter);
    this->setLayout(mainLayout);
//
}
//les fonctions

    //interface connnexion client
void Login::interface_LoginClient(){
}

    //interface conexion ppersonnel
void Login::interface_LoginPersonnel(){
}

Login::~Login()
{
    delete ui;
}
