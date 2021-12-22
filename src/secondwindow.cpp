#include <QPixmap>
#include <QScrollArea>  // полосы прокрутки
#include <QLabel>
#include <utility>
#include <iostream>
#include <fstream>
#include <QFileDialog>

#include "secondwindow.h"
#include "ui_secondwindow.h"


SecondWindow::SecondWindow(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::SecondWindow) {
    ui->setupUi(this);
    std::cerr << "in second_window" << std::endl;
    on_pushButton_addBox_clicked();
    std::cerr << "in second_window" << std::endl;
    //on_pushButton_addBox_clicked();
}

SecondWindow::~SecondWindow() {
    delete ui;
}

/*void SecondWindow::on_pushButton_next_clicked()
{
    if (this->n < 2) {
        this->n ++;
    }
    QPixmap pix1(":/resource/mem/mem0.jpg");  // создаем обьект с картинкой
    QPixmap pix2(":/resource/mem/mem1.jpg");
    QPixmap pix3(":/resource/mem/mem2.jpg");
    int w = 275;
    int h = 257;
    switch (this->n){
    case 0:
        ui->label->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));
        break;
    case 1:
        ui->label->setPixmap(pix2.scaled(w, h, Qt::KeepAspectRatio));
        break;
    case 2:
        ui->label->setPixmap(pix3.scaled(w, h, Qt::KeepAspectRatio));
        break;
    }
}*/


void SecondWindow::on_pushButton_exit_clicked() {
    emit signalExit();
    this->close();
}


void SecondWindow::on_pushButton_addBox_clicked() {
    Request request;
    request_info request_struct = {};
    request_struct.type_request = GET;
    request_struct.target_request = MEME_POST;

    request.do_request(request_struct);
    http::request<http::string_body> to_client = request.get_request();
    net::io_context ioc;
    std::shared_ptr<Client> client(new Client(ioc, to_client));

    client->run();

    ioc.run();

    int likes = client->get_count_likes();
    int dislikes = client->get_count_dislikes();
    client->set_id_meme();
    std::string id = client->get_id_meme();

    QDynamicBox *Box = new QDynamicBox(id, this, likes, dislikes);  // создаем новый GroupBox
    Box->setObjectName("groupBox_" + QString::number(Box->getID()));
    //qDebug() << Box->getID();
    ui->verticalLayout_2->addWidget(Box, 1);  // Помещаем новый Box в слой verticalLayout_2
    QVBoxLayout *VLayout = new QVBoxLayout(Box);  // Создаем новый слой verticalLayout
    Box->setLayout(VLayout);  // применяет макет layout к виджету Box
    QLabel *newLabel = new QLabel(this);  // создаем новый Label для картинки
    VLayout->addWidget(newLabel);  // добавляем newLabel в layout
    QHBoxLayout *HLayout = new QHBoxLayout(Box);
    VLayout->addLayout(HLayout);

    QLabel *labelLike = new QLabel();
    HLayout->addWidget(labelLike);
    labelLike->setObjectName("labelLike_" + QString::number(Box->getID()));
    labelLike->setText(QString::number(Box->numberLike));

    QDynamicButton *buttonLike = new QDynamicButton();
    HLayout->addWidget(buttonLike);
    buttonLike->setObjectName("buttonLike_" + QString::number(Box->getID()));
    buttonLike->BoxNumber = Box->getID();
    buttonLike->setIcon(QIcon("./resource/img/like.png"));  // добавление иконки на кнопку
    buttonLike->setIconSize(QSize(20, 20));  // размер кнопки
    connect(buttonLike, SIGNAL(clicked()), this,
            SLOT(slot_on_pushButton_like_clicked()));  // связываем сигнал нажатия кнопки и слот нажатия кнопки

    QDynamicButton *buttonDislike = new QDynamicButton();
    HLayout->addWidget(buttonDislike);
    buttonDislike->setObjectName("buttonDisLike_" + QString::number(Box->getID()));
    buttonDislike->BoxNumber = Box->getID();
    buttonDislike->setIcon(QIcon("./resource/img/dislike.png"));
    buttonDislike->setIconSize(QSize(20, 20));
    connect(buttonDislike, SIGNAL(clicked()), this, SLOT(slot_on_pushButton_dislike_clicked()));

    QLabel *labelDisLike = new QLabel();
    HLayout->addWidget(labelDisLike);
    labelDisLike->setObjectName("labelDisLike_" + QString::number(Box->getID()));
    labelDisLike->setText(QString::number(Box->numberDisLike));

    HLayout->addStretch(0);

    QDynamicButton *buttonDownload = new QDynamicButton();
    HLayout->addWidget(buttonDownload);
    buttonDownload->setObjectName("buttonDownload_" + QString::number(Box->getID()));
    buttonDownload->BoxNumber = Box->getID();
    buttonDownload->setIcon(QIcon("./resource/img/download.png"));
    buttonDownload->setIconSize(QSize(20, 20));
    connect(buttonDownload, SIGNAL(clicked()), this, SLOT(slot_on_pushButton_download_clicked()));// Добавляет растягиваемое пространство (QSpacerItem) с нулевым минимальным размером

    //std::string meme_file = "./" + client->get_meme() + ".jpeg";

    //std::cerr << meme_file;

    std::vector <unsigned char> buf = client->get_meme();

    client->clean_response();

    QByteArray img(reinterpret_cast<const char*>(buf.data()), buf.size());
    //QString qstr = QString::fromStdString(meme_file);

    QPixmap pix1;
    pix1.loadFromData(img, "JPG");
    int w = 275;
    int h = 257;
    newLabel->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));
    // вставляем картинку в layout

}

