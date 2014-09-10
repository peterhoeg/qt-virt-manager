#include "sdl_graphics.h"

SDL_Graphics::SDL_Graphics(QWidget *parent) :
    _QWidget(parent)
{
    displayLabel = new QLabel("Display:", this);
    xauthLabel = new QLabel("Xauth:", this);
    display = new QLineEdit(this);
    display->setPlaceholderText(":0.0");
    xauth = new QLineEdit(this);
    xauth->setPlaceholderText("${HOME}/.Xauthority");
    fullscreen = new QCheckBox("Fullscreen:", this);
    browse = new QPushButton(QIcon::fromTheme("edit-find"), "", this);
    commonLayout = new QGridLayout();
    commonLayout->addWidget(displayLabel, 0, 0);
    commonLayout->addWidget(display, 0, 1);
    commonLayout->addWidget(xauthLabel, 1, 0);
    commonLayout->addWidget(xauth, 1, 1);
    commonLayout->addWidget(browse, 1, 2);
    commonLayout->addWidget(fullscreen, 2, 1, Qt::AlignTop);
    setLayout(commonLayout);
    connect(browse, SIGNAL(clicked()),
            this, SLOT(getPathToXauthority()));
}

/* public slots */
QDomDocument SDL_Graphics::getDevDocument() const
{
    QDomDocument doc;
    QDomElement _device, _devDesc;
    _device = doc.createElement("device");
    _devDesc = doc.createElement("graphics");
    _devDesc.setAttribute("type", "sdl");
    _devDesc.setAttribute("display", display->text());
    _devDesc.setAttribute("xauth", xauth->text());
    _devDesc.setAttribute("fullscreen", (fullscreen->isChecked())? "yes" : "no");
    _device.appendChild(_devDesc);
    doc.appendChild(_device);
    return doc;
}

/* private slots */
void SDL_Graphics::getPathToXauthority() const
{
    QString file = QFileDialog::getOpenFileName(
                NULL,
                tr("Specify Xauth"),
                "/home",
                tr("Xauth (.Xauthority)"));
    if ( !file.isEmpty() ) xauth->setText(file);
}