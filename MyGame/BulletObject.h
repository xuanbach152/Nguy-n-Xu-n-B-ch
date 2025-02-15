#ifndef BULLET_OBJECT_H_
#define BULLET_OBJECT_H_
#include "BaseObject.h"
#include"CommonFunction.h"


class BulletObject : public BaseObject
{
public:
    BulletObject();
    ~BulletObject();
    enum BulletDir{
        DIR_RIGHT = 20,
        DIR_LEFT = 21,
        DIR_UP = 22,
        DIR_UP_LEFT = 23,
        DIR_UP_RIGHT = 24,
        DIR_DOWN_LEFT = 25,
        DIR_DOWN_RIGHT = 26,
        DIR_DOWN = 27,
    };
    enum BulletType{
        SEPHERE_BULLET = 50,
        LAZER_BULLET = 51,
        ROCKET_BULLET = 52,
    };


    void set_x_val(const int &xVal){x_val_ = xVal;}
    void set_y_val(const int &yVal){y_val_ = yVal;}
    int get_x_val() const {return x_val_;}
    int get_y_val_() const {return y_val_;}

    void set_is_move(const bool& isMove){is_move_ = isMove;}
    bool get_is_move(){return is_move_;}

    unsigned int get_bullet_dir()const {return bullet_dir_;}
    void set_bullet_dir(const unsigned int& bulletDir){bullet_dir_ = bulletDir;}

    void set_bullet_type(const unsigned int& bulletType){bullet_type_ = bulletType;}
    unsigned int get_bullet_type()const {return bullet_type_;}

    void HandleMove(const int& x_border,const int& y_border);//hàm xử lí di chuyển đạn
    void LoadImgBullet(SDL_Renderer* des);//hàm load đạn
private:
    int x_val_;//lượng di chuyển
    int y_val_;
    bool is_move_;//kiểm tra di chuyển
    unsigned int bullet_dir_;//biến quản lí hướng viên đạn
    unsigned int bullet_type_;//biến quản lí loại đạn
};

#endif // BULLET_OBJECT_H_
