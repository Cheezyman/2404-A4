#ifndef SEARCH_H
#define SEARCH_H

#include "Episode.h"
#include <iostream>
#include <string>

// Abstract base class
class Search
{
public:
    virtual ~Search() {}
    virtual bool matches(const Episode *episode) const = 0;
    virtual void print(std::ostream &out) const = 0;

    friend std::ostream &operator<<(std::ostream &out, const Search &search);
};

// Search by host
class H_Search : virtual public Search
{
private:
    std::string host;

public:
    H_Search(const std::string &host);
    virtual bool matches(const Episode *episode) const override;
    virtual void print(std::ostream &out) const override;
};

// Search by category
class C_Search : virtual public Search
{
private:
    std::string category;

public:
    C_Search(const std::string &category);
    virtual bool matches(const Episode *episode) const override;
    virtual void print(std::ostream &out) const override;
};

// Search by host or category
class HorC_Search : public H_Search, public C_Search
{
public:
    HorC_Search(const std::string &host, const std::string &category);
    virtual bool matches(const Episode *episode) const override;
    virtual void print(std::ostream &out) const override;
};

#endif // SEARCH_H
