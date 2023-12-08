#ifndef PODCAST_H
#define PODCAST_H

#include <vector>
#include <string>
#include <iostream>
#include "Episode.h"
#include "Array.h"

class Podcast
{
private:
    Array<Episode *> episodes;
    std::string title;
    std::string host;

public:
    // Constructor
    Podcast(const std::string &title, const std::string &host);

    // Destructor
    ~Podcast();

    // Member functions
    bool equals(const std::string &title) const;
    Episode *get(int index) const;
    int getSize() const;
    void print(std::ostream &out) const;
    void printWithEpisodes(std::ostream &out) const;
    void add(Episode *episode);

    // Overloaded << operator
    friend std::ostream &operator<<(std::ostream &out, const Podcast &podcast);
};

#endif
