#include "Search.h"

// H_Search implementation
H_Search::H_Search(const std::string &host) : host(host) {}

bool H_Search::matches(const Episode *episode) const
{
    return episode && episode->getHost() == host;
}

void H_Search::print(std::ostream &out) const
{
    out << "Search by Host: " << host;
}

// C_Search implementation
C_Search::C_Search(const std::string &category) : category(category) {}

bool C_Search::matches(const Episode *episode) const
{
    return episode && episode->getCategory() == category;
}

void C_Search::print(std::ostream &out) const
{
    out << "Search by Category: " << category;
}

// HorC_Search implementation
HorC_Search::HorC_Search(const std::string &host, const std::string &category)
    : H_Search(host), C_Search(category) {}

bool HorC_Search::matches(const Episode *episode) const
{
    return H_Search::matches(episode) || C_Search::matches(episode);
}

void HorC_Search::print(std::ostream &out) const
{
    out << "Search by Host or Category: ";
    H_Search::print(out); // This will print the host part
    out << ", ";
    C_Search::print(out); // This will print the category part
}

// Operator<< for Search
std::ostream &operator<<(std::ostream &out, const Search &search)
{
    search.print(out);
    return out;
}
