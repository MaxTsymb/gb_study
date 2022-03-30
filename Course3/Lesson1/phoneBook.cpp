#include "PhoneBook.h"


PhoneBook::PhoneBook(std::ifstream& ifs)
{
    int i = 0;
    const int strMaxSize = 255;
    char buf[strMaxSize];
    std::vector<std::string> vs;
    Person p; PhoneNumber pn;
    int entryNum = 0;
    const int NUM_OF_ENTRIES = 7;

    if (ifs)
    {
        while (!ifs.eof())
        {
            ifs.getline(buf, strMaxSize);
            std::string str{ buf };
            int j = 0;
            entryNum = 0;
            pn.extenNum = std::nullopt;
            for (i = 0; i != str.size(); ++i)
            {
                j = str.find_first_of(',', i);
                if (j == str.npos)
                    break;

                std::string s = str.substr(i, j - i);
                switch (entryNum)
                {
                case 0:
                    p.last_name = s;
                    break;
                case 1:
                    p.first_name = s;
                    break;
                case 2:
                    p.middle_name = s;
                    break;
                case 3:
                    pn.countryNum = stoi(s);
                    break;
                case 4:
                    pn.cityNum = stoi(s);
                    break;
                case 5:
                    pn.phoneNum = s;
                    break;
                case 6:
                    pn.extenNum = stoi(s);
                    break;

                default:
                    break;
                }
                ++entryNum;
                i = j;
            }
            if (i > (NUM_OF_ENTRIES - 1) - 1)
            {
                phoneBook.push_back(std::pair(p, pn));
            }
            else
            {
                std::cout << "Error reading data" << std::endl;
            }
        }
    }
}


void PhoneBook::SortByName()
{
    sort(phoneBook.begin(), phoneBook.end(), [](const std::pair<const Person&, const PhoneNumber&>& p1,
        const std::pair<const Person&, const PhoneNumber&>& p2)->bool
        { return p1.first < p2.first; });
}
void PhoneBook::SortByPhone()
{
    sort(phoneBook.begin(), phoneBook.end(), [](const std::pair<const Person&, const PhoneNumber&>& p1,
        const std::pair<const Person&, const PhoneNumber&>& p2)->bool
        { return p1.second < p2.second; });

}
std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string& lastName)
{
    int numEntries = 0;
    PhoneNumber pn;
    std::string foundStr;

    for_each(phoneBook.begin(), phoneBook.end(), [&](const auto& entry)
        {
            if (entry.first.last_name == lastName)
            {
                ++numEntries;
                pn = entry.second;
            }
        });

    if (numEntries == 0)
    {
        foundStr = "not found";
    }
    else if (numEntries == 1)
    {
        foundStr = "";
    }
    else if (numEntries > 1)
    {
        foundStr = "found more than 1";
    }

    return make_tuple(foundStr, pn);
}

void PhoneBook::ChangePhoneNumber(const Person& person, const PhoneNumber& number)
{
    auto result = find_if(phoneBook.begin(), phoneBook.end(), [&](const auto& entry) { return entry.first == person; });
    if (result != phoneBook.end())
    {
        (*result).second = number;
    }
}


std::ostream& operator << (std::ostream& out, const PhoneBook& book)
{
    for (auto p : book.phoneBook)
    {
        out << p.first << "\t" << p.second << std::endl;
    }


    return out;
}