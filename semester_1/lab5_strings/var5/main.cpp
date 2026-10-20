#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> SplitWords(const std::string &s,
                                    const std::string &delimeters)
{

    std::vector<std::string> words;

    size_t beg_index = 0;
    size_t end_index = s.find_first_of(delimeters);

    while (beg_index != std::string::npos)
    {

        std::string word = s.substr(beg_index, end_index - beg_index);
        if (!word.empty())
        {
            words.push_back(word);
        }

        beg_index = s.find_first_not_of(delimeters, end_index);
        end_index = s.find_first_of(delimeters, beg_index);
    }

    return words;
}
int rim_to_norm(std::string s)
{
    int num = 0;
    std::vector<int> nums(s.size());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'I')
        {
            num++;
            nums[i] = 1;
        }
        else if (s[i] == 'V')
        {
            num += 5;
            nums[i] = 2;
        }
        else if (s[i] == 'X')
        {
            num += 10;
            nums[i] = 3;
        }
        else if (s[i] == 'L')
        {
            num += 50;
            nums[i] = 4;
        }
        else if (s[i] == 'C')
        {
            num += 100;
            nums[i] = 5;
        }
        else if (s[i] == 'D')
        {
            num += 500;
            nums[i] = 6;
        }
        else if (s[i] == 'M')
        {
            num += 1000;
            nums[i] = 7;
        }
    }
    for (int i = 0; i < (s.size() - 1); i++)
    {
        if (nums[i] - nums[i + 1] < 0)
        {
            if (nums[i] + nums[i + 1] == 12 || nums[i] + nums[i + 1] == 11)
            {
                num -= 200;
            }
            if (nums[i] + nums[i + 1] == 8 || nums[i] + nums[i + 1] == 7)
            {
                num -= 20;
            }
            if (nums[i] + nums[i + 1] == 4 || nums[i] + nums[i + 1] == 3)
            {
                num -= 2;
            }
        }
    }
    return num;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{

    std::string str;
    int sum = 0, min_el, min_ind = 0, max_el, max_ind = 0;
    std::cout << "Enter roman numerals" << std::endl;
    std::getline(std::cin, str);
    const std::string delimeters = " ";
    std::vector<std::string> vs = SplitWords(str, delimeters);
    int length = vs.size();
    std::vector<int> nums(length);
    for (int i = 0; i < length; i++)
    {
        nums[i] = rim_to_norm(vs[i]);
    }
    for (size_t i = 0; i < vs.size(); ++i)
    {
        if (nums[i] % 2 == 0)
        {
            sum += nums[i];
        }
        if (max_el < nums[i])
        {
            max_el = nums[i];
            max_ind = i;
        }
        if (min_el > nums[i])
        {
            min_el = nums[i];
            min_ind = i;
        }
    }
    swap(nums[min_ind], nums[max_ind]);
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Changed array: " << std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << nums[i] << " ";
    }
    return 0;
}