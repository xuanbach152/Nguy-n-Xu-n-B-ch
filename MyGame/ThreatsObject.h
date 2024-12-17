#ifndef THREATS_OBJECT_H_
#define THREATS_OBJECT_H_
#include"CommonFunction.h"
#include"BaseObject.h"


#define THREAT_FRAME_NUM 8
#define THREAT_GRAVITY_SPEED 0.8
#define THREAT_MAX_FALL_SPEED 10
class ThreatsObject: public BaseObject{
public :
    ThreatsObject();
    ~ThreatsObject();
    void set_x_val(const float& xVal){x_val_ = xVal;}//đặt độ dịch chuyển
    void set_y_val(const float& yVal){y_val_ = yVal;}

    void set_x_pos(const float& xp){x_pos_ = xp;}//đặt vị trí quái
    void set_y_pos(const float& yp){y_pos_ = yp;}
    float get_x_pos()const {return x_pos_;}//lấy vị trí hiện tại quái
    float get_y_pos()const {return y_pos_;}
    void SetMapXY(const int &mp_x,const int &mp_y){map_x_ = mp_x; map_y_ = mp_y;}//set map

    void set_clips();
    bool LoadImg(std:: string path,SDL_Renderer* screen);
    void Show(SDL_Renderer* des);

    int get_width_frame()const {return width_frame_;}//lấy kich thước
    int get_height_frame()const {return height_frame_;}

    void DoPlayer(Map& gmap);//xử lí di chuyển va chạm
    void CheckToMap(Map& gmap);//kiểm tra va chạm


private:

    int map_x_;//xác định giới hạn với bản đồ
    int map_y_;

    float x_val_;// độ dịch chuyển
    float y_val_;

    float x_pos_;//vị trí của quái
    float y_pos_;

    bool on_ground_;//xác định trên đất
    int come_back_time_;// thời gian trở lại
    SDL_Rect frame_clip_[THREAT_FRAME_NUM];//mảng lưu các frame

    int width_frame_;//kích thước 1 frame
    int height_frame_;

    int frame_;//biến lưu chỉ số frame

};

#endif // THREATS_OBJECT_H_