void SecondWindow::slot_on_pushButton_like_clicked() {
    QDynamicButton *buttonLike = (QDynamicButton *) sender();
    QDynamicBox *Box = this->findChild<QDynamicBox *>("groupBox_" + QString::number(buttonLike->BoxNumber));
    QDynamicButton *buttonDisLike = this->findChild<QDynamicButton *>("buttonDisLike_" + QString::number(buttonLike->BoxNumber));
    QLabel *labelLike = this->findChild<QLabel *>("labelLike_" + QString::number(buttonLike->BoxNumber));
    QLabel *labelDisLike = this->findChild<QLabel *>("labelDisLike_" + QString::number(buttonLike->BoxNumber));

    Request request;
    request_info request_struct = {};
    request_struct.type_request = POST;
    nlohmann::json json_body;

    switch (Box->like_status) {
        case LIKE: {
            request_struct.target_request = REDUCE_LIKE;
            Box->like_status = NOTHING;
            Box->numberLike--;
            json_body = {{"id",    Box->memID},
                         {"likes", std::to_string(Box->numberLike)}};
            buttonLike->setIcon(QIcon("./resource/img/like.png"));
            labelLike->setText(QString::number(Box->numberLike));
            break;
        }
        case DISLIKE: {
            request_struct.target_request = INCREASE_LIKE;
            Box->like_status = LIKE;
            Box->numberDisLike--;
            Box->numberLike++;
            json_body = {{"id",    Box->memID},
                         {"likes", std::to_string(Box->numberDisLike)}};
            buttonLike->setIcon(QIcon("./resource/img/like_click.png"));
            buttonDisLike->setIcon(QIcon("./resource/img/dislike.png"));
            labelLike->setText(QString::number(Box->numberLike));
            labelDisLike->setText(QString::number(Box->numberDisLike));
            break;
        }
        case NOTHING: {
            request_struct.target_request = INCREASE_LIKE;
            Box->numberLike++;
            Box->like_status = LIKE;
            json_body = {{"id",    Box->memID},
                         {"likes", std::to_string(Box->numberLike)}};
            buttonLike->setIcon(QIcon("./resource/img/like_click.png"));
            labelLike->setText(QString::number(Box->numberLike));
            break;
        }
    }

    auto string_body = json_body.dump();
    request.do_request(request_struct, string_body);
    http::request<http::string_body> to_client = request.get_request();

    std::cerr << to_client << std::endl;
    net::io_context ioc;
    std::shared_ptr<Client> client(new Client(ioc, to_client));

    client->run();

    ioc.run();
}

