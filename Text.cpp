#include <iostream>
#include <vector>
#include "Text.h"

mt::Text::Text(const std::string &new_text)
{
    text = new_text;
    int w_start = 0;
    int w_size = 0;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ')
        {
            words.push_back(text.substr(w_start, w_size));
            w_start = i+1;
            w_size = 0;
        }
        else
        {
            w_size += 1;
        }
    }
    words.push_back(text.substr(w_start, w_size));
    this->set_biff_line(words.size());
    code_line = biff_line;
    this->set_map();
}

mt::Text::~Text() {}

std::string mt::Text::get_word(int i)
{
    return words[i];
}

int mt::Text::size()
{
    return words.size();
}

void mt::Text::set_map()
{
    for (int i = 0; i < words.size(); i++)
    {
        dictionary[biff_line[i]] = words[i];
    }
}

void mt::Text::set_biff_line(int size)
{
    std::vector<int> temp;
    int a = 1;
    int b = 1;
    temp.push_back(b);
    for (int i = 1; i < size; i++)
    {
        std::swap(a, b);
        b += a;
        temp.push_back(b);
    }
    biff_line = temp;
}

std::vector<int> mt::Text::get_code_line()
{
    std::vector<int> temp;
    int a;
    while (std::cin.peek() != '\n')
    {
        std::cin >> a;
        temp.push_back(a);
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    return temp;
}

void mt::Text::Encode()
{
    std::vector<int> temp = this->get_code_line();

    //std::cout << temp.size() << " " << code_line.size();

    if (temp.size() == code_line.size())
    {
        code_line = temp;
        std::cout << "Text is encoded!" << std::endl;
    }
    else
    {
        std::cout << "Wrong keyword length. Try again" << std::endl;
    }
}

void mt::Text::Decode()
{
    std::vector<int> check = this->get_code_line();

    if(check == code_line)
    {
        code_line = biff_line;
        std::cout << "Text is decoded!" << std::endl;
    }
    else
    {
        std::cout << "Wrong keyword" << std::endl;
    }
}

void mt::Text::show()
{
    std::string temp;
    for (int i = 0; i < code_line.size(); i++)
    {
        int a = code_line[i];
        temp += (dictionary[a]);
        if (i != code_line.size() - 1)
            temp += std::string(" ");
    }
    std::cout << temp << std::endl;
}