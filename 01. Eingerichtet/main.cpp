#include <SFML/Graphics.hpp>

using namespace sf; // statt std, hat zur Folge, dass bei String etc. std:: vor gesetzt werden muss

int main()
{
    // Windows-Fenster einrichten
    RenderWindow window(VideoMode(615, 411), "Bilder & Ebenen");

    // Form: Rechteck
    sf::RectangleShape rechteck(sf::Vector2f(120.f, 50.f)); // 120 x 50 großes Rechteck
    rechteck.setFillColor(Color::Red);
    rechteck.setPosition(10, 20);

    // Bild
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Bilder/hintergrund.jpg"))
        return EXIT_FAILURE;
    Sprite background(backgroundTexture);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // Die Reihenfolge ist wichtig!
        window.clear();          // 1. Bild wird gelöscht
        window.draw(background); // 2. Hintergrundbild wird geladen (1. Ebende)
        window.draw(rechteck);   // 3. Rechteck wird geladen        (2. Ebende)
        window.display();       // wird an den Bildschirm geschickt
    }

    return 0;
}