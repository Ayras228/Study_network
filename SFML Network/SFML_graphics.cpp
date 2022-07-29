#include<SFML/Graphics.hpp>

class Graphics
{
public:
	Graphics();
	~Graphics();
    void init_element();
    void init_sprites();
    void load_textures();
    void rect_textures();
    void set_positions();
    void draw();
    sf::RenderWindow *get_window();
private:
    int HEIGHT;
    int WIDTH;
    sf::RenderWindow window;
    sf::Texture texture_botton1, texture_botton2, texture_botton3,
        texture_background, texture_frame;




    sf::Sprite sprite_botton1, sprite_botton2,sprite_botton3,
        sprite_background, sprite_frame;
    
};

Graphics::Graphics()
{
    window.create(sf::VideoMode(1280, 720), "Messenger");
}

Graphics::~Graphics()
{
}

void Graphics::init_sprites()
{
    sprite_botton1.setTexture(texture_botton1);
    sprite_botton2.setTexture(texture_botton2);
    sprite_botton3.setTexture(texture_botton3);
    sprite_background.setTexture(texture_background);
    sprite_frame.setTexture(texture_frame);   
}
void Graphics::load_textures()
{
    texture_botton1.loadFromFile("D:\\universe\\C++\\Study_network\\SFML Network\\image\\start.png");
    
}
void Graphics::rect_textures()
{
    sprite_botton1.setTextureRect(sf::IntRect(250, 165, 350, 185));

}
void Graphics::set_positions()
{
    sprite_botton1.setPosition(1280 / 2, 720 / 2);
}
void Graphics::init_element()
{
    init_sprites();
    load_textures();
    rect_textures();
    set_positions();
}
void Graphics::draw()
{
    window.draw(sprite_botton1);
}
sf::RenderWindow *Graphics::get_window()
{
    return &window;
}

    
int main()
{
    Graphics graph;
    sf::RenderWindow *window = graph.get_window();
    window->clear(sf::Color::Black);
    graph.init_element();
    //graph.init_sprite();
    //graph.rects_texture();
    //graph.loads_texture();
    //graph.set_positions();
    while (window->isOpen())
    {
       
        sf::Event event;
        while (window->pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window->close();
        }

        
        graph.draw();

        window->display();
    }

    return 0;
}