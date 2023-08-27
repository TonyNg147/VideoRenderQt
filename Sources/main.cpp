#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include "VideoRender/VideoRender.h"
int main(int argc, char** argv){
    QGuiApplication app(argc,argv);
    qmlRegisterType<VideoRender>("VideoRender",1,0,"VideoRender");
    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/Resources/Qml/main.qml"));
    return app.exec();
};