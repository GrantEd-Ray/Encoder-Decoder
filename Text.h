#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace mt
{
    class Text
    {
    private:
        std::string text;
        std::vector<std::string> words;
        std::vector<int> biff_line;
        std::vector<int> code_line;
        std::map<int, std::string> dictionary;
    public:
        Text(const std::string& new_text);

        ~Text();

        std::string get_word(int i);

        int size();

        void set_map();

        void set_biff_line(int size);

        std::vector<int> get_code_line();

        void Encode();

        void Decode();

        void show();
    };
}