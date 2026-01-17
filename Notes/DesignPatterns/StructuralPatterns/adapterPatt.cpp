/*
    Structural design patterns are a category of design patterns in software engineering that deal
    with the composition of classes or objects to form larger structures and provide new functionalities.

    Adapter Pattern  ->  Allows the interface of an existing class to be used as another interface.
    It is often used to make existing classes work with others without modifying their source code.

    Allows two incompatible interfaces to work together
    Applications - wrapping windows/linux apis, 3rd party libraries, creating boundaries
*/

#include <iostream>
#include <string>

// Target interface (what your app expects)
class IMediaPlayer
{
public:
    virtual void playVideo(const std::string &file) = 0;
    virtual ~IMediaPlayer() = default;
};

// Existing or library provide
class ThirdPartyVideo
{
public:
    void render(const std::string &filename)
    {
        std::cout << "Rendering using 3rd party codec: " << filename << "\n";
    }
};

// Adaptor
class VideoAdapter : public IMediaPlayer
{
    ThirdPartyVideo &tpVideo;

public:
    VideoAdapter(ThirdPartyVideo &lib) : tpVideo(lib) {}

    void playVideo(const std::string &file) override
    {
        tpVideo.render(file); // translate call
    }
};

int main()
{
    ThirdPartyVideo thirdPartyLib;

    // Use adapter to match IMediaPlayer interface
    IMediaPlayer *player = new VideoAdapter(thirdPartyLib);

    player->playVideo("movie.mp4");

    delete player;
}
