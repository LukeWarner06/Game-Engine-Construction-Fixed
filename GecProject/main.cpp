/*
    GecProject - For GEC students to use as a start point for their projects.
    Already has SFML linked and ImGui set up.
*/

#include "ExternalHeaders.h"
#include "RedirectCout.h"
#include "AnimationClass.h"
#include "TextureManager.h"
#include "RectangleCollision.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>

void DefineGUI();

int main()
{
    // Redirect cout to the Visual Studio output pane
    outbuf ob;
    std::streambuf* sb{ std::cout.rdbuf(&ob) };

    // Redirect cerr
    outbuferr oberr;
    std::streambuf* sberr{ std::cerr.rdbuf(&oberr) };

    // Turn on memory leak checking
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "GEC Start Project");

    // Create a simple shape to draw
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Identifies the file paths for the four dinosaur animation sprite sheets.
    std::string dinosaurIdleFileLocation = "Data/Textures/Dinodaur/idle_combined.png";
    std::string dinosaurWalkFileLocation = "Data/Textures/Dinodaur/walk_combined.png";
    std::string dinosaurRunFileLocation = "Data/Textures/Dinodaur/run_combined.png";
    std::string dinosaurJumpFileLocation = "Data/Textures/Dinodaur/jump_combined.png";
    std::string dinosaurDeadFileLocation = "Data/Textures/Dinodaur/dead_combined.png";
    
    // Clock required by ImGui
    sf::Clock uiDeltaClock;

    // Sets the dinosaurs origin point to near the centre of its body.
    sf::Vector2f dinosaurOrigin = { 220, 420 };

    // Stores the loaded textures for use, by the animation system.
    TextureManager textureManager;

    // Load Textures
    // The application will stop if a required texture cannot be loaded instead of continuing with missing resources.

    if (!textureManager.LoadTexture("dinosaur_idle", dinosaurIdleFileLocation))
    {
        return 1;
    }

    if (!textureManager.LoadTexture("dinosaur_walk", dinosaurWalkFileLocation))
    {
        return 1;
    }

    if (!textureManager.LoadTexture("dinosaur_run", dinosaurRunFileLocation))
    {
        return 1;
    }

    if (!textureManager.LoadTexture("dinosaur_jump", dinosaurJumpFileLocation))
    {
        return 1;
    }

    if (!textureManager.LoadTexture("dinosaur_dead", dinosaurDeadFileLocation))
    {
        return 1;
    }

    //Get Textures
    // The pointers to the stored textures are retrieved without needleslly creating copies.

    sf::Texture* dinosaurIdleTexture = textureManager.GetTexture("dinosaur_idle");

    sf::Texture* dinosaurWalkTexture = textureManager.GetTexture("dinosaur_walk");

    sf::Texture* dinosaurRunTexture = textureManager.GetTexture("dinosaur_run");

    sf::Texture* dinosaurJumpTexture = textureManager.GetTexture("dinosaur_jump");

    sf::Texture* dinosaurDeadTexture = textureManager.GetTexture("dinosaur_dead");

    // Set up ImGui (the UI library) after the textures are loaded and gotten so that if any fail ImGUI is not initalised beforehand.
    if (!ImGui::SFML::Init(window))
        return -1;

    //Animation Classes
    // Each object represents a different dinosaur animation sprite sheet with its own dimensions.

    AnimationClass dinosaurIdle(dinosaurIdleTexture, 682, 474, SpriteLayout::Vertical);
    dinosaurIdle.SetOrigin(dinosaurOrigin);

    AnimationClass dinosaurWalk(dinosaurWalkTexture, 682, 474, SpriteLayout::Vertical);
    dinosaurWalk.SetOrigin(dinosaurOrigin);

    AnimationClass dinosaurRun(dinosaurRunTexture, 682, 474, SpriteLayout::Vertical);
    dinosaurRun.SetOrigin(dinosaurOrigin);

    AnimationClass dinosaurJump(dinosaurJumpTexture, 682, 474, SpriteLayout::Vertical);
    dinosaurJump.SetOrigin(dinosaurOrigin);

    AnimationClass dinosaurDead(dinosaurDeadTexture, 682, 474, SpriteLayout::Vertical);
    dinosaurDead.SetOrigin(dinosaurOrigin);

    //Collection of Animations
    // The map groups animation pointers, by name, which allows the active animation to be selected rather easily.
    std::map<std::string, AnimationClass*> dinosaurAnimationCollection;

    dinosaurAnimationCollection["idle"] = &dinosaurIdle;
    dinosaurAnimationCollection["walk"] = &dinosaurWalk;
    dinosaurAnimationCollection["run"] = &dinosaurRun;
    dinosaurAnimationCollection["jump"] = &dinosaurJump;
    dinosaurAnimationCollection["dead"] = &dinosaurDead;

    // A pointer to identify which animation is currently being updated and rendered on the window.
    AnimationClass* currentAnimation = dinosaurAnimationCollection["idle"];

    // Variable declaring the character's position.

    sf::Vector2f dinosaurPosition = { 400, 450 };
    float dinosaurMovementSpeed = 150;

    sf::Vector2f dinosaurBodyOffset{ 130, 40 };

    RectangleCollision dinosaurCollision({ dinosaurPosition - dinosaurOrigin + dinosaurBodyOffset }, { 240, 380 });

    sf::RectangleShape testRect({ 60, 100 });
    testRect.setPosition({ 650, 300 });

    RectangleCollision testRectCollision({ 650, 300 }, { 60, 100 });

    sf::RectangleShape dinosaurCollisionOutline({ 240, 380 });
    dinosaurCollisionOutline.setFillColor(sf::Color::Transparent);
    dinosaurCollisionOutline.setOutlineColor(sf::Color::Yellow);
    dinosaurCollisionOutline.setOutlineThickness({ 1 });
  
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Feed ImGui
            ImGui::SFML::ProcessEvent(window, event.value());

            // Pressing these keys switches between idle, walk, run and dead animations.
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::Num1)
                {
                    currentAnimation->ResetFrameCount();
                    currentAnimation = dinosaurAnimationCollection["idle"];
                }
                else if (keyPressed->code == sf::Keyboard::Key::Num2)
                {
                    currentAnimation->ResetFrameCount();
                    currentAnimation = dinosaurAnimationCollection["walk"];
                }
                else if (keyPressed->code == sf::Keyboard::Key::Num3)
                {
                    currentAnimation->ResetFrameCount();
                    currentAnimation = dinosaurAnimationCollection["run"];
                }
                else if (keyPressed->code == sf::Keyboard::Key::Num4)
                {
                    currentAnimation->ResetFrameCount();
                    currentAnimation = dinosaurAnimationCollection["jump"];
                }
                else if (keyPressed->code == sf::Keyboard::Key::Num5)
                {
                    currentAnimation->ResetFrameCount();
                    currentAnimation = dinosaurAnimationCollection["dead"];
                }
            }

            // User clicked on window close X
            if (event->is<sf::Event::Closed>())
                window.close();                          
        }

        sf::Vector2f direction({ 0, 0 });

        // Elapsed time 
        sf::Time dt = uiDeltaClock.restart();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            direction.x++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            direction.x--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            direction.y--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            direction.y++;
        }

        AnimationClass* desiredAnimation = dinosaurAnimationCollection["idle"];

        if (direction.length() > 0)
        {
            direction = direction.normalized();
            dinosaurPosition += direction * dinosaurMovementSpeed * dt.asSeconds();

            desiredAnimation = dinosaurAnimationCollection["run"];
        }

        if (currentAnimation == dinosaurAnimationCollection["idle"] || currentAnimation == dinosaurAnimationCollection["run"])
        {
            if (currentAnimation != desiredAnimation)
            {
                currentAnimation = desiredAnimation;
                currentAnimation->ResetFrameCount();
            }
        }

        dinosaurCollision.SetCollisionPosition(dinosaurPosition - dinosaurOrigin + dinosaurBodyOffset);
        dinosaurCollisionOutline.setPosition(dinosaurPosition - dinosaurOrigin + dinosaurBodyOffset);
        if (dinosaurCollision.Intersect(testRectCollision))
        {
            testRect.setFillColor(sf::Color::Red);
            dinosaurCollisionOutline.setOutlineColor(sf::Color::Green);
        }

        else
        {
            testRect.setFillColor(sf::Color::Green);
            dinosaurCollisionOutline.setOutlineColor(sf::Color::Red);
        }

        // ImGui must be updated each frame
        ImGui::SFML::Update(window,  dt);

        // The elapsed time from dt is passed to the animation so that its speed is based on time rather than the number of rendered frames.
        currentAnimation->update(dt); 

        // The UI gets defined each time
        DefineGUI();

        // Clear the window
        window.clear();

        currentAnimation->SetPosition(dinosaurPosition);
       
        // Only the selected animation is rendered on the window each frame.
        window.draw(testRect);
       currentAnimation->draw(&window);
       window.draw(dinosaurCollisionOutline);

        // UI needs drawing last
        ImGui::SFML::Render(window);

        window.display();
    }

    std::cout << "Finished!" << std::endl;

    // Shuts down when the main game loop finishes.
	ImGui::SFML::Shutdown();

    return 0;
}

/* 
    Use IMGUI for a simple on screen GUI
    See: https://github.com/ocornut/imgui/wiki/
*/
void DefineGUI()
{
    // Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    ImGui::Begin("GEC");				// Create a window called "3GP" and append into it.

    ImGui::Text("Some Text.");	      	// Display some text (you can use a format strings too)	

    ImGui::Button("Button");			// Buttons return true when clicked (most widgets return true when edited/activated)
    
 //   ImGui::Checkbox("Wireframe", &m_wireframe);	// A checkbox linked to a member variable

  //  ImGui::Checkbox("Cull Face", &m_cullFace);

   // ImGui::SliderFloat("Speed", &gAnimationSpeed, 0.01f, 0.3f);	// Slider from 0.0 to 1.0

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    ImGui::End();
}