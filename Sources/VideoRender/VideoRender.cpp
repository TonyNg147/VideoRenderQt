#include "VideoRender.h"

template<typename T>
void safeDel(T& ptr){
    if (ptr){
        delete ptr;
        ptr = nullptr; 
    }
}

VideoRender::VideoRender(){
    m_media = new QMediaPlayer();
    m_videoSink = new QVideoSink();
    m_painter   = new QPainter();
    m_media->setSource(QUrl("qrc:/Resources/Video/Sample.mp4"));
    m_media->setVideoOutput(m_videoSink);
    QObject::connect(m_videoSink,&QVideoSink::videoFrameChanged,this,&VideoRender::onFrameChanged);
    m_media->play();
}
VideoRender::~VideoRender(){
    safeDel(m_painter);
    safeDel(m_videoSink);
    safeDel(m_media);
}
void VideoRender::onFrameChanged(const QVideoFrame& frame){
    // if the content of the frame changes, we will re-draw it
    if (m_frame = frame) return;
    m_frame = frame;
    paint(m_painter);
}

void VideoRender::paint(QPainter *painter){
    // Draw the frame with the width height given
    painter->drawImage(QRect(0,0,640,480),m_frame.toImage() );
    // Call update to re-render the screen
    update(QRect(0,0,640,480));
}