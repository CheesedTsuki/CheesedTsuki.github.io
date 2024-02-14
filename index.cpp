#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>

class ValentineWidget : public QWidget {
public:
    ValentineWidget(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Will You Be My Valentine?");
        setFixedSize(600, 600);

        QVBoxLayout *layout = new QVBoxLayout(this);

        QLabel *titleLabel = new QLabel("Will You Be My Valentine?");
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet("color: #e91e63; font-size: 24px;");
        layout->addWidget(titleLabel);

        QLabel *dearLabel = new QLabel("Dear Nada,");
        dearLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(dearLabel);

        QLabel *poemLabel = new QLabel("Roses are red, violets are blue, my heart is full, and it's all for you!");
        poemLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(poemLabel);

        QLabel *imageLabel = new QLabel;
        imageLabel->setPixmap(QPixmap("nada2.jpeg").scaled(400, 400, Qt::KeepAspectRatio));
        layout->addWidget(imageLabel);

        QLabel *askLabel = new QLabel("Would you make my day extra special by being my Valentine?");
        askLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(askLabel);

        QWidget *buttonWidget = new QWidget;
        QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);

        QPushButton *yesButton = new QPushButton("Yes, I'd love to!");
        yesButton->setStyleSheet("background-color: #e91e63; color: #fff; padding: 10px 20px; font-size: 16px; border: none; border-radius: 5px; cursor: pointer;");
        connect(yesButton, &QPushButton::clicked, this, &ValentineWidget::displayMessage);
        buttonLayout->addWidget(yesButton);

        QPushButton *noButton = new QPushButton("No, sorry.");
        noButton->setStyleSheet("background-color: #fff; color: #e91e63; padding: 10px 20px; font-size: 16px; border: 2px solid #e91e63; border-radius: 5px; cursor: pointer;");
        connect(noButton, &QPushButton::clicked, this, &ValentineWidget::shrinkButton);
        buttonLayout->addWidget(noButton);

        layout->addWidget(buttonWidget);

        setLayout(layout);
    }

private slots:
    void displayMessage() {
        QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(this->layout());
        if (layout) {
            layout->removeWidget(layout->itemAt(5)->widget()); // Remove button widget
            layout->itemAt(0)->widget()->hide(); // Hide title label
            layout->itemAt(1)->widget()->hide(); // Hide dear label
            layout->itemAt(2)->widget()->hide(); // Hide poem label
            layout->itemAt(3)->widget()->hide(); // Hide image label
            layout->itemAt(4)->widget()->hide(); // Hide ask label

            QLabel *messageLabel = new QLabel;
            messageLabel->setText("Yay! 🌟\n\nDear Nada,\n\nYour sweet 'Yes' has made my day brighter! I'm looking forward to celebrating Valentine's Day with you. 😊");
            messageLabel->setAlignment(Qt::AlignCenter);
            layout->addWidget(messageLabel);
        }
    }

    void shrinkButton() {
        QWidget *buttonWidget = qobject_cast<QWidget *>(sender()->parent());
        if (buttonWidget) {
            QPushButton *noButton = buttonWidget->findChild<QPushButton *>("noButton");
            if (noButton) {
                QFont font = noButton->font();
                font.setPointSize(font.pointSize() - 1); // Decrease font size
                noButton->setFont(font);
            }
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ValentineWidget widget;
    widget.show();
    return app.exec();
}

