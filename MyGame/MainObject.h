#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_
#include"CommonFunction.h"
#include"BaseObject.h"
#include<vector>
#include"BulletObject.h"


#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10

#define PLAYER_SPEED 7
#define PLAYER_JUMP_VAL 19
class MainObject : public BaseObject
{
public :
    MainObject();
    ~MainObject();

    enum WalkType{
        WALK_NONE = 0,//trạng thái đầu
        WALK_RIGHT = 1,
        WALK_LEFT = 2,

    };

    bool LoadImg(std:: string path,SDL_Renderer* screen);//hàm tải ảnh
    void Show(SDL_Renderer* des);//hàm hiển thị
    void HandelInputAction(SDL_Event events,SDL_Renderer* screen);//hàm sự kiện nhấn
    void set_clips();//hàm gán các frame

    void DoPlayer(Map& map_data);//hàm thực hiện di chuyển nhân vật
    void CheckToMap(Map& map_data);//kiểm tra va chạm
    void SetMapXY(const int map_x,const int map_y){map_x_ = map_x;map_y_ = map_y;};//thiết lập vị trí của map
    void CenterEntityOnMap(Map& map_data);//tính toán lượng di chuyển màn hình
    void UpdateImagePlayer(SDL_Renderer* des);//cập nhật ảnh nhân vật
    void HandleBullet(SDL_Renderer* des);//hàm bắn đạn

    void IncreaseMoney();

    void set_bullet_list(std::vector<BulletObject*> bullet_list)
    {
        p_bullet_list_ = bullet_list;
    }
    std::vector<BulletObject*> get_bullet_list() const {return p_bullet_list_; }

private:
    std::vector<BulletObject*> p_bullet_list_;//danh sách đạn


    int money_count;

    float x_val_;//độ dịch chuyển
    float y_val_;

    float x_pos_;//vị trí thưc tế
    float y_pos_;

    int width_frame_;//kích thước frame nhân vật
    int height_frame_;

    SDL_Rect frame_clip_[8];
    Input input_type_;
    int frame_;//lưu chỉ số frame
    int status_;//lưu trạng thái di chuyển phải trái
    bool on_ground;

    int map_x_;//biến lưu vị trí của map
    int map_y_;

    int come_back_time_;//thời gian trở lại khi chết

};


#endif // MAIN_OBJECT_H_
