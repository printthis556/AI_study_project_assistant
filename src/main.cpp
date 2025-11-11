#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // Set application metadata
    QApplication::setApplicationName("AI Study Assistant");
    QApplication::setApplicationVersion("1.0.0");
    QApplication::setOrganizationName("StudyAssistant");
    
    MainWindow window;
    window.show();
    
    return app.exec();
}
