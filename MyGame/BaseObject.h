//Lớp cơ sở cho các lớp con kế thừa
#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_
#include"CommonFunction.h"
class BaseObject{
public :
    BaseObject();//khởi tạo

    ~BaseObject();//hủy

    void Render(SDL_Renderer *des ,const SDL_Rect *clip=NULL);

    virtual bool LoadImg(std::string file_path,SDL_Renderer *screen);//tải ảnh hàm ảo

    void SetRect(const int& x,const int& y){rect_.x=x;rect_.y=y;}

    SDL_Rect GetRect()const {return rect_;}//trả về vị trí

    SDL_Texture* GetObject(){return p_object_;};//trả về đối tượng

    void Free();

protected :
    SDL_Rect rect_;//khối chữ nhật
    SDL_Texture *p_object_;
};

#endif
//BASE_OBJECT_H_
