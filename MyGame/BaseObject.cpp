#include"BaseObject.h"

BaseObject::BaseObject()//hàm khởi tạo
{
    rect_.x=0;
    rect_.y=0;
    rect_.w=0;
    rect_.h=0;
    p_object_=NULL;
}
BaseObject::~BaseObject()//hàm hủy
{
   Free();
}
//hàm load ảnh

bool BaseObject::LoadImg(std::string file_path, SDL_Renderer* screen) {
    Free();//xóa đối tượng trước đi đỡ bị rác vùng nhớ
    // Tạo biến texture mới
    SDL_Texture* new_texture = NULL;

    // Tải ảnh từ file vào surface
    SDL_Surface* load_surface = IMG_Load(file_path.c_str());
    if (load_surface != NULL) {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, CORLOR_KEY_R, CORLOR_KEY_G, CORLOR_KEY_B));//đặt màu nền
        new_texture = SDL_CreateTextureFromSurface(screen, load_surface);//tạo texture
       if (new_texture != NULL) {
         // Cập nhật kích thước của object từ surface
            rect_.w = load_surface->w;
            rect_.h = load_surface->h;

        }
        SDL_FreeSurface(load_surface);//giải phóng surface
    }
    // Gán texture mới vào đối tượng
    p_object_ = new_texture;

    // Kiểm tra xem texture có hợp lệ không
    return p_object_ != NULL;
}

//Hàm vẽ ảnh
void BaseObject::Render(SDL_Renderer *des ,const SDL_Rect *clip){//hàm vẽ ảnh
   SDL_Rect renderquad = {rect_.x,rect_.y,rect_.w,rect_.h};//tạo vị trí tọa độ khối chữ nhật
   SDL_RenderCopy(des,p_object_,clip,&renderquad);//truyền các thông số renderquad của p_object vào des
}

void BaseObject::Free(){
    if(p_object_ != NULL){
     SDL_DestroyTexture(p_object_);
     p_object_= NULL;
     rect_.w = 0;
     rect_.h = 0;
    }
}

