#include"ImpTimer.h"
#include"CommonFunction.h"

ImpTimer :: ImpTimer(){
    start_tick_ = 0;
    pause_tick_ = 0;
    is_paused_ = false;
    is_started_ = false;

}
 ImpTimer::~ImpTimer(){

 }
 void ImpTimer::start(){
    is_started_ = true;
    is_paused_ = false;
    start_tick_ = SDL_GetTicks();//lấy thời gian đã trôi qua


 }

 void ImpTimer::stop(){
    is_paused_ = false;
    is_started_ = false;

 }
void ImpTimer::pause(){
    if(is_started_ == true && is_paused_ == false){
        is_paused_ = true;
        pause_tick_ = SDL_GetTicks() - start_tick_;//thời điểm dừng

    }
}
void ImpTimer::resume(){
    if(is_paused_ == true){
     is_paused_ = false;
     start_tick_ = SDL_GetTicks() - pause_tick_;// thời điêmt bắt đầu
     pause_tick_ = 0;
    }
}
int ImpTimer::get_ticks(){
    if(is_started_ == true){
        if(is_paused_ == true){
            return pause_tick_;//nếu dừng thì thời gian chạy qua là thời điểm dừng luôn
        }
        else {
            return SDL_GetTicks() - start_tick_;//thời điểm đã chạy qua
        }
    }
return 0;
}

bool ImpTimer::is_started(){
    return is_started_;
}
bool ImpTimer::is_paused(){
    return is_paused_;
}
