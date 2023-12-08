#include "Podcast.h"
#include <iostream>
#include "Array.h"

Podcast::Podcast(const std::string &title, const std::string &host)
    : title(title), host(host) {}

Podcast::~Podcast()
{
   for(int i = 0; i < episodes.getSize(); i++)
    {
         delete episodes[i];
    }
}

bool Podcast::equals(const std::string &title) const
{
    return this->title == title;
}

Episode *Podcast::get(int index) const
{
    if (index < 0 || index >= episodes.getSize())
    {
        std::cerr << "Index out of bounds" << std::endl;
        return nullptr;
    }
    return episodes[index];
}

int Podcast::getSize() const
{
    return episodes.getSize();
}

void Podcast::print(std::ostream &out) const
{
    out << "Podcast Title: " << title << "\nHost: " << host << std::endl;
}

void Podcast::printWithEpisodes(std::ostream &out) const
{
    print(out);
    for(int i = 0; i < episodes.getSize(); i++)
    {
        out << episodes[i]->getEpisodeTitle() << std::endl;
    }
}

void Podcast::add(Episode *episode)
{
    if(episodes.isFull())
    {
        std::cerr << "Podcast is full" << std::endl;
        return;
    }
    episodes.add(episode);
}

std::ostream &operator<<(std::ostream &out, const Podcast &podcast)
{
    podcast.print(out);
    return out;
}
