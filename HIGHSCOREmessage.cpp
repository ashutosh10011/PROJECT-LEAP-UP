#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode({800, 600}), "Highscore Popup");

    Font font;
    if (!font.openFromFile("roboto.ttf")) {
        throw ("Could not load font");
    } 

    Text text(font); // SFML 3.0 requires full constructor
    text.setFillColor(Color::Red);
    text.setString("HIGH SCORE");
    text.setStyle(Text::Bold);
    text.setPosition({100, 200});
   // SFML 3.0 requires move to be called with a Vector2f
    text.setCharacterSize(50); // SFML 3.0 requires character size to be set explicitly

    while (window.isOpen()) {
        while (optional event = window.pollEvent()) {
            if (event->is<Event::Closed>()) {
                window.close();
            }
        }
 text.move({0.1f,0.f}); 
        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}