void SecondWindow::slot_on_pushButton_dislike_clicked() {
    QDynamicButton *buttonDisLike = (QDynamicButton *) sender();
    QDynamicBox *Box = this->findChild<QDynamicBox *>("groupBox_" + QString::number(buttonDisLike->BoxNumber));
    QDynamicButton *buttonLike = this->findChild<QDynamicButton *>("buttonLike_" + QString::number(buttonDisLike->BoxNumber));
    QLabel *labelLike = this->findChild<QLabel *>("labelLike_" + QString::number(buttonLike->BoxNumber));
    QLabel *labelDisLike = this->findChild<QLabel *>("labelDisLike_" + QString::number(buttonLike->BoxNumber));

    Request request;
    request_info request_struct = {};
    request_struct.type_request = POST;
    nlohmann::json json_body;

    switch (Box->like_status) {
        case DISLIKE:
            request_struct.target_request = REDUCE_DISLIKE;
            Box->like_status = NOTHING;
            Box->numberDisLike--;
            json_body = {{"id",    Box->memID},
                         {"dislikes", std::to_string(Box->numberDisLike)}};
            buttonDisLike->setIcon(QIcon("./resource/img/dislike.png"));
            labelDisLike->setText(QString::number(Box->numberDisLike));
            break;
        case LIKE:
            request_struct.target_request = INCREASE_DISLIKE;
            Box->like_status = DISLIKE;
            Box->numberLike--;
            Box->numberDisLike++;
            json_body = {{"id",    Box->memID},
                         {"dislikes", std::to_string(Box->numberDisLike)}};
            buttonLike->setIcon(QIcon("./resource/img/like.png"));
            buttonDisLike->setIcon(QIcon("./resource/img/dislike_click.png"));
            labelLike->setText(QString::number(Box->numberLike));
            labelDisLike->setText(QString::number(Box->numberDisLike));
            break;
        case NOTHING:
            request_struct.target_request = INCREASE_DISLIKE;
            Box->like_status = DISLIKE;
            Box->numberDisLike++;
            json_body = {{"id",    Box->memID},
                         {"dislikes", std::to_string(Box->numberDisLike)}};
            buttonDisLike->setIcon(QIcon("./resource/img/dislike_click.png"));
            labelDisLike->setText(QString::number(Box->numberDisLike));
            break;
    }

    auto string_body = json_body.dump();
    request.do_request(request_struct, string_body);
    http::request<http::string_body> to_client = request.get_request();

    std::cerr << to_client << std::endl;
    net::io_context ioc;
    std::shared_ptr<Client> client(new Client(ioc, to_client));

    client->run();

    ioc.run();
}

void SecondWindow::slot_on_pushButton_download_clicked()
{
    QDynamicButton *buttonDownload = (QDynamicButton*) sender();
    QDynamicBox *Box = this->findChild<QDynamicBox *>("groupBox_" + QString::number(buttonDownload->BoxNumber));
    QString fileDirectory = QFileDialog::getExistingDirectory(this);

    std::cerr << fileDirectory.toStdString();


    Request request;
    request_info request_struct = { };
    request_struct.type_request = POST;
    request_struct.target_request = DOWNLOAD_MEME;

    nlohmann::json json_body = {{"id", Box->memID} };

    std::string str_body = json_body.dump();

    request.do_request(request_struct, str_body);
    http::request<http::string_body> to_client = request.get_request();

    std::cerr << "Запрос: \n" << to_client;

    net::io_context ioc;
    std::shared_ptr<Client> client(new Client(ioc, to_client));

    client->run();

    ioc.run();

    std::vector <unsigned char> buf = client->get_meme();

    client->clean_response();

    std::ofstream outfile(fileDirectory.toStdString() + "/" + Box->memID + ".jpeg", std::ios::out | std::ios::binary);
    outfile.write(reinterpret_cast<const char *>(buf.data()), buf.size());
}

void SecondWindow::on_pushButton_clicked() {
    hide();  // скрыть исходное окно
    userProf = new userProfileWin(this);
    userProf->show();
    connect(userProf, &userProfileWin::signalExitProf, this, &SecondWindow::slotExitProf);
}

void SecondWindow::slotExitProf() {
    show();
}


