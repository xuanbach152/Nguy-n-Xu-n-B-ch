//xử lí thời gian
#ifndef IMP_TIMER_H_
#define IMP_TIMER_H_
class ImpTimer
{
public :
    ImpTimer();
    ~ImpTimer();

    void start();
    void stop();
    void pause();
    void resume();

    int get_ticks();//

    bool is_paused();//trả lại trạng thái
    bool is_started();
private :
    int start_tick_;//thời điểm bắt đầu chạy
    int pause_tick_;//thời điểm dừng

    bool is_paused_;//kiểm tra dừng
    bool is_started_;

};


#endif // IMP_TIMER_H_
