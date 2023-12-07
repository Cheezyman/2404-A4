#include "Podcast.h"
#include <iostream>

Podcast::Podcast(const std::string &title, const std::string &host)
    : title(title), host(host) {}

Podcast::~Podcast()
{
    for (auto &episode : episodes)
    {
        delete episode;
    }
}

bool Podcast::equals(const std::string &title) const
{
    return this->title == title;
}

Episode *Podcast::get(int index) const
{
    if (index < 0 || index >= episodes.size())
    {
        std::cerr << "Index out of bounds" << std::endl;
        return nullptr;
    }
    return episodes[index];
}

int Podcast::getSize() const
{
    return episodes.size();
}

void Podcast::print(std::ostream &out) const
{
    out << "Podcast Title: " << title << "\nHost: " << host << std::endl;
}

void Podcast::printWithEpisodes(std::ostream &out) const
{
    print(out);
    for (const auto &episode : episodes)
    {
        out << *episode << std::endl;
    }
}

void Podcast::add(Episode *episode)
{
    episodes.push_back(episode);
}

std::ostream &operator<<(std::ostream &out, const Podcast &podcast)
{
    podcast.print(out);
    return out;
}
