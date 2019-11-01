#include <chrono>
#include <logic/ComponentManager.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {
    using TickClock = std::chrono::steady_clock;
    using std::chrono::time_point;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;
    using namespace std::literals::chrono_literals;
    using namespace logic;

    sf::RenderWindow window(sf::VideoMode(800,600), "Hello, World!");

    auto components = ComponentManager();
    time_point<TickClock> lastTickTime = TickClock::now();

    while(window.isOpen()) {
        sf::Event event;
        //handle window events
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        //run a tick, if the necessary time has elapsed
        milliseconds elapsed = duration_cast<milliseconds>(TickClock::now() - lastTickTime);
        //hardcoded for now, should be configurable
        if(elapsed.count() >= 20) {
            lastTickTime = TickClock::now(); //be sure to record the time before running the tick, to let the execution time be part of the delay
            components.tick();
        }

        //draw
        window.clear(sf::Color::Black);
        components.draw(window);
        window.display();
    }

    return 0;
}