#ifndef SEARCH_H
#define SEARCH_H

#include "Episode.h"
#include <iostream>
#include <string>

class Search{
    friend std::ostream &operator<<(std::ostream &out, const Search &search);
    public:
        virtual bool matches (const Episode *episode) const = 0;
        virtual void print(std::ostream &out) const = 0;
};

class H_Search: public virtual Search
{
    private:
        std::string host;
    
    public:
        H_Search(const std::string &host);
        bool matches(const Episode *episode) const override;
        void print(std::ostream &out) const override;
};

class C_Search : public virtual Search
{
    private:
        std::string category;

    public:
        C_Search(const std::string &category);
        bool matches(const Episode *episode) const override;
        void print(std::ostream &out) const override;
};

class HorC_Search : public H_Search, public C_Search
{
    public:
        HorC_Search(const std::string &host, const std::string &category);
        bool matches(const Episode *episode) const override;
        void print(std::ostream &out) const override;
};

#endif