#ifndef VIDEO_SINK_H
#define VIDEO_SINK_H
#include <QQuickPaintedItem>
#include <QtMultimedia>
#include <QVideoSink>
class VideoRender: public QQuickPaintedItem{
    Q_OBJECT
    public:
        VideoRender();
        ~VideoRender();
    protected:
        /**
         * @brief Each time the frame changes, call this function will allow the engine 
         *        redraw the render
         * 
         * @param painter 
         */
        void paint(QPainter *painter) override;
    private:    
        /**
         * @brief Receive the data when the frame changes
         * 
         * @param frame 
         */
        void onFrameChanged(const QVideoFrame& frame);
    private:
        QMediaPlayer* m_media = nullptr;
        QVideoSink*   m_videoSink = nullptr;
        QPainter*     m_painter = nullptr;
        QVideoFrame   m_frame;
};
#endif