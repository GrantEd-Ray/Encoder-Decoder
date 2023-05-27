#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>

class Text
{
private:
    std::string text;
    std::vector<std::string> words;
    std::vector<int> biff_line;
    std::map<int, std::string> dictionary;
public:
    Text(const std::string& new_text)
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
        this->set_map();
    };

    ~Text()
    {

    };

    // Сделать перегрузку []
    std::string get_word(int i)
    {
        return words[i];
    }

    int size()
    {
        return words.size();
    }

    void set_map()
    {
        for (int i = 0; i < words.size(); i++)
        {
            dictionary[i] = words[i];
        }
    }

    void set_biff_line(int size)
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

    void Encode()
    {

    };
};


int main() {
    std::string t;
    std::getline(std::cin, t);

    Text a(t);
    std::cout << a.get_word(1);
    return 0;
}
