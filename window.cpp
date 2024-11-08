#include "window.h"
#include "ui_window.h"

#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>


Window::Window(QWidget *parent) : QWidget(parent)
{
    QGroupBox *echoGroup = new QGroupBox(tr("Echo"));

    QLabel *echoLabel = new QLabel(tr("Mode : "));
    QComboBox *echoComboBox = new QComboBox;
    echoComboBox->addItem(tr("Normal"));
    echoComboBox->addItem(tr("Password"));
    echoComboBox->addItem(tr("PAsswordEchoOnEdit"));
    echoComboBox->addItem(tr("No Echo"));

    echoLineEdit = new QLineEdit;
    echoLineEdit->setPlaceholderText("Entrer votre texte");

    QGridLayout *echoLayout = new QGridLayout;
    echoLayout->addWidget(echoLabel, 0, 0);
    echoLayout->addWidget(echoComboBox, 0, 1);
    echoLayout->addWidget(echoLineEdit, 1, 0, 1, 2);
    echoGroup->setLayout(echoLayout);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(echoGroup, 0, 0);
    setLayout(layout);

    setWindowTitle(tr("Line Edits"));
    connect(echoComboBox, QOverload<int>::of(&QComboBox::activated),this, &Window::echoChanged);
}
        void Window::echoChanged(int index)
         {
         switch (index) {
         case 0:
             echoLineEdit->setEchoMode(QLineEdit::Normal);
             break;
         case 1:
             echoLineEdit->setEchoMode(QLineEdit::Password);
             break;
         case 2:

                 echoLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
             break;
        case 3:
             echoLineEdit->setEchoMode(QLineEdit::NoEcho);
             break;
             }
         }



